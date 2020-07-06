#pragma once

#include <msclr\marshal_cppstd.h>
#include "Recursos.h"
#include "Grafica.h"
#include <iostream>
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Formulario {

	
	public ref class EditorFrm : public Form
	{
		Recursos* recursos;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  grhParticulas;
	private: System::Windows::Forms::ListBox^  grhList;


	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabProp;
	private: System::Windows::Forms::TabPage^  tabGrav;






















	private: System::Windows::Forms::TabPage^  tabMov;
	private: System::Windows::Forms::TabPage^  tabGiro;
	private: System::Windows::Forms::TabPage^  tabVeloc;
	private: System::Windows::Forms::TabPage^  tabDurac;
	private: System::Windows::Forms::TabPage^  tabTonalidad;
	private: System::Windows::Forms::TabPage^  tabFade;


			 Grafica* grafica;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox2;















































































































private: System::Windows::Forms::GroupBox^  gbPropiedades;
private: System::Windows::Forms::TextBox^  txtX2;
private: System::Windows::Forms::TextBox^  txtY1;
private: System::Windows::Forms::TextBox^  txtY2;
private: System::Windows::Forms::TextBox^  txtFriction;
private: System::Windows::Forms::TextBox^  txtLRH;
private: System::Windows::Forms::TextBox^  txtLRL;
private: System::Windows::Forms::TextBox^  txtReizeY;
private: System::Windows::Forms::TextBox^  txtResizeX;
private: System::Windows::Forms::TextBox^  txtAngle;
private: System::Windows::Forms::TextBox^  txtVectY2;
private: System::Windows::Forms::TextBox^  txtVecX2;
private: System::Windows::Forms::TextBox^  txtVectY1;
private: System::Windows::Forms::TextBox^  txtVecX1;
private: System::Windows::Forms::TextBox^  txtX1;
private: System::Windows::Forms::TextBox^  txtNroPart;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::GroupBox^  gbDuracion;
private: System::Windows::Forms::TextBox^  txtLife;
private: System::Windows::Forms::CheckBox^  chkNvDies;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::GroupBox^  gbTonalidad;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::TextBox^  textBoxG;
private: System::Windows::Forms::TextBox^  textBoxB;
private: System::Windows::Forms::TextBox^  textBoxR;
private: System::Windows::Forms::ListBox^  listBox2;
private: System::Windows::Forms::HScrollBar^  hScrollB;
private: System::Windows::Forms::HScrollBar^  hScrollG;
private: System::Windows::Forms::HScrollBar^  hScrollR;
private: System::Windows::Forms::PictureBox^  picColor;
private: System::Windows::Forms::GroupBox^  gbGravedad;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::TextBox^  txtBounStr;
private: System::Windows::Forms::TextBox^  txtGrvStr;
private: System::Windows::Forms::CheckBox^  chkGrhInfluence;
private: System::Windows::Forms::GroupBox^  gbVelocidad;
private: System::Windows::Forms::TextBox^  txtRndDelay;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::GroupBox^  gbMov;
private: System::Windows::Forms::TextBox^  txtMovY2;
private: System::Windows::Forms::TextBox^  txtMovY1;
private: System::Windows::Forms::TextBox^  txtMovX2;
private: System::Windows::Forms::TextBox^  txtMovX1;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::CheckBox^  chkYMov;
private: System::Windows::Forms::CheckBox^  chkXMov;
private: System::Windows::Forms::GroupBox^  gbFade;
private: System::Windows::Forms::TextBox^  txtFadeOutTime;
private: System::Windows::Forms::TextBox^  txtFadeInTime;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::GroupBox^  gbGiro;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::CheckBox^  chkSpin;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^  archivoToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  nuevaParticulaToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  guardarToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  salirToolStripMenuItem;



		particula* tempParticula;
	public:
		EditorFrm(void){
			InitializeComponent();
			setVisualFrame(true, true, true, true, true, true, true, true);
		}
		
		void setGrafica(Grafica* graficaParam)
		{
			grafica = graficaParam;
			cargarDatosParticula(18);
		}

		void setRecursos(Recursos* recursosParam)
		{
			recursos = recursosParam;
			cargarNombreParticulas();
			cartarListaIndexacionesGraficos();
		}

	protected:

		~EditorFrm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	public:
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->grhParticulas = (gcnew System::Windows::Forms::ListBox());
			this->grhList = (gcnew System::Windows::Forms::ListBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabProp = (gcnew System::Windows::Forms::TabPage());
			this->gbPropiedades = (gcnew System::Windows::Forms::GroupBox());
			this->txtX2 = (gcnew System::Windows::Forms::TextBox());
			this->txtY1 = (gcnew System::Windows::Forms::TextBox());
			this->txtY2 = (gcnew System::Windows::Forms::TextBox());
			this->txtFriction = (gcnew System::Windows::Forms::TextBox());
			this->txtLRH = (gcnew System::Windows::Forms::TextBox());
			this->txtLRL = (gcnew System::Windows::Forms::TextBox());
			this->txtReizeY = (gcnew System::Windows::Forms::TextBox());
			this->txtResizeX = (gcnew System::Windows::Forms::TextBox());
			this->txtAngle = (gcnew System::Windows::Forms::TextBox());
			this->txtVectY2 = (gcnew System::Windows::Forms::TextBox());
			this->txtVecX2 = (gcnew System::Windows::Forms::TextBox());
			this->txtVectY1 = (gcnew System::Windows::Forms::TextBox());
			this->txtVecX1 = (gcnew System::Windows::Forms::TextBox());
			this->txtX1 = (gcnew System::Windows::Forms::TextBox());
			this->txtNroPart = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabGrav = (gcnew System::Windows::Forms::TabPage());
			this->gbGravedad = (gcnew System::Windows::Forms::GroupBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->txtBounStr = (gcnew System::Windows::Forms::TextBox());
			this->txtGrvStr = (gcnew System::Windows::Forms::TextBox());
			this->chkGrhInfluence = (gcnew System::Windows::Forms::CheckBox());
			this->tabMov = (gcnew System::Windows::Forms::TabPage());
			this->gbMov = (gcnew System::Windows::Forms::GroupBox());
			this->txtMovY2 = (gcnew System::Windows::Forms::TextBox());
			this->txtMovY1 = (gcnew System::Windows::Forms::TextBox());
			this->txtMovX2 = (gcnew System::Windows::Forms::TextBox());
			this->txtMovX1 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->chkYMov = (gcnew System::Windows::Forms::CheckBox());
			this->chkXMov = (gcnew System::Windows::Forms::CheckBox());
			this->tabGiro = (gcnew System::Windows::Forms::TabPage());
			this->gbGiro = (gcnew System::Windows::Forms::GroupBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->chkSpin = (gcnew System::Windows::Forms::CheckBox());
			this->tabVeloc = (gcnew System::Windows::Forms::TabPage());
			this->gbVelocidad = (gcnew System::Windows::Forms::GroupBox());
			this->txtRndDelay = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->tabDurac = (gcnew System::Windows::Forms::TabPage());
			this->gbDuracion = (gcnew System::Windows::Forms::GroupBox());
			this->txtLife = (gcnew System::Windows::Forms::TextBox());
			this->chkNvDies = (gcnew System::Windows::Forms::CheckBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->tabTonalidad = (gcnew System::Windows::Forms::TabPage());
			this->gbTonalidad = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxG = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->textBoxR = (gcnew System::Windows::Forms::TextBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->hScrollB = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollG = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollR = (gcnew System::Windows::Forms::HScrollBar());
			this->picColor = (gcnew System::Windows::Forms::PictureBox());
			this->tabFade = (gcnew System::Windows::Forms::TabPage());
			this->gbFade = (gcnew System::Windows::Forms::GroupBox());
			this->txtFadeOutTime = (gcnew System::Windows::Forms::TextBox());
			this->txtFadeInTime = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nuevaParticulaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guardarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabProp->SuspendLayout();
			this->gbPropiedades->SuspendLayout();
			this->tabGrav->SuspendLayout();
			this->gbGravedad->SuspendLayout();
			this->tabMov->SuspendLayout();
			this->gbMov->SuspendLayout();
			this->tabGiro->SuspendLayout();
			this->gbGiro->SuspendLayout();
			this->tabVeloc->SuspendLayout();
			this->gbVelocidad->SuspendLayout();
			this->tabDurac->SuspendLayout();
			this->gbDuracion->SuspendLayout();
			this->tabTonalidad->SuspendLayout();
			this->gbTonalidad->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picColor))->BeginInit();
			this->tabFade->SuspendLayout();
			this->gbFade->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Location = System::Drawing::Point(12, 29);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(545, 419);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->listBox1);
			this->groupBox1->Location = System::Drawing::Point(567, 25);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(224, 249);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Particulas";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(10, 19);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(208, 225);
			this->listBox1->TabIndex = 3;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &EditorFrm::listBox1_SelectedIndexChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->grhParticulas);
			this->groupBox2->Controls->Add(this->grhList);
			this->groupBox2->Location = System::Drawing::Point(567, 280);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(230, 161);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Indices";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(95, 92);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(48, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"<----";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(95, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(48, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"----->";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// grhParticulas
			// 
			this->grhParticulas->FormattingEnabled = true;
			this->grhParticulas->Location = System::Drawing::Point(143, 42);
			this->grhParticulas->Name = L"grhParticulas";
			this->grhParticulas->Size = System::Drawing::Size(81, 95);
			this->grhParticulas->TabIndex = 1;
			this->grhParticulas->SelectedIndexChanged += gcnew System::EventHandler(this, &EditorFrm::listBox3_SelectedIndexChanged);
			// 
			// grhList
			// 
			this->grhList->FormattingEnabled = true;
			this->grhList->Location = System::Drawing::Point(6, 42);
			this->grhList->Name = L"grhList";
			this->grhList->Size = System::Drawing::Size(88, 95);
			this->grhList->TabIndex = 0;
			this->grhList->SelectedIndexChanged += gcnew System::EventHandler(this, &EditorFrm::grhList_SelectedIndexChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabProp);
			this->tabControl1->Controls->Add(this->tabGrav);
			this->tabControl1->Controls->Add(this->tabMov);
			this->tabControl1->Controls->Add(this->tabGiro);
			this->tabControl1->Controls->Add(this->tabVeloc);
			this->tabControl1->Controls->Add(this->tabDurac);
			this->tabControl1->Controls->Add(this->tabTonalidad);
			this->tabControl1->Controls->Add(this->tabFade);
			this->tabControl1->Location = System::Drawing::Point(12, 454);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(549, 195);
			this->tabControl1->TabIndex = 5;
			// 
			// tabProp
			// 
			this->tabProp->Controls->Add(this->gbPropiedades);
			this->tabProp->Location = System::Drawing::Point(4, 22);
			this->tabProp->Name = L"tabProp";
			this->tabProp->Padding = System::Windows::Forms::Padding(3);
			this->tabProp->Size = System::Drawing::Size(541, 169);
			this->tabProp->TabIndex = 0;
			this->tabProp->Text = L"Propiedades";
			this->tabProp->UseVisualStyleBackColor = true;
			// 
			// gbPropiedades
			// 
			this->gbPropiedades->Controls->Add(this->txtX2);
			this->gbPropiedades->Controls->Add(this->txtY1);
			this->gbPropiedades->Controls->Add(this->txtY2);
			this->gbPropiedades->Controls->Add(this->txtFriction);
			this->gbPropiedades->Controls->Add(this->txtLRH);
			this->gbPropiedades->Controls->Add(this->txtLRL);
			this->gbPropiedades->Controls->Add(this->txtReizeY);
			this->gbPropiedades->Controls->Add(this->txtResizeX);
			this->gbPropiedades->Controls->Add(this->txtAngle);
			this->gbPropiedades->Controls->Add(this->txtVectY2);
			this->gbPropiedades->Controls->Add(this->txtVecX2);
			this->gbPropiedades->Controls->Add(this->txtVectY1);
			this->gbPropiedades->Controls->Add(this->txtVecX1);
			this->gbPropiedades->Controls->Add(this->txtX1);
			this->gbPropiedades->Controls->Add(this->txtNroPart);
			this->gbPropiedades->Controls->Add(this->label16);
			this->gbPropiedades->Controls->Add(this->label15);
			this->gbPropiedades->Controls->Add(this->label8);
			this->gbPropiedades->Controls->Add(this->label14);
			this->gbPropiedades->Controls->Add(this->label18);
			this->gbPropiedades->Controls->Add(this->label13);
			this->gbPropiedades->Controls->Add(this->label9);
			this->gbPropiedades->Controls->Add(this->label17);
			this->gbPropiedades->Controls->Add(this->label12);
			this->gbPropiedades->Controls->Add(this->label11);
			this->gbPropiedades->Controls->Add(this->label10);
			this->gbPropiedades->Controls->Add(this->label7);
			this->gbPropiedades->Controls->Add(this->label6);
			this->gbPropiedades->Controls->Add(this->label5);
			this->gbPropiedades->Controls->Add(this->label4);
			this->gbPropiedades->Location = System::Drawing::Point(6, 6);
			this->gbPropiedades->Name = L"gbPropiedades";
			this->gbPropiedades->Size = System::Drawing::Size(410, 158);
			this->gbPropiedades->TabIndex = 8;
			this->gbPropiedades->TabStop = false;
			this->gbPropiedades->Text = L"Propiedades";
			this->gbPropiedades->Visible = false;
			// 
			// txtX2
			// 
			this->txtX2->Location = System::Drawing::Point(79, 65);
			this->txtX2->Name = L"txtX2";
			this->txtX2->Size = System::Drawing::Size(43, 20);
			this->txtX2->TabIndex = 34;
			// 
			// txtY1
			// 
			this->txtY1->Location = System::Drawing::Point(79, 87);
			this->txtY1->Name = L"txtY1";
			this->txtY1->Size = System::Drawing::Size(43, 20);
			this->txtY1->TabIndex = 33;
			// 
			// txtY2
			// 
			this->txtY2->Location = System::Drawing::Point(79, 110);
			this->txtY2->Name = L"txtY2";
			this->txtY2->Size = System::Drawing::Size(43, 20);
			this->txtY2->TabIndex = 32;
			// 
			// txtFriction
			// 
			this->txtFriction->Location = System::Drawing::Point(347, 117);
			this->txtFriction->Name = L"txtFriction";
			this->txtFriction->Size = System::Drawing::Size(43, 20);
			this->txtFriction->TabIndex = 30;
			// 
			// txtLRH
			// 
			this->txtLRH->Location = System::Drawing::Point(347, 92);
			this->txtLRH->Name = L"txtLRH";
			this->txtLRH->Size = System::Drawing::Size(43, 20);
			this->txtLRH->TabIndex = 29;
			// 
			// txtLRL
			// 
			this->txtLRL->Location = System::Drawing::Point(347, 67);
			this->txtLRL->Name = L"txtLRL";
			this->txtLRL->Size = System::Drawing::Size(43, 20);
			this->txtLRL->TabIndex = 28;
			// 
			// txtReizeY
			// 
			this->txtReizeY->Location = System::Drawing::Point(347, 44);
			this->txtReizeY->Name = L"txtReizeY";
			this->txtReizeY->Size = System::Drawing::Size(43, 20);
			this->txtReizeY->TabIndex = 27;
			// 
			// txtResizeX
			// 
			this->txtResizeX->Location = System::Drawing::Point(347, 20);
			this->txtResizeX->Name = L"txtResizeX";
			this->txtResizeX->Size = System::Drawing::Size(43, 20);
			this->txtResizeX->TabIndex = 26;
			// 
			// txtAngle
			// 
			this->txtAngle->Location = System::Drawing::Point(195, 121);
			this->txtAngle->Name = L"txtAngle";
			this->txtAngle->Size = System::Drawing::Size(43, 20);
			this->txtAngle->TabIndex = 25;
			// 
			// txtVectY2
			// 
			this->txtVectY2->Location = System::Drawing::Point(195, 95);
			this->txtVectY2->Name = L"txtVectY2";
			this->txtVectY2->Size = System::Drawing::Size(43, 20);
			this->txtVectY2->TabIndex = 24;
			// 
			// txtVecX2
			// 
			this->txtVecX2->Location = System::Drawing::Point(195, 45);
			this->txtVecX2->Name = L"txtVecX2";
			this->txtVecX2->Size = System::Drawing::Size(43, 20);
			this->txtVecX2->TabIndex = 23;
			// 
			// txtVectY1
			// 
			this->txtVectY1->Location = System::Drawing::Point(195, 70);
			this->txtVectY1->Name = L"txtVectY1";
			this->txtVectY1->Size = System::Drawing::Size(43, 20);
			this->txtVectY1->TabIndex = 22;
			// 
			// txtVecX1
			// 
			this->txtVecX1->Location = System::Drawing::Point(194, 20);
			this->txtVecX1->Name = L"txtVecX1";
			this->txtVecX1->Size = System::Drawing::Size(43, 20);
			this->txtVecX1->TabIndex = 21;
			// 
			// txtX1
			// 
			this->txtX1->Location = System::Drawing::Point(79, 42);
			this->txtX1->Name = L"txtX1";
			this->txtX1->Size = System::Drawing::Size(43, 20);
			this->txtX1->TabIndex = 20;
			// 
			// txtNroPart
			// 
			this->txtNroPart->Location = System::Drawing::Point(79, 19);
			this->txtNroPart->Name = L"txtNroPart";
			this->txtNroPart->Size = System::Drawing::Size(43, 20);
			this->txtNroPart->TabIndex = 19;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(271, 97);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(65, 13);
			this->label16->TabIndex = 18;
			this->label16->Text = L"Life range H";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(271, 73);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(63, 13);
			this->label15->TabIndex = 17;
			this->label15->Text = L"Life range L";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(270, 23);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(46, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"ResizeX";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(270, 49);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(46, 13);
			this->label14->TabIndex = 16;
			this->label14->Text = L"ResizeY";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(271, 120);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(41, 13);
			this->label18->TabIndex = 14;
			this->label18->Text = L"Friction";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(137, 74);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(51, 13);
			this->label13->TabIndex = 9;
			this->label13->Text = L"VectorY1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(137, 97);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(51, 13);
			this->label9->TabIndex = 5;
			this->label9->Text = L"VectorY2";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(139, 122);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(34, 13);
			this->label17->TabIndex = 13;
			this->label17->Text = L"Angle";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(137, 49);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(51, 13);
			this->label12->TabIndex = 8;
			this->label12->Text = L"VectorX2";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(17, 113);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(20, 13);
			this->label11->TabIndex = 7;
			this->label11->Text = L"Y2";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(16, 66);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(20, 13);
			this->label10->TabIndex = 6;
			this->label10->Text = L"X2";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(137, 25);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(51, 13);
			this->label7->TabIndex = 3;
			this->label7->Text = L"VectorX1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 89);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 13);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Y1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 43);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"X1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(14, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"# particulas";
			// 
			// tabGrav
			// 
			this->tabGrav->Controls->Add(this->gbGravedad);
			this->tabGrav->Location = System::Drawing::Point(4, 22);
			this->tabGrav->Name = L"tabGrav";
			this->tabGrav->Padding = System::Windows::Forms::Padding(3);
			this->tabGrav->Size = System::Drawing::Size(541, 169);
			this->tabGrav->TabIndex = 1;
			this->tabGrav->Text = L"Gravedad";
			this->tabGrav->UseVisualStyleBackColor = true;
			// 
			// gbGravedad
			// 
			this->gbGravedad->Controls->Add(this->label25);
			this->gbGravedad->Controls->Add(this->label24);
			this->gbGravedad->Controls->Add(this->txtBounStr);
			this->gbGravedad->Controls->Add(this->txtGrvStr);
			this->gbGravedad->Controls->Add(this->chkGrhInfluence);
			this->gbGravedad->Location = System::Drawing::Point(19, 17);
			this->gbGravedad->Name = L"gbGravedad";
			this->gbGravedad->Size = System::Drawing::Size(200, 100);
			this->gbGravedad->TabIndex = 6;
			this->gbGravedad->TabStop = false;
			this->gbGravedad->Text = L"Gravedad";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(12, 73);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(87, 13);
			this->label25->TabIndex = 4;
			this->label25->Text = L"Bounce Strength";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(11, 48);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(83, 13);
			this->label24->TabIndex = 3;
			this->label24->Text = L"Gravity Strength";
			// 
			// txtBounStr
			// 
			this->txtBounStr->Location = System::Drawing::Point(103, 70);
			this->txtBounStr->Name = L"txtBounStr";
			this->txtBounStr->Size = System::Drawing::Size(29, 20);
			this->txtBounStr->TabIndex = 2;
			// 
			// txtGrvStr
			// 
			this->txtGrvStr->Location = System::Drawing::Point(103, 44);
			this->txtGrvStr->Name = L"txtGrvStr";
			this->txtGrvStr->Size = System::Drawing::Size(29, 20);
			this->txtGrvStr->TabIndex = 1;
			// 
			// chkGrhInfluence
			// 
			this->chkGrhInfluence->AutoSize = true;
			this->chkGrhInfluence->Location = System::Drawing::Point(19, 22);
			this->chkGrhInfluence->Name = L"chkGrhInfluence";
			this->chkGrhInfluence->Size = System::Drawing::Size(106, 17);
			this->chkGrhInfluence->TabIndex = 0;
			this->chkGrhInfluence->Text = L"Gravity Influence";
			this->chkGrhInfluence->UseVisualStyleBackColor = true;
			// 
			// tabMov
			// 
			this->tabMov->Controls->Add(this->gbMov);
			this->tabMov->Location = System::Drawing::Point(4, 22);
			this->tabMov->Name = L"tabMov";
			this->tabMov->Size = System::Drawing::Size(541, 169);
			this->tabMov->TabIndex = 2;
			this->tabMov->Text = L"Movimiento";
			this->tabMov->UseVisualStyleBackColor = true;
			// 
			// gbMov
			// 
			this->gbMov->Controls->Add(this->txtMovY2);
			this->gbMov->Controls->Add(this->txtMovY1);
			this->gbMov->Controls->Add(this->txtMovX2);
			this->gbMov->Controls->Add(this->txtMovX1);
			this->gbMov->Controls->Add(this->label22);
			this->gbMov->Controls->Add(this->label21);
			this->gbMov->Controls->Add(this->label20);
			this->gbMov->Controls->Add(this->label19);
			this->gbMov->Controls->Add(this->chkYMov);
			this->gbMov->Controls->Add(this->chkXMov);
			this->gbMov->Location = System::Drawing::Point(3, 3);
			this->gbMov->Name = L"gbMov";
			this->gbMov->Size = System::Drawing::Size(340, 163);
			this->gbMov->TabIndex = 6;
			this->gbMov->TabStop = false;
			this->gbMov->Text = L"Movimiento";
			// 
			// txtMovY2
			// 
			this->txtMovY2->Location = System::Drawing::Point(249, 76);
			this->txtMovY2->Name = L"txtMovY2";
			this->txtMovY2->Size = System::Drawing::Size(56, 20);
			this->txtMovY2->TabIndex = 15;
			// 
			// txtMovY1
			// 
			this->txtMovY1->Location = System::Drawing::Point(249, 51);
			this->txtMovY1->Name = L"txtMovY1";
			this->txtMovY1->Size = System::Drawing::Size(56, 20);
			this->txtMovY1->TabIndex = 14;
			// 
			// txtMovX2
			// 
			this->txtMovX2->Location = System::Drawing::Point(94, 74);
			this->txtMovX2->Name = L"txtMovX2";
			this->txtMovX2->Size = System::Drawing::Size(56, 20);
			this->txtMovX2->TabIndex = 13;
			// 
			// txtMovX1
			// 
			this->txtMovX1->Location = System::Drawing::Point(94, 48);
			this->txtMovX1->Name = L"txtMovX1";
			this->txtMovX1->Size = System::Drawing::Size(56, 20);
			this->txtMovX1->TabIndex = 12;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(173, 55);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(73, 13);
			this->label22->TabIndex = 11;
			this->label22->Text = L"Movement Y1";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(173, 78);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(73, 13);
			this->label21->TabIndex = 10;
			this->label21->Text = L"Movement Y2";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(21, 79);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(73, 13);
			this->label20->TabIndex = 9;
			this->label20->Text = L"Movement X2";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(21, 52);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(73, 13);
			this->label19->TabIndex = 8;
			this->label19->Text = L"Movement X1";
			// 
			// chkYMov
			// 
			this->chkYMov->AutoSize = true;
			this->chkYMov->Location = System::Drawing::Point(176, 27);
			this->chkYMov->Name = L"chkYMov";
			this->chkYMov->Size = System::Drawing::Size(86, 17);
			this->chkYMov->TabIndex = 7;
			this->chkYMov->Text = L"Y Movement";
			this->chkYMov->UseVisualStyleBackColor = true;
			// 
			// chkXMov
			// 
			this->chkXMov->AutoSize = true;
			this->chkXMov->Location = System::Drawing::Point(20, 28);
			this->chkXMov->Name = L"chkXMov";
			this->chkXMov->Size = System::Drawing::Size(86, 17);
			this->chkXMov->TabIndex = 6;
			this->chkXMov->Text = L"X Movement";
			this->chkXMov->UseVisualStyleBackColor = true;
			// 
			// tabGiro
			// 
			this->tabGiro->Controls->Add(this->gbGiro);
			this->tabGiro->Location = System::Drawing::Point(4, 22);
			this->tabGiro->Name = L"tabGiro";
			this->tabGiro->Size = System::Drawing::Size(541, 169);
			this->tabGiro->TabIndex = 3;
			this->tabGiro->Text = L"Giro de particula";
			this->tabGiro->UseVisualStyleBackColor = true;
			// 
			// gbGiro
			// 
			this->gbGiro->Controls->Add(this->label28);
			this->gbGiro->Controls->Add(this->label27);
			this->gbGiro->Controls->Add(this->textBox2);
			this->gbGiro->Controls->Add(this->textBox1);
			this->gbGiro->Controls->Add(this->chkSpin);
			this->gbGiro->Location = System::Drawing::Point(3, 8);
			this->gbGiro->Name = L"gbGiro";
			this->gbGiro->Size = System::Drawing::Size(200, 125);
			this->gbGiro->TabIndex = 5;
			this->gbGiro->TabStop = false;
			this->gbGiro->Text = L"Giro";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(25, 97);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(79, 13);
			this->label28->TabIndex = 4;
			this->label28->Text = L"Spin Speed (H)";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(24, 62);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(77, 13);
			this->label27->TabIndex = 3;
			this->label27->Text = L"Spin Speed (L)";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(107, 94);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(55, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(106, 59);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(55, 20);
			this->textBox1->TabIndex = 1;
			// 
			// chkSpin
			// 
			this->chkSpin->AutoSize = true;
			this->chkSpin->Location = System::Drawing::Point(24, 28);
			this->chkSpin->Name = L"chkSpin";
			this->chkSpin->Size = System::Drawing::Size(47, 17);
			this->chkSpin->TabIndex = 0;
			this->chkSpin->Text = L"Spin";
			this->chkSpin->UseVisualStyleBackColor = true;
			// 
			// tabVeloc
			// 
			this->tabVeloc->Controls->Add(this->gbVelocidad);
			this->tabVeloc->Location = System::Drawing::Point(4, 22);
			this->tabVeloc->Name = L"tabVeloc";
			this->tabVeloc->Size = System::Drawing::Size(541, 169);
			this->tabVeloc->TabIndex = 4;
			this->tabVeloc->Text = L"Velocidad";
			this->tabVeloc->UseVisualStyleBackColor = true;
			// 
			// gbVelocidad
			// 
			this->gbVelocidad->Controls->Add(this->txtRndDelay);
			this->gbVelocidad->Controls->Add(this->label23);
			this->gbVelocidad->Location = System::Drawing::Point(21, 24);
			this->gbVelocidad->Name = L"gbVelocidad";
			this->gbVelocidad->Size = System::Drawing::Size(200, 109);
			this->gbVelocidad->TabIndex = 7;
			this->gbVelocidad->TabStop = false;
			this->gbVelocidad->Text = L"Velocidad";
			// 
			// txtRndDelay
			// 
			this->txtRndDelay->Location = System::Drawing::Point(111, 45);
			this->txtRndDelay->Name = L"txtRndDelay";
			this->txtRndDelay->Size = System::Drawing::Size(45, 20);
			this->txtRndDelay->TabIndex = 1;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(27, 49);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(70, 13);
			this->label23->TabIndex = 0;
			this->label23->Text = L"Render delay";
			// 
			// tabDurac
			// 
			this->tabDurac->Controls->Add(this->gbDuracion);
			this->tabDurac->Location = System::Drawing::Point(4, 22);
			this->tabDurac->Name = L"tabDurac";
			this->tabDurac->Size = System::Drawing::Size(541, 169);
			this->tabDurac->TabIndex = 5;
			this->tabDurac->Text = L"Duracion";
			this->tabDurac->UseVisualStyleBackColor = true;
			// 
			// gbDuracion
			// 
			this->gbDuracion->Controls->Add(this->txtLife);
			this->gbDuracion->Controls->Add(this->chkNvDies);
			this->gbDuracion->Controls->Add(this->label26);
			this->gbDuracion->Location = System::Drawing::Point(16, 21);
			this->gbDuracion->Name = L"gbDuracion";
			this->gbDuracion->Size = System::Drawing::Size(200, 100);
			this->gbDuracion->TabIndex = 6;
			this->gbDuracion->TabStop = false;
			this->gbDuracion->Text = L"Duracion";
			// 
			// txtLife
			// 
			this->txtLife->Location = System::Drawing::Point(102, 50);
			this->txtLife->Name = L"txtLife";
			this->txtLife->Size = System::Drawing::Size(40, 20);
			this->txtLife->TabIndex = 2;
			// 
			// chkNvDies
			// 
			this->chkNvDies->AutoSize = true;
			this->chkNvDies->Location = System::Drawing::Point(24, 28);
			this->chkNvDies->Name = L"chkNvDies";
			this->chkNvDies->Size = System::Drawing::Size(79, 17);
			this->chkNvDies->TabIndex = 1;
			this->chkNvDies->Text = L"Never Dies";
			this->chkNvDies->UseVisualStyleBackColor = true;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(25, 55);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(24, 13);
			this->label26->TabIndex = 0;
			this->label26->Text = L"Life";
			// 
			// tabTonalidad
			// 
			this->tabTonalidad->Controls->Add(this->gbTonalidad);
			this->tabTonalidad->Location = System::Drawing::Point(4, 22);
			this->tabTonalidad->Name = L"tabTonalidad";
			this->tabTonalidad->Size = System::Drawing::Size(541, 169);
			this->tabTonalidad->TabIndex = 6;
			this->tabTonalidad->Text = L"Tonalidad";
			this->tabTonalidad->UseVisualStyleBackColor = true;
			// 
			// gbTonalidad
			// 
			this->gbTonalidad->Controls->Add(this->label3);
			this->gbTonalidad->Controls->Add(this->label2);
			this->gbTonalidad->Controls->Add(this->label1);
			this->gbTonalidad->Controls->Add(this->textBoxG);
			this->gbTonalidad->Controls->Add(this->textBoxB);
			this->gbTonalidad->Controls->Add(this->textBoxR);
			this->gbTonalidad->Controls->Add(this->listBox2);
			this->gbTonalidad->Controls->Add(this->hScrollB);
			this->gbTonalidad->Controls->Add(this->hScrollG);
			this->gbTonalidad->Controls->Add(this->hScrollR);
			this->gbTonalidad->Controls->Add(this->picColor);
			this->gbTonalidad->Location = System::Drawing::Point(3, 6);
			this->gbTonalidad->Name = L"gbTonalidad";
			this->gbTonalidad->Size = System::Drawing::Size(355, 160);
			this->gbTonalidad->TabIndex = 2;
			this->gbTonalidad->TabStop = false;
			this->gbTonalidad->Text = L"Tonalidad";
			this->gbTonalidad->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(30, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(15, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"G";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"B";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(15, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"R";
			// 
			// textBoxG
			// 
			this->textBoxG->Location = System::Drawing::Point(305, 104);
			this->textBoxG->Name = L"textBoxG";
			this->textBoxG->Size = System::Drawing::Size(42, 20);
			this->textBoxG->TabIndex = 7;
			// 
			// textBoxB
			// 
			this->textBoxB->Location = System::Drawing::Point(305, 127);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(42, 20);
			this->textBoxB->TabIndex = 6;
			// 
			// textBoxR
			// 
			this->textBoxR->Location = System::Drawing::Point(305, 79);
			this->textBoxR->Name = L"textBoxR";
			this->textBoxR->Size = System::Drawing::Size(42, 20);
			this->textBoxR->TabIndex = 2;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Bottom left", L"Top left", L"Bottom Right", L"Top Right" });
			this->listBox2->Location = System::Drawing::Point(49, 19);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(96, 56);
			this->listBox2->TabIndex = 5;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &EditorFrm::listBox2_SelectedIndexChanged_1);
			// 
			// hScrollB
			// 
			this->hScrollB->Location = System::Drawing::Point(48, 127);
			this->hScrollB->Maximum = 255;
			this->hScrollB->Name = L"hScrollB";
			this->hScrollB->Size = System::Drawing::Size(243, 20);
			this->hScrollB->TabIndex = 4;
			// 
			// hScrollG
			// 
			this->hScrollG->Location = System::Drawing::Point(48, 103);
			this->hScrollG->Maximum = 255;
			this->hScrollG->Name = L"hScrollG";
			this->hScrollG->Size = System::Drawing::Size(243, 20);
			this->hScrollG->TabIndex = 3;
			// 
			// hScrollR
			// 
			this->hScrollR->Location = System::Drawing::Point(48, 79);
			this->hScrollR->Maximum = 255;
			this->hScrollR->Name = L"hScrollR";
			this->hScrollR->Size = System::Drawing::Size(243, 20);
			this->hScrollR->TabIndex = 2;
			// 
			// picColor
			// 
			this->picColor->BackColor = System::Drawing::Color::White;
			this->picColor->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->picColor->Location = System::Drawing::Point(151, 19);
			this->picColor->Name = L"picColor";
			this->picColor->Size = System::Drawing::Size(198, 57);
			this->picColor->TabIndex = 1;
			this->picColor->TabStop = false;
			// 
			// tabFade
			// 
			this->tabFade->Controls->Add(this->gbFade);
			this->tabFade->Location = System::Drawing::Point(4, 22);
			this->tabFade->Name = L"tabFade";
			this->tabFade->Size = System::Drawing::Size(541, 169);
			this->tabFade->TabIndex = 7;
			this->tabFade->Text = L"Fade";
			this->tabFade->UseVisualStyleBackColor = true;
			// 
			// gbFade
			// 
			this->gbFade->Controls->Add(this->txtFadeOutTime);
			this->gbFade->Controls->Add(this->txtFadeInTime);
			this->gbFade->Controls->Add(this->label30);
			this->gbFade->Controls->Add(this->label29);
			this->gbFade->Location = System::Drawing::Point(29, 24);
			this->gbFade->Name = L"gbFade";
			this->gbFade->Size = System::Drawing::Size(200, 100);
			this->gbFade->TabIndex = 8;
			this->gbFade->TabStop = false;
			this->gbFade->Text = L"Fade";
			// 
			// txtFadeOutTime
			// 
			this->txtFadeOutTime->Location = System::Drawing::Point(93, 64);
			this->txtFadeOutTime->Name = L"txtFadeOutTime";
			this->txtFadeOutTime->Size = System::Drawing::Size(78, 20);
			this->txtFadeOutTime->TabIndex = 3;
			// 
			// txtFadeInTime
			// 
			this->txtFadeInTime->Location = System::Drawing::Point(93, 31);
			this->txtFadeInTime->Name = L"txtFadeInTime";
			this->txtFadeInTime->Size = System::Drawing::Size(74, 20);
			this->txtFadeInTime->TabIndex = 2;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(18, 69);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(71, 13);
			this->label30->TabIndex = 1;
			this->label30->Text = L"Fade out time";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(18, 34);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(64, 13);
			this->label29->TabIndex = 0;
			this->label29->Text = L"Fade in time";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->pictureBox2);
			this->groupBox4->Location = System::Drawing::Point(567, 443);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(230, 206);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Visor de graficos";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlText;
			this->pictureBox2->Location = System::Drawing::Point(21, 32);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(188, 168);
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->archivoToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(800, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &EditorFrm::menuStrip1_ItemClicked);
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->nuevaParticulaToolStripMenuItem,
					this->guardarToolStripMenuItem, this->salirToolStripMenuItem
			});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// nuevaParticulaToolStripMenuItem
			// 
			this->nuevaParticulaToolStripMenuItem->Name = L"nuevaParticulaToolStripMenuItem";
			this->nuevaParticulaToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->nuevaParticulaToolStripMenuItem->Text = L"Nueva particula";
			// 
			// guardarToolStripMenuItem
			// 
			this->guardarToolStripMenuItem->Name = L"guardarToolStripMenuItem";
			this->guardarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->guardarToolStripMenuItem->Text = L"Guardar";
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->salirToolStripMenuItem->Text = L"Salir";
			// 
			// EditorFrm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 648);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"EditorFrm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Editor de particulas InmortalAO";
			this->Load += gcnew System::EventHandler(this, &EditorFrm::EditorFrm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabProp->ResumeLayout(false);
			this->gbPropiedades->ResumeLayout(false);
			this->gbPropiedades->PerformLayout();
			this->tabGrav->ResumeLayout(false);
			this->gbGravedad->ResumeLayout(false);
			this->gbGravedad->PerformLayout();
			this->tabMov->ResumeLayout(false);
			this->gbMov->ResumeLayout(false);
			this->gbMov->PerformLayout();
			this->tabGiro->ResumeLayout(false);
			this->gbGiro->ResumeLayout(false);
			this->gbGiro->PerformLayout();
			this->tabVeloc->ResumeLayout(false);
			this->gbVelocidad->ResumeLayout(false);
			this->gbVelocidad->PerformLayout();
			this->tabDurac->ResumeLayout(false);
			this->gbDuracion->ResumeLayout(false);
			this->gbDuracion->PerformLayout();
			this->tabTonalidad->ResumeLayout(false);
			this->gbTonalidad->ResumeLayout(false);
			this->gbTonalidad->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picColor))->EndInit();
			this->tabFade->ResumeLayout(false);
			this->gbFade->ResumeLayout(false);
			this->gbFade->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	
	
	void cargarNombreParticulas()
	{
		int cantidad = recursos->getCantidadParticulas();
		
		
		particula* tempParticula;
		for (int i = 1; i <= cantidad; i++)
		{
			tempParticula = recursos->getParticula(i);
			std::string nombre = tempParticula->getName();
			
			System::String^ nombreS = msclr::interop::marshal_as<System::String^>(nombre);

			listBox1->Items->Add(i.ToString()+ " - " +nombreS);
		}

	}

#pragma endregion
	private: System::Void EditorFrm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
			 
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 int index = listBox1->SelectedIndex;
				 cargarDatosParticula(index + 1);
	}

			 void cargarDatosParticula(int indiceParticula)
			 {
				 grafica->cargarParticula(indiceParticula);
				 tempParticula = grafica->getTempParticula();
				 grhParticulas->Items->Clear();
				 for (int i = 0; i<tempParticula->getNumGrh(); i++)
					 grhParticulas->Items->Add(tempParticula->getGrhLista()[i]);

				 actualizarCamposDeTexto();
				 setColor(0);
			 }

			void setColor(int indicePosicionColor){
			
				 int r = tempParticula->getColorInt()[indicePosicionColor][2];
				 int g = tempParticula->getColorInt()[indicePosicionColor][1];
				 int b = tempParticula->getColorInt()[indicePosicionColor][0];

				 textBoxR->Text = r.ToString();
				 textBoxB->Text = b.ToString();
				 textBoxG->Text = g.ToString();

				 hScrollR->Value = r;
				 hScrollB->Value = b;
				 hScrollG->Value = g;

				 picColor->BackColor = Color::FromArgb(r, g, b);

				 
			 }

			void cartarListaIndexacionesGraficos()
			{
				int cantidadIndexaciones = recursos->getCantidadIndexGraficos();
				int tempIndexGrh;
				for (int i = 0;i<32016;i++)
				{
					grhList->Items->Add(i);
				}

			}

			void setVisualFrame(bool gbPropParam,bool gbTonalidadParam,bool gbDuracionParam,bool gbFadeParam,bool gbGiroParam,bool gbGravedadParam,bool gbMovParam,bool gbVelocidadParam)
			{
				gbPropiedades->Visible = gbPropParam;
				gbTonalidad->Visible = gbTonalidadParam;
				gbDuracion->Visible = gbDuracionParam;
				gbFade->Visible = gbFadeParam;
				gbGiro->Visible = gbGiroParam;
				gbGravedad->Visible = gbGravedadParam;
				gbMov->Visible = gbMovParam;
				gbVelocidad->Visible = gbVelocidadParam;
			}

			void actualizarCamposDeTexto()
			{
				txtAngle->Text = tempParticula->getAngle().ToString();
				txtBounStr->Text = tempParticula->getBounceStrength().ToString();
				//txtFadeInTime->Text = tempParticula;
				//txtFadeOutTime->Text = tempParticula;
				txtFriction->Text = tempParticula->getFriction().ToString();
				txtGrvStr->Text = tempParticula->getGravity().ToString();
				txtLife->Text = tempParticula->getLifeCounter().ToString();
				txtLRH->Text = tempParticula->getLife1().ToString();
				txtLRL->Text = tempParticula->getLife2().ToString();
				txtMovX1->Text = tempParticula->getMoveX1().ToString();
				txtMovX2->Text = tempParticula->getMoveX2().ToString();
				txtMovY2->Text = tempParticula->getMoveY2().ToString();
				txtMovY2->Text = tempParticula->getMoveY2().ToString();
				txtNroPart->Text = tempParticula->getNumParticles().ToString();
				txtReizeY->Text = tempParticula->getGrhResizeY().ToString();
				txtResizeX->Text = tempParticula->getGrhResizeX().ToString();
				//txtRndDelay->Text = tempParticula->GetR;
				txtVectY1->Text = tempParticula->getVecY1().ToString();
				txtVectY2->Text = tempParticula->getVecY2().ToString();
				txtVecX1->Text = tempParticula->getVecX1().ToString();
				txtVecX2->Text = tempParticula->getVectX2().ToString();
				txtX1->Text = tempParticula->getX1().ToString();
				txtX2->Text = tempParticula->getX2().ToString();
				txtY1->Text = tempParticula->getY1().ToString();
				txtY2->Text = tempParticula->getY2().ToString();
			}

	private: System::Void listBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 cargarImagenEnPicture((int)grhParticulas->Items[grhParticulas->SelectedIndex]);
	}
private: System::Void groupBox3_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label15_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label17_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void gpVelocidad_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listBox2_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
			 setColor(listBox2->SelectedIndex);
}
private: System::Void grhList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 cargarImagenEnPicture((int)grhList->Items[grhList->SelectedIndex]);
}

		 void cargarImagenEnPicture(int indiceGrh)
		 {
			 pictureBox2->Refresh();

			 HWND hWnd = static_cast<HWND>(pictureBox2->Handle.ToPointer());
			 HDC hdc = GetDC(hWnd);

			 int numGrh = recursos->GetGrafico(indiceGrh);
			 int h, w,sX,sY;
			 h = recursos->GetHGrafico(indiceGrh);
			 w =recursos->GetWGrafico(indiceGrh);
			 sX = recursos->GetXGrafico(indiceGrh);
			 sY = recursos->GetYGrafico(indiceGrh);

			 stringstream ss;
			 ss << numGrh;
			 string numStrGrh = ".\\Recursos\\Graficos\\" + ss.str() + ".bmp";

			 std::wstring stemp = s2ws(numStrGrh);
			 LPCWSTR result = stemp.c_str();

			 HBITMAP image = (HBITMAP)LoadImage(0, result, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			 //BITMAP bm;
			 //GetObject(image, sizeof(BITMAP), &bm);
			 HDC hdcdevice = CreateCompatibleDC(hdc);
			 SelectObject(hdcdevice, image);
			 BitBlt(hdc, 0, 0, w, h, hdcdevice, sX, sY, SRCCOPY);

			 //delete the device context and bitmap
			 DeleteDC(hdcdevice);
			 DeleteObject((HBITMAP)image);

		 }

		 std::wstring s2ws(const std::string& s)
		 {
			 int len;
			 int slength = (int)s.length() + 1;
			 len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
			 wchar_t* buf = new wchar_t[len];
			 MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
			 std::wstring r(buf);
			 delete[] buf;
			 return r;
		 }

private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
};
}
