#pragma once

#include<map>
#include"Tree.cpp"
#include "TreeDetailForm.h"


Forest coniferous("Ufa", "coniferous", 0.2);//хвойный
Forest foliar("Russia", "foliar", 0.3);//лиственный


std::ostream& operator << (std::ostream& os, const Forest&forest){
	os<<"расположение "<<forest.location<<std::endl;
	os<<"тип "<<forest.type<<std::endl;
	os<<"пожароопасность "<<forest.fireDanger<<std::endl;
	return os;
}

//вывод дерева в консоль
std::ostream& operator << (std::ostream& os, const Tree&tree){
	os<<"Тип: \'coniferous\' - хвойный \'foliar\' - лиственный"<<std::endl;

	if( coniferous==tree.kind){
		os<<"coniferous"<<std::endl;
	}
	if(foliar==tree.kind){
		os<<"foliar"<<std::endl;
	}

	os<<"Высота"<<std::endl;
	os<<tree.height<<std::endl;

	os<<"Толщина"<<std::endl;
	os<<tree.thickness<<std::endl;


	os<<"Есть ли в дереве дупла (\'Y\' или \'N\')"<<std::endl;

	if(tree.hasHollow){
		os<<"Y"<<std::endl;
	}else{
		os<<"N"<<std::endl;
	}	

	os<<"Площадь отбрасываемой тени"<<std::endl;
	os<<tree.shadowSquare<<std::endl;

	return os;
}

//вывод дерева в файл
std::ofstream& operator << (std::ofstream& ofs, const Tree&tree){
	ofs<<"Тип: \'coniferous\' - хвойный \'foliar\' - лиственный"<<std::endl;

	if( coniferous==tree.kind){
		ofs<<"coniferous"<<std::endl;
	}
	if(foliar==tree.kind){
		ofs<<"foliar"<<std::endl;
	}

	ofs<<"Высота"<<std::endl;
	ofs<<tree.height<<std::endl;

	ofs<<"Толщина"<<std::endl;
	ofs<<tree.thickness<<std::endl;


	ofs<<"Есть ли в дереве дупла (\'Y\' или \'N\')"<<std::endl;

	if(tree.hasHollow){
		ofs<<"Y"<<std::endl;
	}else{
		ofs<<"N"<<std::endl;
	}	

	ofs<<"Площадь отбрасываемой тени"<<std::endl;
	ofs<<tree.shadowSquare<<std::endl;

	return ofs;
}



std::istream& operator >> (std::istream& is, Tree& tree){
	std::string kind;
	while(kind!="coniferous" && kind!="foliar"){
		std::cout<<"Введите тип: \'coniferous\' - хвойный \'foliar\' - лиственный"<<std::endl;
		is>>kind;
		if(kind=="coniferous"){
			tree.kind=coniferous;
		}
		if(kind=="foliar"){
			tree.kind=foliar;
		}
	}
	std::cout<<"Введите высоту"<<std::endl;
	is>>tree.height;

	std::cout<<"Введите толщину"<<std::endl;
	is>>tree.thickness;

	std::string hasHollow;
	while(hasHollow!="Y" && hasHollow!="N"){
		std::cout<<"Введите есть ли в дереве дупла (\'Y\' или \'N\')"<<std::endl;
		is>>hasHollow;

		if(hasHollow=="Y"){
			tree.hasHollow = true;
		}
		if(hasHollow=="N"){
			tree.hasHollow = false;
		}
	}

	std::cout<<"Введите площадь отбрасываемой тени"<<std::endl;
	is >> tree.shadowSquare;
	return is;
}

