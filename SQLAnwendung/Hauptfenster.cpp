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

		// Werte der einzelnen Spalten anzeigen
		while (dataReader->Read())
		{
			textBox_Ausgabe->Text += dataReader["Id"]->ToString() + ": ";
			textBox_Ausgabe->Text += dataReader["Nachname"]->ToString() + ", ";
			textBox_Ausgabe->Text += dataReader["Vorname"]->ToString() + ", ";
			textBox_Ausgabe->Text += dataReader["Standort"]->ToString() + Environment::NewLine;
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

}