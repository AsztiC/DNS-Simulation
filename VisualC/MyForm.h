#pragma once
#include <string> 
#include <vector>
#include "fstream"
#include <iostream>
#include <random>
#include <unordered_map>
#include <chrono>
#include "SplayTree.cpp"
#include "Hashmap.h"
#include "TimerClock.h"


namespace VisualC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:


		//List of simulation commands
		std::vector<std::pair<std::string, std::string>> *simulationList;
	private: System::Windows::Forms::TextBox^ textBox2;
	public:
	private: System::Windows::Forms::Label^ label14;

	public:

		   //List of websites
		std::vector<std::pair<std::string, std::string>>* websiteList;

		MyForm(void)
		{
			//Init vector
			simulationList = new std::vector<std::pair<std::string, std::string>>;
			websiteList = new std::vector<std::pair<std::string, std::string>>;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete simulationList;
				delete websiteList;
			}
		}
	//Form component list
	private: 
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Label^ label7;
		System::Windows::Forms::Label^ label8;
		System::Windows::Forms::Label^ label9;
		System::Windows::Forms::Label^ label10;
		System::Windows::Forms::Label^ label11;
		System::Windows::Forms::Label^ label12;
		System::Windows::Forms::Label^ label13;
		System::Windows::Forms::Button^ runBtn;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Label^ webCounter;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TrackBar^ trackBar1;
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::GroupBox^ groupBox2;
		System::Windows::Forms::ProgressBar^ progressBar1;
		System::Windows::Forms::RadioButton^ radioButton1;
		System::Windows::Forms::RadioButton^ radioButton2;
		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
		System::ComponentModel::Container ^components; /// Required designer variable.

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->runBtn = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->webCounter = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(521, 28);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"DNS Simulation";
			// 
			// runBtn
			// 
			this->runBtn->BackColor = System::Drawing::SystemColors::ControlLight;
			this->runBtn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->runBtn->Location = System::Drawing::Point(50, 247);
			this->runBtn->Margin = System::Windows::Forms::Padding(4);
			this->runBtn->Name = L"runBtn";
			this->runBtn->Size = System::Drawing::Size(168, 39);
			this->runBtn->TabIndex = 1;
			this->runBtn->Text = L"Run Simulation";
			this->runBtn->UseVisualStyleBackColor = false;
			this->runBtn->Click += gcnew System::EventHandler(this, &MyForm::runBtn_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(240, 45);
			this->trackBar1->Margin = System::Windows::Forms::Padding(4);
			this->trackBar1->Maximum = 100000;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(217, 45);
			this->trackBar1->TabIndex = 2;
			this->trackBar1->Value = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(35, 45);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Amount of Websites";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(36, 101);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Total Visits";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->textBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox1->Location = System::Drawing::Point(241, 101);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(216, 22);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"100000";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(35, 201);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Visit Distribution";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(239, 201);
			this->radioButton1->Margin = System::Windows::Forms::Padding(4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(71, 20);
			this->radioButton1->TabIndex = 8;
			this->radioButton1->Text = L"Uniform";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(379, 201);
			this->radioButton2->Margin = System::Windows::Forms::Padding(4);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(69, 20);
			this->radioButton2->TabIndex = 9;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Normal";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->progressBar1);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->webCounter);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->groupBox1->Location = System::Drawing::Point(32, 76);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(521, 326);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Simulation Settings";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->textBox2->Location = System::Drawing::Point(241, 150);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(216, 22);
			this->textBox2->TabIndex = 16;
			this->textBox2->Text = L"1";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label14->Location = System::Drawing::Point(38, 150);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(155, 17);
			this->label14->TabIndex = 15;
			this->label14->Text = L"Standard Deviation (%)";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(215, 247);
			this->progressBar1->Margin = System::Windows::Forms::Padding(4);
			this->progressBar1->MarqueeAnimationSpeed = 10;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(299, 39);
			this->progressBar1->TabIndex = 14;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button4->Location = System::Drawing::Point(39, 247);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(168, 39);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Prepare Simulation";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// webCounter
			// 
			this->webCounter->AutoSize = true;
			this->webCounter->Location = System::Drawing::Point(328, 25);
			this->webCounter->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->webCounter->Name = L"webCounter";
			this->webCounter->Size = System::Drawing::Size(14, 16);
			this->webCounter->TabIndex = 12;
			this->webCounter->Text = L"1";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(328, 34);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 16);
			this->label11->TabIndex = 11;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->runBtn);
			this->groupBox2->ForeColor = System::Drawing::SystemColors::Window;
			this->groupBox2->Location = System::Drawing::Point(605, 76);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(629, 326);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Simulation Controls";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(94, 178);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(129, 16);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Site Simulation Time";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(125, 104);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(98, 16);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Site Load Time";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(507, 178);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 16);
			this->label10->TabIndex = 11;
			this->label10->Text = L"0 ms";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(281, 178);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 16);
			this->label9->TabIndex = 10;
			this->label9->Text = L"0 ms";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(507, 104);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 16);
			this->label8->TabIndex = 9;
			this->label8->Text = L"0 ms";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(281, 104);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 16);
			this->label7->TabIndex = 8;
			this->label7->Text = L"0 ms";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label6->Location = System::Drawing::Point(485, 58);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 17);
			this->label6->TabIndex = 7;
			this->label6->Text = L"HashMap";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(264, 58);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 17);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Splay Tree";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->Location = System::Drawing::Point(342, 247);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(168, 39);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::SystemColors::Window;
			this->chart1->BackImageTransparentColor = System::Drawing::Color::Transparent;
			this->chart1->BackSecondaryColor = System::Drawing::Color::Transparent;
			this->chart1->BorderSkin->BackColor = System::Drawing::Color::DimGray;
			this->chart1->BorderSkin->PageColor = System::Drawing::Color::Transparent;
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(32, 410);
			this->chart1->Margin = System::Windows::Forms::Padding(4);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			this->chart1->PaletteCustomColors = gcnew cli::array< System::Drawing::Color >(2) { System::Drawing::Color::DeepSkyBlue, System::Drawing::Color::MediumSlateBlue };
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"Legend1";
			series3->Name = L"Splay Tree";
			series4->ChartArea = L"ChartArea1";
			series4->Legend = L"Legend1";
			series4->Name = L"HashMap";
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(1203, 369);
			this->chart1->TabIndex = 12;
			this->chart1->Text = L"chart1";
			title2->Name = L"Title1";
			this->chart1->Titles->Add(title2);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1317, 838);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::SystemColors::Window;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Project 3";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		ref struct ArgumentList {
			int websiteAmount;
			int visitAmount;
		};

	//Run simulaiton
	private: System::Void runBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hashmap simulation
		hashSim();

		//Splay tree simulation
		splaySim();

		//Create chart
		this->chart1->Series["HashMap"]->Points->AddXY("Load Time", int::Parse(label8->Text->Substring(0, label8->Text->Length-3)));
		this->chart1->Series["Splay Tree"]->Points->AddXY("Load Time", int::Parse(label7->Text->Substring(0, label7->Text->Length - 3)));

		this->chart1->Series["HashMap"]->Points->AddXY("Simulation Time", int::Parse(label10->Text->Substring(0, label10->Text->Length - 3)));
		this->chart1->Series["Splay Tree"]->Points->AddXY("Simulation Time", int::Parse(label9->Text->Substring(0, label9->Text->Length - 3)));
	}
	private: void hashSim() {
		//Data structure
		Hashmap myMap(120000);

		//TimerClock 
		TimerClock myTime;
		
		
		//Insert websites test
		myTime.reset(); //Start Timer
		for (int i = 0; i < websiteList->size(); i++) {
			myMap.insert(websiteList->at(i).first, websiteList->at(i).second);
		}
		label8->Text = myTime.elapsed() + " ms"; //Set elapsed time


		//Get sites test
		myTime.reset(); //Start Timer
		for (int i = 0; i < simulationList->size(); i++) {
			std::string url = simulationList->at(i).first;
			std::string ip = myMap.search(url);
			if (ip != simulationList->at(i).second) {
				label1->Text = "Error";
			}
		}
		label10->Text = myTime.elapsed() + " ms"; //Set elapsed time
	}
	private: void splaySim() {
		//Data structure
		SplayTree myTree;
		
		//TimerClock 
		TimerClock myTime;


		//Insert websites test
		myTime.reset(); //Start Timer
		for (int i = 0; i < websiteList->size(); i++) {
			myTree.insertHelp(websiteList->at(i).first, websiteList->at(i).second);
		}
		label7->Text = myTime.elapsed() + " ms"; //Set elapsed time


		//Get sites test
		myTime.reset(); //Start Timer
		for (int i = 0; i < simulationList->size(); i++) {
			std::string url = simulationList->at(i).first;
			std::string ip = myTree.Search(url);
			if (ip != simulationList->at(i).second) {
				label1->Text = "Error";
			}
		}
		label9->Text = myTime.elapsed() + " ms"; //Set elapsed time

		//Clear tree
		myTree.clearHelp();
	}
	//Amount of websites scroll bar
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		this->webCounter->Text = (this->trackBar1->Value.ToString());
	}
	//Prepare simulation
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//Get total visit amount from trackBar
		int websiteAmount = this->trackBar1->Value;
		int visitAmount = Int32::Parse(this->textBox1->Text);

		//Prepare arguments for background worker
		ArgumentList^ args = gcnew ArgumentList;
		args->websiteAmount = websiteAmount;
		args->visitAmount = visitAmount;
		
		//Prepare simulation in the background
		backgroundWorker1->RunWorkerAsync(args);
		
	}
	private: void countDistribution(std::unordered_map<std::string, int>& countMap, std::string url) {
		//If item exists -> add to count
		if (countMap.count(url) != 0) {
			countMap[url]++;
		}
		else {
			countMap.insert({ url,1 });
		}
	}
	private: void prepareSimulation(int websiteAmount, int visitAmount) {
		//Internally load websites from csv
		std::vector<std::pair<std::string, std::string>> webList;

		std::ifstream file("websiteData.csv");
		std::string tempLine;


		//counter to rearrange distribution- most popular site goes to middle
		int i = 0;
		int j = 0;
		int middle = websiteAmount / 2;
		bool left = false;

		//Allocate vector amount
		webList.resize(websiteAmount);
		while (getline(file, tempLine, '\n') && i < websiteAmount) {
			//Get url
			std::string url = tempLine.substr(0, tempLine.find(','));

			//Get ip
			std::string ip = tempLine.substr(tempLine.find(',') + 1, tempLine.size());

			//Store values in a pair
			std::pair<std::string, std::string> urlPair;
			urlPair.first = url;
			urlPair.second = ip;
			

			//Insert into global list
			websiteList->push_back(urlPair);

			//Insert into vector
			if (left) {
				webList.at(middle - j) = urlPair;
				left = false;
			}
			else {
				webList.at(middle + j) = urlPair;
				left = true;
				j++;
			}

			//Loading bar progress report
			double ratio = (double)(i+1) /websiteAmount;
			ratio *= 100;
			int percent = (int)ratio;
			if ((i+1) % (websiteAmount/10 +1) == 0) {
				backgroundWorker1->ReportProgress(percent / 2);
			}
			
			i++;
		}
		
		//Create distribution list
		//Uniform Distribution
		int minIndex = 0;
		int maxIndex = websiteAmount - 1;
		std::uniform_int_distribution<> uniformDist(minIndex, maxIndex);

		//Normal Distribution
		int mean = websiteAmount / 2;
		if (mean < 1) {
			mean = 1;
		}

		//Get standard deviation
		double percent = Double::Parse(this->textBox2->Text);
		percent /= 100;
		int standardDeviation = percent * websiteAmount;
		if (standardDeviation < 1) {
			standardDeviation = 1; //Clip value
		}
		std::default_random_engine generator;
		std::normal_distribution<double> normalDist(mean, standardDeviation);

		for (int i = 0; i < visitAmount; i++) {
			//Normal
			int index;
			if (this->radioButton2->Checked) {
				index = (normalDist(generator));
			}
			//Uniform
			else {
				index = (uniformDist(generator));
			}
			
			//Clip values to be in vector range
			if (index < 0) {
				index = 0;
			}
			else if (index > websiteAmount - 1) {
				index = websiteAmount - 1;
			}

			//Loading bar progress report
			double ratio = (double)(i + 1) / visitAmount;
			ratio *= 100;
			int percent = (int)ratio;
			if ((i+1) % (visitAmount / 10 +1) == 0) {
				backgroundWorker1->ReportProgress(50 + percent / 2);
			}
			

			//Add to simulation list
			simulationList->push_back(webList.at(index));
		}

		backgroundWorker1->ReportProgress(100);
	}
	private: System::String^ stringConvert(std::string input) {
		//std::string to System::String conversion https://learn.microsoft.com/en-us/cpp/dotnet/how-to-convert-standard-string-to-system-string?redirectedfrom=MSDN&view=msvc-170
		String^ out = gcnew String(input.c_str());
		return out;
	}
	private: void print(std::string input) {
		System::Diagnostics::Debug::Write(stringConvert(input));
	}
	private: void println(std::string input) {
		System::Diagnostics::Debug::WriteLine(stringConvert(input));
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		//Background worker https://www.sourcecodester.com/tutorials/cc/6583/c-tutorial-using-backgroundworker-component-ccli.html
		
		ArgumentList^ args = dynamic_cast<ArgumentList^>(e->Argument);
		prepareSimulation(args->websiteAmount, args->visitAmount);;
	}
	private: System::Void backgroundWorker1_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
		progressBar1->Value = (e->ProgressPercentage);// += e->ProgressPercentage;  //rising the progressbar's value

	}
	//Reset sim
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			websiteList->clear();
			simulationList->clear();
			label7->Text = "0 ms";
			label8->Text = "0 ms";
			label9->Text = "0 ms";
			label10->Text = "0 ms";
			progressBar1->Value = 0;
			this->chart1->Series["HashMap"]->Points->Clear();
			this->chart1->Series["Splay Tree"]->Points->Clear();

	}
	};
}
