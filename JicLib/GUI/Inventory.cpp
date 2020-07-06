#include "Inventory.h"


Inventory::Inventory(Directx11* directx11Param, Recursos* recursosParam)
{
	directx11 = directx11Param;
	recursos = recursosParam;
}


void Inventory::dibujar(std::string mensaje, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix)
{

	/*for (int i= 0;i<4;i++) {
		for (int j = 0;j < 5;j++) {
			slot->SetPosition(700 + i * 47, 70+j*47);
			slot->girar(0.0, worldMatrix);
			slot->dibujar(directx11->GetDeviceContext(), viewMatrix, projMatrix);
		}
	}*/


	bool isOpen = false;
	
	//Create ImGui Test Window
	ImGui::Begin("Inventory", &isOpen, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove
		| ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar );
	ImGui::SetWindowPos(ImVec2(777, 223), ImGuiCond_Always);

	ImGui::Separator();
	
	if (ImGui::Button("Inventory", ImVec2(70, 30))) {}

	ImGui::SameLine();

	if (ImGui::Button("Spells",ImVec2(50,30))) {}

	ImGui::SameLine();

	if (ImGui::Button("Options", ImVec2(80, 30))) {}


	ImGuiIO& io = ImGui::GetIO();
	
	/*
	ImTextureID my_tex_id = io.Fonts->TexID;
	float my_tex_w = (float)io.Fonts->TexWidth;
	float my_tex_h = (float)io.Fonts->TexHeight;
	*/

	//ImGui::Text("asd", my_tex_w, my_tex_h);
	//ImVec2 pos = ImGui::GetCursorScreenPos();
	
//	ImGui::Image(my_tex_id, ImVec2(my_tex_w, my_tex_h), ImVec2(0, 0), ImVec2(1, 1), ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec4(1.0f, 1.0f, 1.0f, 0.5f));
	
	/*
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		float region_sz = 32.0f;
		float region_x = io.MousePos.x - pos.x - region_sz * 0.5f; if (region_x < 0.0f) region_x = 0.0f; else if (region_x > my_tex_w - region_sz) region_x = my_tex_w - region_sz;
		float region_y = io.MousePos.y - pos.y - region_sz * 0.5f; if (region_y < 0.0f) region_y = 0.0f; else if (region_y > my_tex_h - region_sz) region_y = my_tex_h - region_sz;
		float zoom = 4.0f;
		ImGui::Text("Min: (%.2f, %.2f)", region_x, region_y);
		ImGui::Text("Max: (%.2f, %.2f)", region_x + region_sz, region_y + region_sz);
		ImVec2 uv0 = ImVec2((region_x) / my_tex_w, (region_y) / my_tex_h);
		ImVec2 uv1 = ImVec2((region_x + region_sz) / my_tex_w, (region_y + region_sz) / my_tex_h);
		ImGui::Image(my_tex_id, ImVec2(region_sz * zoom, region_sz * zoom), uv0, uv1, ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec4(1.0f, 1.0f, 1.0f, 0.5f));
		ImGui::EndTooltip();
	}
	*/

	
	ImGui::SetNextWindowPos(ImVec2(820, 320), ImGuiCond_Always);

	ImGui::BeginChildFrame(ImGui::GetID("cfginfos"), ImVec2(150, ImGui::GetTextLineHeightWithSpacing() * 9), ImGuiWindowFlags_NoMove);

	ImGui::SetWindowPos(ImVec2(830, 340), ImGuiCond_Always);

	//static const char* names[9] = { "Bobby", "Beatrice", "Betty", "Brianna", "Barry", "Bernard", "Bibi", "Blaine", "Bryn" };
	static const int* names[9] = {new int(0),new int(1),new int(2),new int(3),new int(4),new int(5),new int(6),new int(7),new int(8) };
	for (int n = 0; n < IM_ARRAYSIZE(names); n++)
	{

		ImGui::PushID(n);
		if ((n % 3) != 0)
			ImGui::SameLine();
		
		ID3D11ShaderResourceView* texture = slots[*names[n]]->getTextura()->getTextura();
		ImGui::Image((void*)texture, ImVec2(33, 33), ImVec2(0, 0), ImVec2(0.973f,0.973f), ImVec4(0.5f, 0.1f, 0.1f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 1.0f));

		if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_SourceAllowNullID))
		{
			ImGui::SetDragDropPayload("DND_DEMO_CELL", &n, sizeof(int));        // Set payload to carry the index of our item (could be anything)
			
			ID3D11ShaderResourceView* texture = slots[*names[n]]->getTextura()->getTextura();
			ImGui::Image((void*)texture, ImVec2(40, 40), ImVec2(0, 0), ImVec2(1, 1), ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f));

			ImGui::EndDragDropSource();
		}

		if (ImGui::BeginDragDropTarget())
		{
			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("DND_DEMO_CELL"))
			{
				IM_ASSERT(payload->DataSize == sizeof(int));
				int payload_n = *(const int*)payload->Data;
				const int* tmp = names[n];
				names[n] = names[payload_n];
				names[payload_n] = tmp;
			}
			ImGui::EndDragDropTarget();
		}
		ImGui::PopID();
	}
	ImGui::Unindent();
	ImGui::EndChildFrame();

	/*
	ImGui::TextWrapped("And now some textured buttons..");
	static int pressed_count = 0;




	static const int names[3] = { 0, 1, 2 };
	int move_from = -1, move_to = -1;

	
	for (int n = 0; n < IM_ARRAYSIZE(names); n++)
	{
		ImGui::PushID(n);
		if ((n % 3) != 0)
			ImGui::SameLine();

		ID3D11ShaderResourceView* texture = slots[names[n]]->getTextura()->getTextura();
		ImGui::Image((void*)texture, ImVec2(30, 30), ImVec2(0, 0), ImVec2(1, 1), ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec4(1.0f, 1.0f, 1.0f, 0.5f));

		//ImGui::Selectable(names[n]);

		ImGuiDragDropFlags src_flags = 0;
		src_flags |= ImGuiDragDropFlags_SourceNoDisableHover;     // Keep the source displayed as hovered
		src_flags |= ImGuiDragDropFlags_SourceNoHoldToOpenOthers; // Because our dragging is local, we disable the feature of opening foreign treenodes/tabs while dragging
															  //src_flags |= ImGuiDragDropFlags_SourceNoPreviewTooltip; // Hide the tooltip
		if (ImGui::BeginDragDropSource(src_flags))
		{
			if (!(src_flags & ImGuiDragDropFlags_SourceNoPreviewTooltip))
				ImGui::Text("Moving \"%s\"", names[n]);
			ImGui::SetDragDropPayload("DND_DEMO_NAME", &n, sizeof(int));
			ImGui::EndDragDropSource();
		}
		
		if (ImGui::BeginDragDropTarget())
		{
			ImGuiDragDropFlags target_flags = 0;
			target_flags |= ImGuiDragDropFlags_AcceptBeforeDelivery;    // Don't wait until the delivery (release mouse button on a target) to do something
			target_flags |= ImGuiDragDropFlags_AcceptNoDrawDefaultRect; // Don't display the yellow rectangle
			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("DND_DEMO_NAME", target_flags))
			{
				move_from = *(const int*)payload->Data;
				move_to = n;
			}
			ImGui::EndDragDropTarget();
		}

		ImGui::PopID();
	}
	*/

	/*
	if (move_from != -1 && move_to != -1)
	{
		// Reorder items
		int copy_dst = (move_from < move_to) ? move_from : move_to + 1;
		int copy_src = (move_from < move_to) ? move_from + 1 : move_to;
		int copy_count = (move_from < move_to) ? move_to - move_from : move_from - move_to;
		const char* tmp = names[move_from];
		//printf("[%05d] move %d->%d (copy %d..%d to %d..%d)\n", ImGui::GetFrameCount(), move_from, move_to, copy_src, copy_src + copy_count - 1, copy_dst, copy_dst + copy_count - 1);
		memmove(&names[copy_dst], &names[copy_src], (size_t)copy_count * sizeof(const char*));
		names[move_to] = tmp;
		ImGui::SetDragDropPayload("DND_DEMO_NAME", &move_to, sizeof(int)); // Update payload immediately so on the next frame if we move the mouse to an earlier item our index payload will be correct. This is odd and showcase how the DnD api isn't best presented in this example.
	}*/

	/*
	for (int i = 0; i < 8; i++)
	{
		ImGui::PushID(i);
		int frame_padding = -1 + i;     // -1 = uses default padding
		if (ImGui::ImageButton(my_tex_id, ImVec2(32, 32), ImVec2(0, 0), ImVec2(32.0f / my_tex_w, 32 / my_tex_h), frame_padding, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)))
			pressed_count += 1;
		ImGui::PopID();
		ImGui::SameLine();
	}*/



	ImGui::End();

	
}


void Inventory::load(int anchoPantalla, int altoPantalla)
{


	int indexSlot = 1000;
	slots = new Grafico*[3];

	for (int i = 0;i<9;i++) {
		slot = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
		slot->setDimensionPantalla(anchoPantalla, altoPantalla);
		slot->definirTextura(indexSlot);
		slot->InitializeSprite();
		slot->ajustarImagen();

		slots[i] = slot;
		indexSlot += i;
	}

}


Inventory::~Inventory()
{
}