std::ifstream& operator >> (std::ifstream& is, Tree& tree){
	std::string kind;
	std::string header;
	getline(is, header);
	getline(is, header);//пропускаем заголовки
	getline(is, kind);
	if(kind=="coniferous"){
		tree.kind=coniferous;
	}
	if(kind=="foliar"){
		tree.kind=foliar;
	}

	getline(is, header);//пропускаем заголовки
	is>>tree.height;

	getline(is, header);//пропускаем заголовки
	getline(is, header);//пропускаем заголовки
	is>>tree.thickness;

	getline(is, header);//пропускаем заголовки
	std::string hasHollow;

	getline(is, header);//пропускаем заголовки
	is>>hasHollow;

	if(hasHollow=="Y"){
		tree.hasHollow = true;
	}
	if(hasHollow=="N"){
		tree.hasHollow = false;
	}

	getline(is, header);//пропускаем заголовки
	getline(is, header);//пропускаем заголовки
	is >> tree.shadowSquare;
	return is;
}


Tree* readFromFile(std::string filename, int *treesCount, Tree* trees){

	if((*treesCount)>0){
		delete[] trees;
	}

	std::ifstream ifs(filename);
	ifs>>*treesCount;
	trees = new Tree[(*treesCount)];
	for(int i =0; i< (*treesCount); ++i){
		ifs>>trees[i];
	}
	return trees;
}


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

		Forest* choices;

		Tree* trees;
