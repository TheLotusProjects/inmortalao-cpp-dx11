#pragma once

#include "Grafica.h"

namespace Formulario {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de EditorMapas
	/// </summary>
	public ref class EditorMapas : public System::Windows::Forms::Form
	{
		Grafica* grafica;
		Recursos* recursos;
		personaje* pj;
		administradorRecursos* administrador;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabGrh;
	private: System::Windows::Forms::ListBox^  lstGrhIndex;
	private: System::Windows::Forms::TabPage^  tabCascos;
	private: System::Windows::Forms::TabPage^  tabArmas;
	private: System::Windows::Forms::TabPage^  tabEscudos;
	private: System::Windows::Forms::TabPage^  tabArmaduras;
	private: System::Windows::Forms::TabPage^  tabParticulas;
	public: System::Windows::Forms::PictureBox^  picMiniMap;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	public:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private:



			 int key;

	public:
		EditorMapas(void)
		{
			InitializeComponent();
			this->TabStop = true;
			this->SetStyle(System::Windows::Forms::ControlStyles::Selectable, true);
		}

		void setGrafica(Grafica* graficaParam)
		{
			grafica = graficaParam;
			recursos = grafica->getRecursos();
			pj = grafica->getPj();
			administrador = grafica->getAdministrador();
			cargarMapas();
		}

		int getKey()
		{
			return key;
		}

		void cargarMapas()
		{
			int cantidadMapas = 851;

			
			for (int i = 1; i <= cantidadMapas;i++)
			{
				lstMapas->Items->Add(i.ToString());
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~EditorMapas()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ListBox^  lstMapas;



	public:
	protected:

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lstMapas = (gcnew System::Windows::Forms::ListBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabGrh = (gcnew System::Windows::Forms::TabPage());
			this->lstGrhIndex = (gcnew System::Windows::Forms::ListBox());
			this->tabCascos = (gcnew System::Windows::Forms::TabPage());
			this->tabArmas = (gcnew System::Windows::Forms::TabPage());
			this->tabEscudos = (gcnew System::Windows::Forms::TabPage());
			this->tabArmaduras = (gcnew System::Windows::Forms::TabPage());
			this->tabParticulas = (gcnew System::Windows::Forms::TabPage());
			this->picMiniMap = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabGrh->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMiniMap))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Location = System::Drawing::Point(159, 26);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(544, 416);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &EditorMapas::pictureBox1_Click);
			this->pictureBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &EditorMapas::pictureBox1_KeyDown);
			// 
			// lstMapas
			// 
			this->lstMapas->FormattingEnabled = true;
			this->lstMapas->Location = System::Drawing::Point(4, 26);
			this->lstMapas->Name = L"lstMapas";
			this->lstMapas->Size = System::Drawing::Size(148, 303);
			this->lstMapas->TabIndex = 3;
			this->lstMapas->TabStop = false;
			this->lstMapas->Click += gcnew System::EventHandler(this, &EditorMapas::lstMapas_Click);
			this->lstMapas->SelectedIndexChanged += gcnew System::EventHandler(this, &EditorMapas::lstMapas_SelectedIndexChanged);
			this->lstMapas->TabIndexChanged += gcnew System::EventHandler(this, &EditorMapas::lstMapas_TabIndexChanged);
			this->lstMapas->TabStopChanged += gcnew System::EventHandler(this, &EditorMapas::lstMapas_TabStopChanged);
			this->lstMapas->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &EditorMapas::lstMapas_KeyDown);
			this->lstMapas->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &EditorMapas::lstMapas_KeyUp);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabGrh);
			this->tabControl1->Controls->Add(this->tabCascos);
			this->tabControl1->Controls->Add(this->tabArmas);
			this->tabControl1->Controls->Add(this->tabEscudos);
			this->tabControl1->Controls->Add(this->tabArmaduras);
			this->tabControl1->Controls->Add(this->tabParticulas);
			this->tabControl1->Location = System::Drawing::Point(709, 26);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(249, 228);
			this->tabControl1->TabIndex = 6;
			this->tabControl1->TabStop = false;
			// 
			// tabGrh
			// 
			this->tabGrh->Controls->Add(this->lstGrhIndex);
			this->tabGrh->Location = System::Drawing::Point(4, 22);
			this->tabGrh->Name = L"tabGrh";
			this->tabGrh->Padding = System::Windows::Forms::Padding(3);
			this->tabGrh->Size = System::Drawing::Size(241, 202);
			this->tabGrh->TabIndex = 0;
			this->tabGrh->Text = L"Graficos";
			this->tabGrh->UseVisualStyleBackColor = true;
			// 
			// lstGrhIndex
			// 
			this->lstGrhIndex->FormattingEnabled = true;
			this->lstGrhIndex->Location = System::Drawing::Point(18, 28);
			this->lstGrhIndex->Name = L"lstGrhIndex";
			this->lstGrhIndex->Size = System::Drawing::Size(181, 160);
			this->lstGrhIndex->TabIndex = 5;
			this->lstGrhIndex->TabStop = false;
			// 
			// tabCascos
			// 
			this->tabCascos->Location = System::Drawing::Point(4, 22);
			this->tabCascos->Name = L"tabCascos";
			this->tabCascos->Padding = System::Windows::Forms::Padding(3);
			this->tabCascos->Size = System::Drawing::Size(241, 202);
			this->tabCascos->TabIndex = 1;
			this->tabCascos->Text = L"Cascos";
			this->tabCascos->UseVisualStyleBackColor = true;
			// 
			// tabArmas
			// 
			this->tabArmas->Location = System::Drawing::Point(4, 22);
			this->tabArmas->Name = L"tabArmas";
			this->tabArmas->Size = System::Drawing::Size(241, 202);
			this->tabArmas->TabIndex = 2;
			this->tabArmas->Text = L"Armas";
			this->tabArmas->UseVisualStyleBackColor = true;
			// 
			// tabEscudos
			// 
			this->tabEscudos->Location = System::Drawing::Point(4, 22);
			this->tabEscudos->Name = L"tabEscudos";
			this->tabEscudos->Size = System::Drawing::Size(241, 202);
			this->tabEscudos->TabIndex = 3;
			this->tabEscudos->Text = L"Escudos";
			this->tabEscudos->UseVisualStyleBackColor = true;
			// 
			// tabArmaduras
			// 
			this->tabArmaduras->Location = System::Drawing::Point(4, 22);
			this->tabArmaduras->Name = L"tabArmaduras";
			this->tabArmaduras->Size = System::Drawing::Size(241, 202);
			this->tabArmaduras->TabIndex = 4;
			this->tabArmaduras->Text = L"Armaduras";
			this->tabArmaduras->UseVisualStyleBackColor = true;
			// 
			// tabParticulas
			// 
			this->tabParticulas->Location = System::Drawing::Point(4, 22);
			this->tabParticulas->Name = L"tabParticulas";
			this->tabParticulas->Size = System::Drawing::Size(241, 202);
			this->tabParticulas->TabIndex = 5;
			this->tabParticulas->Text = L"Particulas";
			this->tabParticulas->UseVisualStyleBackColor = true;
			// 
			// picMiniMap
			// 
			this->picMiniMap->BackColor = System::Drawing::SystemColors::ControlText;
			this->picMiniMap->Location = System::Drawing::Point(26, 335);
			this->picMiniMap->Name = L"picMiniMap";
			this->picMiniMap->Size = System::Drawing::Size(90, 95);
			this->picMiniMap->TabIndex = 7;
			this->picMiniMap->TabStop = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->pictureBox2);
			this->groupBox4->Location = System::Drawing::Point(709, 260);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(245, 182);
			this->groupBox4->TabIndex = 8;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Visor de graficos";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlText;
			this->pictureBox2->Location = System::Drawing::Point(22, 19);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(188, 151);
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// EditorMapas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 452);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->picMiniMap);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->lstMapas);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"EditorMapas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EditorMapas";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &EditorMapas::EditorMapas_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &EditorMapas::EditorMapas_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &EditorMapas::EditorMapas_KeyUp);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EditorMapas::EditorMapas_MouseClick);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabGrh->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMiniMap))->EndInit();
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void EditorMapas_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->Activate();
	}
	private: System::Void lstMapas_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 pj->setNroMapa(lstMapas->SelectedIndex + 1);
				 administrador->setMapaActual(lstMapas->SelectedIndex + 1);
				 this->Focus();
	}
