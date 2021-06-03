#pragma once

namespace cppStructuresForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnInput;
	protected: 
	private: System::Windows::Forms::Button^  btnSort;
	private: System::Windows::Forms::Button^  btnSearch;
	private: System::Windows::Forms::Button^  btnChange;
	private: System::Windows::Forms::Button^  btnRemove;
	private: System::Windows::Forms::Button^  btnShow;
	private: System::Windows::Forms::Button^  btnClose;

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
			this->btnInput = (gcnew System::Windows::Forms::Button());
			this->btnSort = (gcnew System::Windows::Forms::Button());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnChange = (gcnew System::Windows::Forms::Button());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->btnShow = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnInput
			// 
			this->btnInput->Location = System::Drawing::Point(23, 12);
			this->btnInput->Name = L"btnInput";
			this->btnInput->Size = System::Drawing::Size(91, 41);
			this->btnInput->TabIndex = 0;
			this->btnInput->Text = L"Ввод";
			this->btnInput->UseVisualStyleBackColor = true;
			// 
			// btnSort
			// 
			this->btnSort->Location = System::Drawing::Point(23, 74);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(92, 38);
			this->btnSort->TabIndex = 1;
			this->btnSort->Text = L"Сортировка";
			this->btnSort->UseVisualStyleBackColor = true;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(23, 135);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(91, 34);
			this->btnSearch->TabIndex = 2;
			this->btnSearch->Text = L"Поиск";
			this->btnSearch->UseVisualStyleBackColor = true;
			// 
			// btnChange
			// 
			this->btnChange->Location = System::Drawing::Point(23, 187);
			this->btnChange->Name = L"btnChange";
			this->btnChange->Size = System::Drawing::Size(91, 32);
			this->btnChange->TabIndex = 3;
			this->btnChange->Text = L"Изменить";
			this->btnChange->UseVisualStyleBackColor = true;
			// 
			// btnRemove
			// 
			this->btnRemove->Location = System::Drawing::Point(23, 237);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(91, 32);
			this->btnRemove->TabIndex = 4;
			this->btnRemove->Text = L"Удалить";
			this->btnRemove->UseVisualStyleBackColor = true;
			// 
			// btnShow
			// 
			this->btnShow->Location = System::Drawing::Point(23, 275);
			this->btnShow->Name = L"btnShow";
			this->btnShow->Size = System::Drawing::Size(92, 34);
			this->btnShow->TabIndex = 5;
			this->btnShow->Text = L"Просмотреть";
			this->btnShow->UseVisualStyleBackColor = true;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(24, 315);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(90, 27);
			this->btnClose->TabIndex = 6;
			this->btnClose->Text = L"Закрыть";
			this->btnClose->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(395, 417);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnShow);
			this->Controls->Add(this->btnRemove);
			this->Controls->Add(this->btnChange);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->btnSort);
			this->Controls->Add(this->btnInput);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

