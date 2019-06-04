#include <iostream>
#include "Hauptfenster.h"


using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;


int main()
{

	// Objekt der Klasse Hauptfenster anlegen und im Anschluss ausführen
	SQLAnwendung::Hauptfenster^ fenster1 = gcnew SQLAnwendung::Hauptfenster;
	System::Windows::Forms::Application::Run(fenster1);





	/*Console::WriteLine("Programm zu SQLAnwendung" + Environment::NewLine);*/

	// Verbindung zur Datenbank herstellen


	// Verbindungs Zeichenfolge - connectionString (auf die backslashes achten \\)
//	String^ connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\Alfa\\source\\repos\\SQLAnwendung\\SQLAnwendung\\Datenbank.mdf;Integrated Security=True;Connect Timeout=30";


	// der aktuelle Pfad:
	// - beim starten aus dem Programm heraus (Debug), wäre das der pfad wo die main liegt
	// - wenn ich die exe benutze, den pfad der exe, dh, ich muss die datenbank dateien vorher dahin kopieren, wo die exe liegt
	
	
	/*
	String^ filePath = System::IO::Directory::GetCurrentDirectory();
	String^ connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=" + filePath + "\\Datenbank.mdf;Integrated Security=True;Connect Timeout=30";
	Console::WriteLine(filePath);
	*/

	// Verbindung vorbereiten

	/*
	SqlConnection^ connection = gcnew SqlConnection();
	
	try
	{
		connection->ConnectionString = connectionString;
	}
	catch (Exception^ ausnahme1)
	{
		Console::WriteLine("Verbindung konnte nicht hergestellt werden, falsche Syntax beim Verbindungsstring?");
	}
	*/
	

	/*
	try
	{
		// Verbindung herstellen
		connection->Open();
		Console::WriteLine("Verbindung erfolgreich hergstellt");

		// --------------------------------------------------------------------------------------------
		// --------------------------------------------------------------------------------------------
		// SQL Befehlskategorie A - mit genau einem Ergebnis als Rückgabe

		// 1. SQL-Befehlszeichenfolge angeben - Anzahl der Teilnehmer
		String^ sqlCommandString = "SELECT COUNT(*) FROM Teilnehmer";

		// 2. SQL Befehlsobjekt erzeugen
		// im Konstruktor gleich Befehlszeichenfolge und Verbindung angeben
		SqlCommand^ sqlCommand = gcnew SqlCommand(sqlCommandString, connection);

		// 3. SQL Befehl ausführen
		int anzahl = Convert::ToInt32(sqlCommand->ExecuteScalar());
		Console::WriteLine("Anzahl der Teilnehmer: " + anzahl.ToString());

		// --------------------------------------------------------------------------------------------

		// 1. SQL Command String anlegen
		String^ sqlCommandString2 = "SELECT Nachname FROM Teilnehmer WHERE Vorname = 'Daniel'";

		// 2. Befehlsobjekt anlegen
		SqlCommand^ sqlCommand2 = gcnew SqlCommand(sqlCommandString2, connection);

		// 3. Befehl ausführen
		String^ Nachname = sqlCommand2->ExecuteScalar()->ToString();
		Console::WriteLine("Nachname von Daniel ist " + Nachname);

		// --------------------------------------------------------------------------------------------
		// --------------------------------------------------------------------------------------------
		// SQL Befehlskategorie B - Befehle, bei denen kein Ergebnis zurückgeliefert wird

		// 1. SQL Befehl -  aktualisiere Teilnehmer 1
		String^ sqlUpdateString = "UPDATE Teilnehmer SET Standort = 'Osna' WHERE Id = 1";

		// 2. Objket anlegen
		SqlCommand^ sqlUpdateCommand = gcnew SqlCommand(sqlUpdateString, connection);

		// 3. Befehlsobjekt absenden / Befehl ausführen
		sqlUpdateCommand->ExecuteNonQuery();

		// --------------------------------------------------------------------------------------------

		String^ sqlDeleteString2 = "DELETE FROM Teilnehmer WHERE Id = 100";

		SqlCommand^ sqlDeleteCommand2 = gcnew SqlCommand(sqlDeleteString2, connection);

		sqlDeleteCommand2->ExecuteNonQuery();

		// --------------------------------------------------------------------------------------------
		// --------------------------------------------------------------------------------------------
		// SQL Befehlskategorie C - Befehle mit vielen Ergebnissen / Rückgabewerten

		String^ sqlSelectString = "SELECT * FROM Teilnehmer";

		SqlCommand^ sqlSelectCommand = gcnew SqlCommand(sqlSelectString, connection);

		SqlDataReader^ dataReader = sqlSelectCommand->ExecuteReader();

		// Werte der einzelnen Spalten anzeigen
		while(dataReader->Read())
		{
			Console::Write(dataReader["Id"]);
			Console::Write(": ");
			Console::Write(dataReader["Nachname"]);
			Console::Write(", ");
			Console::Write(dataReader["Vorname"]);
			Console::Write(", ");
			Console::WriteLine(dataReader["Standort"]);
		}

		// Verbindung des Datenreaders zur Datenbank trennen
		dataReader->Close();

		// --------------------------------------------------------------------------------------------
		
		String^ vorname = "";
		Console::WriteLine("Bitte geben Sie einen Vornamen ein");
		vorname = Console::ReadLine();


		String^ sqlInsertString = "INSERT INTO Teilnehmer(Id,Vorname, Nachname, Standort) VALUES (100,'" + vorname + "', 'Mustermann', 'Musterdorf')";

		SqlCommand^ sqlInsertCommand = gcnew SqlCommand(sqlInsertString, connection);

		try {
			sqlInsertCommand->ExecuteNonQuery();
		}
		catch (Exception^ ausnahme3)
		{
			Console::WriteLine(ausnahme3);
		}

		// --------------------------------------------------------------------------------------------
		// --------------------------------------------------------------------------------------------

	}
	catch (Exception^ ausnahme)
	{
		Console::WriteLine("Verbindung konnte nicht hergestellt werden, falscher Pfad?");
	}
	
	// Verbindung wieder schliessen
	connection->Close();

	Console::WriteLine("Zum Beenden eine beliebige Taste drücken");
	Console::ReadKey();
	*/
	
	return 0;
}