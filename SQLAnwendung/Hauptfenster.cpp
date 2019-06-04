#include "Hauptfenster.h"


System::Void SQLAnwendung::Hauptfenster::button_DatenAnzeigen_Click(System::Object^  sender, System::EventArgs^  e)
{
	try
	{
		connection->Open();
		Console::WriteLine("Verbindung zur Datenbank wurde hergestellt");

		// 1. Sql String anlegen
		String^ sqlString = "SELECT * FROM TEILNEHMER";

		// 2. sql Befehlsobjekt anlegen
		SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, connection);

		// 3. Sql Befehlsobjket ausführen
		SqlDataReader^ dataReader = sqlCommand->ExecuteReader();

		textBox_Ausgabe->Text = "";

		int i = 0;

		// bei jedem knopfdruck werden, labels erzeugt und überlagert an den vorherigen
		// so kann es schnell zu 1000 ... labels kommen und das programm verlangsamen
		// deswegen einmal clearen
		panel_Ausgabe->Controls->Clear();


		// Werte der einzelnen Spalten anzeigen
		while (dataReader->Read())
		{
			textBox_Ausgabe->Text += dataReader["Id"] + ": ";

			Label^ label_Id = gcnew Label;
			label_Id->Text = dataReader["Id"]->ToString();
			label_Id->BackColor = Color::White;
			label_Id->Size = System::Drawing::Size(40, 20);
			label_Id->Location = System::Drawing::Point(0, i*20);
			panel_Ausgabe->Controls->Add(label_Id);	// in das Panel einfügen


			
			textBox_Ausgabe->Text += dataReader["Vorname"] + ", ";

			Label^ label_Vorname = gcnew Label;
			label_Vorname->Text = dataReader["Vorname"]->ToString();
			label_Vorname->BackColor = Color::White;
			label_Vorname->Size = System::Drawing::Size(100, 20);
			label_Vorname->Location = System::Drawing::Point(40, i*20);
			panel_Ausgabe->Controls->Add(label_Vorname);	// in das Panel einfügen



			textBox_Ausgabe->Text += dataReader["Nachname"] + ", ";

			Label^ label_Nachname = gcnew Label;
			label_Nachname->Text = dataReader["Nachname"]->ToString();
			label_Nachname->BackColor = Color::White;
			label_Nachname->Size = System::Drawing::Size(100, 20);
			label_Nachname->Location = System::Drawing::Point(140, i * 20);
			panel_Ausgabe->Controls->Add(label_Nachname);	// in das Panel einfügen
					


			textBox_Ausgabe->Text += dataReader["Standort"] + Environment::NewLine;
		
			Label^ label_Standort = gcnew Label;
			label_Standort->Text = dataReader["Standort"]->ToString();
			label_Standort->BackColor = Color::White;
			label_Standort->Size = System::Drawing::Size(100, 20);
			label_Standort->Location = System::Drawing::Point(240, i * 20);
			panel_Ausgabe->Controls->Add(label_Standort);	// in das Panel einfügen
		
			i++;
		}
		dataReader->Close();
	}
	catch (Exception^ exceptionOpen)
	{
		Console::WriteLine("Verbindung konnte nicht hergestellt werden" + Environment::NewLine);
		Console::WriteLine(exceptionOpen);
	}


	try
	{
		connection->Close();
		Console::WriteLine("Verbindung zur Datenbank wurde geschlossen");
	}
	catch (Exception^ exceptionClose)
	{
		Console::WriteLine("Verbindung zur Datenbank konnte nicht geschlossen werden");
	}
}



System::Void SQLAnwendung::Hauptfenster::button_TeilnehmerHinzufuegen_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ id = textBox_Id->Text;
	String^ nachname = textBox_Nachname->Text;
	String^ vorname = textBox_Vorname->Text;
	String^ standort = textBox_Standort->Text;
	bool idExistiert = false;

	try
	{
		connection->Open();
		Console::WriteLine("Verbindung zur Datenbank wurde hergestellt");

		if ((id != "") && (nachname != "") && (vorname != "") && (standort != ""))
		{
			String^ sqlString = "SELECT * FROM TEILNEHMER";

			// 2. sql Befehlsobjekt anlegen
			SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, connection);

			// 3. Sql Befehlsobjket ausführen
			SqlDataReader^ dataReader = sqlCommand->ExecuteReader();

			// Werte der einzelnen Spalten anzeigen
			while (dataReader->Read())
			{
				if (id == dataReader["Id"]->ToString())
				{
					idExistiert = true;
				}
			}
			dataReader->Close();

			//idexestiert = false;
			if (!idExistiert)
			{
				// 1. Sql String anlegen
				String^ sqlString2 = "INSERT INTO Teilnehmer(Id,Vorname, Nachname, Standort) VALUES (" + id + ",' " + vorname + "', '" + nachname + "', '" + standort + "')";

				// 2. sql Befehlsobjekt anlegen
				SqlCommand^ sqlCommand2 = gcnew SqlCommand(sqlString2, connection);

				// 3. Sql Befehlsobjket ausführen
				sqlCommand2->ExecuteNonQuery();
			}
			else
			{
				Console::WriteLine("Id bereits vorhanden");
				MessageBox::Show("Id bereits vorhanden");
			}
		}
		else
		{
			Console::WriteLine("Bitte alle Felder ausfüllen");
			MessageBox::Show("Bitte alle Felder ausfüllen");
		}
	}
	catch (Exception^ exceptionOpen)
	{
		Console::WriteLine("Verbindung konnte nicht hergestellt werden" + Environment::NewLine);
		Console::WriteLine(exceptionOpen);
	}


	try
	{
		connection->Close();
		Console::WriteLine("Verbindung zur Datenbank wurde geschlossen");
	}
	catch (Exception^ exceptionClose)
	{
		Console::WriteLine("Verbindung zur Datenbank konnte nicht geschlossen werden");
	}

	// Ausgabe Liste einmal refreshen
	button_DatenAnzeigen->PerformClick();
}