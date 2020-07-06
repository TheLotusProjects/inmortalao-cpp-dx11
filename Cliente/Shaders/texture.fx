/////////////
// GLOBALS //
/////////////
Texture2D shaderTexture;
SamplerState SampleType;

cbuffer MatrixBuffer
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};

//////////////
// TYPEDEFS //
//////////////
struct VertexInputType
{
    float4 position : POSITION;
    float2 tex : TEXCOORD0;
	float4 color : COLOR;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
	float4 color : COLOR;
};

cbuffer TransparentBuffer
{
	float blendAmount;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType VSMain(VertexInputType input)
{
    PixelInputType output;

    // Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;

    // Calculate the position of the vertex against the world, view, and projection matrices.
    output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);

    // Store the texture coordinates for the pixel shader.
    output.tex = input.tex;
    
	// Store the particle color for the pixel shader. 
	output.color = input.color;

    return output;
}

////////////////////////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////////////////////////
float4 PSMain(PixelInputType input) : SV_TARGET
{
    float4 textureColor = float4(1, 1, 1, 1);
	float4 finalColor;

    // Sample the pixel color from the texture using the sampler at this texture coordinate location.
    textureColor = shaderTexture.Sample(SampleType, input.tex);
	
	
	if (textureColor.r == 0.0 && textureColor.b == 0.0 && textureColor.g == 0.0)
	{
		discard;
	}


	//clip((textureColor.r == 0.0f) && (textureColor.g == 0.0f) && (textureColor.b == 0.0f));
	//return textureColor;

	
	// Combine the texture color and the particle color to get the final color result.
	
	
	finalColor = textureColor * input.color ; //*0.5;
	
	

	finalColor.a = finalColor.a*blendAmount;

    return finalColor;
}