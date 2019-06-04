#pragma once

namespace SQLAnwendung {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Data::SqlClient;



	/// <summary>
	/// Zusammenfassung für Hauptfenster
	/// </summary>
	public ref class Hauptfenster : public System::Windows::Forms::Form
	{
	public:
		Hauptfenster(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//

			// Verbindungzeichenfolge zusammenbauen
			String^ filePath = System::IO::Directory::GetCurrentDirectory();
			connectionString =
				"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=" +
				filePath +
				"\\Datenbank.mdf;Integrated Security=True;Connect Timeout=30";

			// Verbindungsobjekt initialisieren
			connection = gcnew SqlConnection();

			try
			{
				connection->ConnectionString = connectionString;
			}
			catch (Exception^ ausnahme1)
			{
				Console::WriteLine("Verbindung konnte nicht hergestellt werden");
			}



		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Hauptfenster()
		{
			if (components)
			{
				delete components;
			}
		}

		// eigene Attribute
		String^ connectionString;
		SqlConnection^ connection;


		// Eigenschaften, die das Studio anlegt bei Benutzung des Designers
		
	private: System::Windows::Forms::Button^  button_DatenAnzeigen;
	protected:
	private: System::Windows::Forms::TextBox^  textBox_Ausgabe;


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Hauptfenster::typeid));
			this->button_DatenAnzeigen = (gcnew System::Windows::Forms::Button());
			this->textBox_Ausgabe = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button_DatenAnzeigen
			// 
			this->button_DatenAnzeigen->Location = System::Drawing::Point(527, 12);
			this->button_DatenAnzeigen->Name = L"button_DatenAnzeigen";
			this->button_DatenAnzeigen->Size = System::Drawing::Size(123, 23);
			this->button_DatenAnzeigen->TabIndex = 0;
			this->button_DatenAnzeigen->Text = L"Daten anzeigen";
			this->button_DatenAnzeigen->UseVisualStyleBackColor = true;
			this->button_DatenAnzeigen->Click += gcnew System::EventHandler(this, &Hauptfenster::button_DatenAnzeigen_Click);
			// 
			// textBox_Ausgabe
			// 
			this->textBox_Ausgabe->Location = System::Drawing::Point(12, 12);
			this->textBox_Ausgabe->Multiline = true;
			this->textBox_Ausgabe->Name = L"textBox_Ausgabe";
			this->textBox_Ausgabe->Size = System::Drawing::Size(509, 403);
			this->textBox_Ausgabe->TabIndex = 1;
			// 
			// Hauptfenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1109, 642);
			this->Controls->Add(this->textBox_Ausgabe);
			this->Controls->Add(this->button_DatenAnzeigen);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Hauptfenster";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SQLAnwendung";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_DatenAnzeigen_Click(System::Object^  sender, System::EventArgs^  e);



	};
}
