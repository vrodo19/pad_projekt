int read() {

int uart0_filestream = -1;							//Kontrollbit
uart0_filestream = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY);		//öffnet Serielle Schnittstelle;
										//O_RDWR - Modus; O_NOCTTY - nicht Master; O_NDELAY - State egal
if (uart0_filestream == -1) {							//falls Kontrollbit weiterhin -1, Fehler
	printf("[ERROR] UART open()\n");
}

struct termios options;
tcgetattr(uart0_filestream, &options);						//Verbindung definieren
	options.c_cflag = B9600 | CS8 | CLOCAL | CREAD; 			//Baudrate
	options.c_iflag = IGNPAR;						//Input option
	options.c_oflag = 0;							//Output option
	options.c_lflag = 0;							//Lin
tcflush(uart0_filestream, TCIFLUSH);
tcsetattr(uart0_filestream, TCSANOW, &options);


// Bytes empfangen
if (uart0_filestream != -1) {
	unsigned char BUF_RX[50];
	int rx_length = read(uart0_filestream, (void*)BUF_RX, 50);		//Daten lesen + länge in rx_length speichern

	if (rx_length < 0) {							//Abfragen ob Daten erhalten wurden mit jeweiliger Meldung
		printf("[ERROR] UART RX\n");
	} else if (rx_length == 0) {
		printf("[ERROR] UART RX - no data\n");
	} else {
		BUF_RX[rx_length] = '\0';					//letzes Zeichen zu \0 ändern, wenn Daten empfangen wurden
	}
}

close(uart0_filestream);							//Schließt Serielle Schnittstelle
	
return BUF_RX;

}