int *treesCount;

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->treesCount = new int(0);
			this->choices = new Forest[2];
			choices[0] = foliar;
			choices[1] = coniferous;

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

	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  kind;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  height;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  thickness;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  hasHollow;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  shadowSquare;
	private: System::Windows::Forms::Button^  addButton;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ComboBox^  sortType;
	private: System::Windows::Forms::ComboBox^  searchField;
	private: System::Windows::Forms::NumericUpDown^  searchValue;

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
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->kind = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->height = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->thickness = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->hasHollow = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->shadowSquare = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->sortType = (gcnew System::Windows::Forms::ComboBox());
			this->searchField = (gcnew System::Windows::Forms::ComboBox());
			this->searchValue = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->searchValue))->BeginInit();
			this->SuspendLayout();
			// 
			// btnInput
			// 
			this->btnInput->Location = System::Drawing::Point(23, 12);
			this->btnInput->Name = L"btnInput";
			this->btnInput->Size = System::Drawing::Size(91, 41);
			this->btnInput->TabIndex = 0;
			this->btnInput->Text = L"Ввод из файла";
			this->btnInput->UseVisualStyleBackColor = true;
			this->btnInput->Click += gcnew System::EventHandler(this, &Form1::btnInput_Click);
			// 
			// btnSort
			// 
			this->btnSort->Location = System::Drawing::Point(23, 133);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(92, 38);
			this->btnSort->TabIndex = 1;
			this->btnSort->Text = L"Сортировка";
			this->btnSort->UseVisualStyleBackColor = true;
			this->btnSort->Click += gcnew System::EventHandler(this, &Form1::btnSort_Click);
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(24, 196);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(91, 34);
			this->btnSearch->TabIndex = 2;
			this->btnSearch->Text = L"Поиск";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &Form1::btnSearch_Click);
			// 
			// btnChange
			// 
			this->btnChange->Location = System::Drawing::Point(22, 236);
			this->btnChange->Name = L"btnChange";
			this->btnChange->Size = System::Drawing::Size(91, 32);
			this->btnChange->TabIndex = 3;
			this->btnChange->Text = L"Изменить";
			this->btnChange->UseVisualStyleBackColor = true;
			this->btnChange->Click += gcnew System::EventHandler(this, &Form1::btnChange_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->Location = System::Drawing::Point(22, 275);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(91, 32);
			this->btnRemove->TabIndex = 4;
			this->btnRemove->Text = L"Удалить";
			this->btnRemove->UseVisualStyleBackColor = true;
			this->btnRemove->Click += gcnew System::EventHandler(this, &Form1::btnRemove_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(23, 324);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(90, 27);
			this->btnClose->TabIndex = 6;
			this->btnClose->Text = L"Закрыть";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &Form1::btnClose_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->kind, this->height, 
				this->thickness, this->hasHollow, this->shadowSquare});
			this->dataGridView1->Location = System::Drawing::Point(337, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(452, 295);
			this->dataGridView1->TabIndex = 7;
			// 
			// kind
			// 
			this->kind->HeaderText = L"Лес";
			this->kind->Name = L"kind";
			this->kind->ReadOnly = true;
			// 
			// height
			// 
			this->height->HeaderText = L"Высота";
			this->height->Name = L"height";
			this->height->ReadOnly = true;
			// 
			// thickness
			// 
			this->thickness->HeaderText = L"Толщина";
			this->thickness->Name = L"thickness";
			this->thickness->ReadOnly = true;
			// 
			// hasHollow
			// 
			this->hasHollow->HeaderText = L"Есть дупло";
			this->hasHollow->Name = L"hasHollow";
			this->hasHollow->ReadOnly = true;
			// 
			// shadowSquare
			// 
			this->shadowSquare->HeaderText = L"Площадь тени";
			this->shadowSquare->Name = L"shadowSquare";
			this->shadowSquare->ReadOnly = true;
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(24, 73);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(88, 37);
			this->addButton->TabIndex = 8;
			this->addButton->Text = L"Добавить";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &Form1::addButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// sortType
			// 
			this->sortType->FormattingEnabled = true;
			this->sortType->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Высота", L"Толщина", L"Площадь тени"});
			this->sortType->Location = System::Drawing::Point(134, 133);
			this->sortType->Name = L"sortType";
			this->sortType->Size = System::Drawing::Size(102, 21);
			this->sortType->TabIndex = 9;
			// 
			// searchField
			// 
			this->searchField->FormattingEnabled = true;
			this->searchField->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Высота", L"Толщина", L"Площадь тени"});
			this->searchField->Location = System::Drawing::Point(134, 204);
			this->searchField->Name = L"searchField";
			this->searchField->Size = System::Drawing::Size(77, 21);
			this->searchField->TabIndex = 10;
			// 
			// searchValue
			// 
			this->searchValue->Location = System::Drawing::Point(239, 201);
			this->searchValue->Name = L"searchValue";
			this->searchValue->Size = System::Drawing::Size(71, 20);
			this->searchValue->TabIndex = 11;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(791, 417);
			this->Controls->Add(this->searchValue);
			this->Controls->Add(this->searchField);
			this->Controls->Add(this->sortType);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnRemove);
			this->Controls->Add(this->btnChange);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->btnSort);
			this->Controls->Add(this->btnInput);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->searchValue))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:


	private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void btnRemove_Click(System::Object^  sender, System::EventArgs^  e) {
				 for(int i =0; i<dataGridView1->SelectedRows->Count; i++){
					 int row = dataGridView1->SelectedRows[i]->Index;
					 removeFromArray(row);
				 }
				 refreshDataGridView();
			 }
	private: System::Void btnInput_Click(System::Object^  sender, System::EventArgs^  e) {
				 openFileDialog1->ShowDialog();
				 System::String^ path_f = openFileDialog1->FileName;

				 std::string vsSt= "";

				 for(int i = 0; i < path_f ->Length; i++)
					 vsSt += (char) path_f [i];
				 this->trees = readFromFile(vsSt, treesCount, this->trees);
				 refreshDataGridView();
			 }

			 void refreshDataGridView(){
				 dataGridView1->Rows->Clear();

				 for(int i = 0; i<*treesCount; i++){
					 String^ kind = gcnew String(trees[i].kind.type.c_str());
					 dataGridView1->Rows->Add(kind, trees[i].height, trees[i].thickness, trees[i].hasHollow, trees[i].shadowSquare);
				 }
			 }

			 void removeFromArray(int removed){
				 for(int i = removed; i<*treesCount-1; i++){
					 trees[i] = trees[i+1];
				 }
				 *treesCount--;
			 }

	private: System::Void btnChange_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(dataGridView1->SelectedRows->Count!=1){
					 return;
				 }
				 int editdIndex = dataGridView1->SelectedRows[0]->Index;
				 Tree edited = trees[editdIndex];


				 TreeDetailForm^ form = gcnew TreeDetailForm(editdIndex, choices, 2);

				 form->thicknessValue=edited.thickness;
				 form->heightValue=edited.height;
				 form->hasHollowValue=edited.hasHollow;
				 form->shadowSquareValue=edited.shadowSquare;


				 form->kindValue = gcnew System::String(edited.kind.type.c_str());


				 form->Show();
				 form->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::detailFormClose);

			 }

			 System::Void detailFormClose(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e){
				 TreeDetailForm^ form = (TreeDetailForm^)sender;
				 int index = form->index;

				 std::string kind= "";

				 for(int i = 0; i < (form->kindValue )->Length; i++)
					 kind += (char) (form->kindValue) [i];

				 if(index!=-1){
					 Tree& tree = trees[index];
					 tree.thickness=form->thicknessValue;
					 tree.height = form->heightValue;
					 tree.hasHollow=form->hasHollowValue;
					 tree.shadowSquare =form->shadowSquareValue;
					 if(kind=="coniferous"){
						 tree.kind=coniferous;
					 }
					 if(kind=="foliar"){
						 tree.kind=foliar;
					 }

				 }else{
					 Tree* newTrees = new Tree[(*treesCount)+1];
					 for(int i =0; i<*treesCount; i++){
						 newTrees[i] = trees[i];
					 }

					 

					 // delete[] trees;
					 trees = newTrees;


					 Tree& tree = trees[*treesCount];
					 tree.thickness=form->thicknessValue;
					 tree.height = form->heightValue;
					 tree.hasHollow=form->hasHollowValue;
					 tree.shadowSquare =form->shadowSquareValue;

					 if(kind=="coniferous"){
						 tree.kind=coniferous;
					 }
					 if(kind=="foliar"){
						 tree.kind=foliar;
					 }

					 (*treesCount)++;

				 }
				 refreshDataGridView();
			 }

	private: System::Void addButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 TreeDetailForm^ form = gcnew TreeDetailForm(-1, choices, 2);


				 form->Show();
				 form->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::detailFormClose);

			 }
	private: System::Void btnSort_Click(System::Object^  sender, System::EventArgs^  e) {
				 System::String^ selectedField = ( System::String^)this->sortType->SelectedItem;
				 
				 for(int i =0; i<*treesCount; i++){
					 for(int j=i+1; j<*treesCount; j++){

						 if(
							 (System::String::Equals(selectedField, "Высота") && trees[i].height>trees[j].height)||
							 (System::String::Equals(selectedField, "Толщина") && trees[i].thickness>trees[j].thickness)||
							( System::String::Equals(selectedField, "Площадь тени") && trees[i].shadowSquare>trees[j].shadowSquare)
							 )
						 {
							 Tree tmp = trees[i];
							 trees[i] = trees[j];
							 trees[j] = tmp;
						 }

					 }
				 }
				 refreshDataGridView();
			 }
private: System::Void btnSearch_Click(System::Object^  sender, System::EventArgs^  e) {
			 dataGridView1->ClearSelection();
			  System::String^ selectedField = ( System::String^)this->searchField->SelectedItem;
			  int searchValue = (int)(this->searchValue->Value);
				 
				 for(int i =0; i<*treesCount; i++){

						 if(
							 (System::String::Equals(selectedField, "Высота") && trees[i].height==searchValue)||
							 (System::String::Equals(selectedField, "Толщина") && trees[i].thickness==searchValue)||
							( System::String::Equals(selectedField, "Площадь тени") && trees[i].shadowSquare==searchValue)
							 )
						 {
							 dataGridView1->Rows[i]->Selected = true;
						 }

				 }
		 }
};



}

