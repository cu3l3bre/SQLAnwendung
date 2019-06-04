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
	private: System::Windows::Forms::TextBox^  textBox_Id;
	private: System::Windows::Forms::TextBox^  textBox_Nachname;
	private: System::Windows::Forms::TextBox^  textBox_Vorname;
	private: System::Windows::Forms::TextBox^  textBox_Standort;

	private: System::Windows::Forms::Label^  label_Id;
	private: System::Windows::Forms::Label^  label_Nachname;
	private: System::Windows::Forms::Label^  label_Vorname;
	private: System::Windows::Forms::Label^  label_Standort;
	private: System::Windows::Forms::Button^  button_TeilnehmerHinzufuegen;
	private: System::Windows::Forms::Panel^  panel_Ausgabe;



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
			this->textBox_Id = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Nachname = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Vorname = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Standort = (gcnew System::Windows::Forms::TextBox());
			this->label_Id = (gcnew System::Windows::Forms::Label());
			this->label_Nachname = (gcnew System::Windows::Forms::Label());
			this->label_Vorname = (gcnew System::Windows::Forms::Label());
			this->label_Standort = (gcnew System::Windows::Forms::Label());
			this->button_TeilnehmerHinzufuegen = (gcnew System::Windows::Forms::Button());
			this->panel_Ausgabe = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button_DatenAnzeigen
			// 
			this->button_DatenAnzeigen->Location = System::Drawing::Point(544, 12);
			this->button_DatenAnzeigen->Name = L"button_DatenAnzeigen";
			this->button_DatenAnzeigen->Size = System::Drawing::Size(140, 23);
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
			this->textBox_Ausgabe->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox_Ausgabe->Size = System::Drawing::Size(508, 287);
			this->textBox_Ausgabe->TabIndex = 1;
			// 
			// textBox_Id
			// 
			this->textBox_Id->Location = System::Drawing::Point(544, 67);
			this->textBox_Id->Name = L"textBox_Id";
			this->textBox_Id->Size = System::Drawing::Size(140, 20);
			this->textBox_Id->TabIndex = 2;
			// 
			// textBox_Nachname
			// 
			this->textBox_Nachname->Location = System::Drawing::Point(544, 122);
			this->textBox_Nachname->Name = L"textBox_Nachname";
			this->textBox_Nachname->Size = System::Drawing::Size(140, 20);
			this->textBox_Nachname->TabIndex = 3;
			// 
			// textBox_Vorname
			// 
			this->textBox_Vorname->Location = System::Drawing::Point(544, 178);
			this->textBox_Vorname->Name = L"textBox_Vorname";
			this->textBox_Vorname->Size = System::Drawing::Size(140, 20);
			this->textBox_Vorname->TabIndex = 4;
			// 
			// textBox_Standort
			// 
			this->textBox_Standort->Location = System::Drawing::Point(544, 240);
			this->textBox_Standort->Name = L"textBox_Standort";
			this->textBox_Standort->Size = System::Drawing::Size(140, 20);
			this->textBox_Standort->TabIndex = 5;
			// 
			// label_Id
			// 
			this->label_Id->AutoSize = true;
			this->label_Id->Location = System::Drawing::Point(544, 51);
			this->label_Id->Name = L"label_Id";
			this->label_Id->Size = System::Drawing::Size(19, 13);
			this->label_Id->TabIndex = 6;
			this->label_Id->Text = L"Id:";
			// 
			// label_Nachname
			// 
			this->label_Nachname->AutoSize = true;
			this->label_Nachname->Location = System::Drawing::Point(544, 106);
			this->label_Nachname->Name = L"label_Nachname";
			this->label_Nachname->Size = System::Drawing::Size(62, 13);
			this->label_Nachname->TabIndex = 7;
			this->label_Nachname->Text = L"Nachname:";
			// 
			// label_Vorname
			// 
			this->label_Vorname->AutoSize = true;
			this->label_Vorname->Location = System::Drawing::Point(544, 162);
			this->label_Vorname->Name = L"label_Vorname";
			this->label_Vorname->Size = System::Drawing::Size(52, 13);
			this->label_Vorname->TabIndex = 8;
			this->label_Vorname->Text = L"Vorname:";
			// 
			// label_Standort
			// 
			this->label_Standort->AutoSize = true;
			this->label_Standort->Location = System::Drawing::Point(544, 224);
			this->label_Standort->Name = L"label_Standort";
			this->label_Standort->Size = System::Drawing::Size(47, 13);
			this->label_Standort->TabIndex = 9;
			this->label_Standort->Text = L"Standort";
			// 
			// button_TeilnehmerHinzufuegen
			// 
			this->button_TeilnehmerHinzufuegen->Location = System::Drawing::Point(544, 276);
			this->button_TeilnehmerHinzufuegen->Name = L"button_TeilnehmerHinzufuegen";
			this->button_TeilnehmerHinzufuegen->Size = System::Drawing::Size(140, 23);
			this->button_TeilnehmerHinzufuegen->TabIndex = 10;
			this->button_TeilnehmerHinzufuegen->Text = L"Teilnehmer hinzufuegen";
			this->button_TeilnehmerHinzufuegen->UseVisualStyleBackColor = true;
			this->button_TeilnehmerHinzufuegen->Click += gcnew System::EventHandler(this, &Hauptfenster::button_TeilnehmerHinzufuegen_Click);
			// 
			// panel_Ausgabe
			// 
			this->panel_Ausgabe->AutoScroll = true;
			this->panel_Ausgabe->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Ausgabe->Location = System::Drawing::Point(12, 343);
			this->panel_Ausgabe->Name = L"panel_Ausgabe";
			this->panel_Ausgabe->Size = System::Drawing::Size(508, 287);
			this->panel_Ausgabe->TabIndex = 11;
			// 
			// Hauptfenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1109, 642);
			this->Controls->Add(this->panel_Ausgabe);
			this->Controls->Add(this->button_TeilnehmerHinzufuegen);
			this->Controls->Add(this->label_Standort);
			this->Controls->Add(this->label_Vorname);
			this->Controls->Add(this->label_Nachname);
			this->Controls->Add(this->label_Id);
			this->Controls->Add(this->textBox_Standort);
			this->Controls->Add(this->textBox_Vorname);
			this->Controls->Add(this->textBox_Nachname);
			this->Controls->Add(this->textBox_Id);
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



	private: System::Void button_TeilnehmerHinzufuegen_Click(System::Object^  sender, System::EventArgs^  e);
};
}
