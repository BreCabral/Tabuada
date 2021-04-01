#pragma once

namespace Tabuada {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgTabuada;
	protected:

	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btCalcular;
	private: System::Windows::Forms::TextBox^ tbNumero;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Multiplicador;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Resultado;



	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgTabuada = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btCalcular = (gcnew System::Windows::Forms::Button());
			this->tbNumero = (gcnew System::Windows::Forms::TextBox());
			this->Multiplicador = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Resultado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgTabuada))->BeginInit();
			this->SuspendLayout();
			// 
			// dgTabuada
			// 
			this->dgTabuada->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgTabuada->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Multiplicador,
					this->Resultado
			});
			this->dgTabuada->Location = System::Drawing::Point(12, 84);
			this->dgTabuada->Name = L"dgTabuada";
			this->dgTabuada->Size = System::Drawing::Size(244, 284);
			this->dgTabuada->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Digite o numero:";
			// 
			// btCalcular
			// 
			this->btCalcular->Location = System::Drawing::Point(12, 55);
			this->btCalcular->Name = L"btCalcular";
			this->btCalcular->Size = System::Drawing::Size(75, 23);
			this->btCalcular->TabIndex = 2;
			this->btCalcular->Text = L"Calcular";
			this->btCalcular->UseVisualStyleBackColor = true;
			this->btCalcular->Click += gcnew System::EventHandler(this, &MyForm::btCalcular_Click);
			// 
			// tbNumero
			// 
			this->tbNumero->Location = System::Drawing::Point(12, 29);
			this->tbNumero->Name = L"tbNumero";
			this->tbNumero->Size = System::Drawing::Size(100, 20);
			this->tbNumero->TabIndex = 3;
			// 
			// Multiplicador
			// 
			this->Multiplicador->HeaderText = L"Numero Escolhido Vezes:";
			this->Multiplicador->Name = L"Multiplicador";
			// 
			// Resultado
			// 
			this->Resultado->HeaderText = L"Igual";
			this->Resultado->Name = L"Resultado";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(265, 381);
			this->Controls->Add(this->tbNumero);
			this->Controls->Add(this->btCalcular);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgTabuada);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgTabuada))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btCalcular_Click(System::Object^ sender, System::EventArgs^ e) {
		// Essa parte era pra apagar a ultima ultilização porem so funciona se o usuario nao clicar em outra linha
		int controle = dgTabuada->CurrentRow->Index;
		while (controle > 0)
		{
			controle--;
			dgTabuada->Rows->RemoveAt(controle);
		}
		//
		double numero;
		try
		{
			numero = Convert::ToDouble(tbNumero->Text);
		}
		catch (...)
		{
			MessageBox::Show("Numero Invalido", "ERRO");
			return;
		}
		for (int i = 0; i < 10; i++) {
			dgTabuada->Rows->Add(i + 1, (i + 1) * numero);
		}
	}
};
}
