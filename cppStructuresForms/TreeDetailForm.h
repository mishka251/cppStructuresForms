#pragma once
#include<map>
#include"Tree.cpp"
namespace cppStructuresForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for TreeDetailForm
	/// </summary>
	public ref class TreeDetailForm : public System::Windows::Forms::Form
	{
	public:
		Forest* typeChoices;
		int choicesCount;
		int index;

		 property System::String^ kindValue
			{
				System::String^ get()
				{
					return (System::String^)kind->SelectedItem;
				}
				void set(System::String^ text)
				{
					kind->SelectedItem = text;
				}
			}

		 property int thicknessValue
			{
				int get()
				{
					return (int)thickness->Value;
				}
				void set(int value)
				{
					thickness->Value = value;
				}
			}

		 property int shadowSquareValue
			{
				int get()
				{
					return (int)shadowSquare->Value;
				}
				void set(int value)
				{
					shadowSquare->Value = value;
				}
			}

		 property double heightValue
			{
				double get()
				{
					return (double)height->Value;
				}
				void set(double value)
				{
					height->Value = Decimal(value);
				}
			}

		 property bool hasHollowValue
			{
				bool get()
				{
					return hasHollow->Checked;
				}
				void set(bool value)
				{
					hasHollow->Checked = value;
				}
			}

		TreeDetailForm(int index, Forest* choices, int choicesCount)
		{
			this->index = index;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			for(int i =0; i<choicesCount; i++){					
				kind->Items->Add(gcnew String(choices[i].type.c_str()));
			}			
			
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TreeDetailForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  kind;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  height;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  thickness;
	private: System::Windows::Forms::CheckBox^  hasHollow;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  shadowSquare;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->kind = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->height = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->thickness = (gcnew System::Windows::Forms::NumericUpDown());
			this->hasHollow = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->shadowSquare = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->height))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->thickness))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->shadowSquare))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(31, 202);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Отмена";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TreeDetailForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(149, 202);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 33);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ок";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TreeDetailForm::button2_Click);
			// 
			// kind
			// 
			this->kind->FormattingEnabled = true;
			this->kind->Location = System::Drawing::Point(156, 12);
			this->kind->Name = L"kind";
			this->kind->Size = System::Drawing::Size(117, 21);
			this->kind->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Вид леса";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Высота";
			// 
			// height
			// 
			this->height->Location = System::Drawing::Point(149, 46);
			this->height->Name = L"height";
			this->height->Size = System::Drawing::Size(123, 20);
			this->height->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"толщина";
			// 
			// thickness
			// 
			this->thickness->Location = System::Drawing::Point(147, 83);
			this->thickness->Name = L"thickness";
			this->thickness->Size = System::Drawing::Size(124, 20);
			this->thickness->TabIndex = 7;
			// 
			// hasHollow
			// 
			this->hasHollow->AutoSize = true;
			this->hasHollow->Location = System::Drawing::Point(22, 115);
			this->hasHollow->Name = L"hasHollow";
			this->hasHollow->Size = System::Drawing::Size(101, 17);
			this->hasHollow->TabIndex = 9;
			this->hasHollow->Text = L"Наличие дупла";
			this->hasHollow->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 154);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Тень";
			// 
			// shadowSquare
			// 
			this->shadowSquare->Location = System::Drawing::Point(132, 155);
			this->shadowSquare->Name = L"shadowSquare";
			this->shadowSquare->Size = System::Drawing::Size(140, 20);
			this->shadowSquare->TabIndex = 11;
			// 
			// TreeDetailForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(458, 261);
			this->Controls->Add(this->shadowSquare);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->hasHollow);
			this->Controls->Add(this->thickness);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->height);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->kind);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"TreeDetailForm";
			this->Text = L"TreeDetailForm";
			this->Load += gcnew System::EventHandler(this, &TreeDetailForm::TreeDetailForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->height))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->thickness))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->shadowSquare))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
	private: System::Void TreeDetailForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
