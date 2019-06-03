#include <iostream>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;


int main()
{
	Console::WriteLine("Programm zu SQLAnwendung" + Environment::NewLine);

	// Verbindung zur Datenbank herstellen



	// Verbindungs Zeichenfolge - connectionString
	String^ connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\Alfa\\source\\repos\\SQLAnwendung\\SQLAnwendung\\Datenbank.mdf;Integrated Security=True;Connect Timeout=30";
	

	// Verbindung vorbereiten
	SqlConnection^ connection = gcnew SqlConnection();
	
	try
	{
		connection->ConnectionString = connectionString;
	}
	catch (Exception^ ausnahme1)
	{
		Console::WriteLine("Verbindung konnte nicht hergestellt werden, falsche Syntax beim Verbindungsstring?");
	}

	
	try
	{
		// Verbindung herstellen
		connection->Open();
		Console::WriteLine("Verbindung erfolgreich hergstellt");

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



	}
	catch (Exception^ ausnahme)
	{
		Console::WriteLine("Verbindung konnte nicht hergestellt werden, falscher Pfad?");
	}

	// Verbindung wieder schliessen
	connection->Close();

	Console::WriteLine("Zum Beenden eine beliebige Taste drücken");
	Console::ReadKey();

	
	return 0;
}