public: System::Void EditorMapas_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 
			 if (!pj->estaCaminando())
			 {
				 switch (e->KeyCode)
				 {
				 case (Keys::Down) :
					 key = 40;
					 break;
				 case (Keys::Up) :
					 key = 38;
					 break;
				 case (Keys::Left) :
					 key = 37;
					 break;
				 case (Keys::Right) :
					 key = 39;
					 break;
				 case (Keys::Return) :
					 break;
				 }
				 //posicionMapa->Text = "Posición: " + pj->getNroMapa() + ", " + pj->getPossX() + ", " + pj->getPossY();
			 }
			 
}
private: System::Void lstMapas_TabStopChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->Focus();
			 
}
private: System::Void EditorMapas_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 key = -1;
			 
}

		 
public: System::Void pictureBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			if (!pj->estaCaminando())
			{
				switch (e->KeyCode)
				{
				case (Keys::Down) :
					key = 40;
					break;
				case (Keys::Up) :
					key = 38;
					break;
				case (Keys::Left) :
					key = 37;
					break;
				case (Keys::Right) :
					key = 39;
					break;
				case (Keys::Return) :
					break;
				}
				//posicionMapa->Text = "Posición: " + pj->getNroMapa() + ", " + pj->getPossX() + ", " + pj->getPossY();
			}

}

private: System::Void lstMapas_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 pictureBox1->Focus();
}
private: System::Void lstMapas_TabIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 pictureBox1->Focus();
}
private: System::Void EditorMapas_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 pictureBox1->Focus();
}


private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 pictureBox1->Focus();
}
private: System::Void lstMapas_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 pictureBox1->Focus();
}
private: System::Void lstMapas_Click(System::Object^  sender, System::EventArgs^  e) {
			 pictureBox1->Focus();
}
};
}
