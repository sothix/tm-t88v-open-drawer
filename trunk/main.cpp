#include <iostream>
#include "StatusAPI.h"

#define	EPS_PRINTER_NAME	(char *) "EPSON TM-T88V Receipt"

using namespace std;

int main()
{
	CStatusAPI	m_statAPI;

	// Initialize the Status API object. This loads the functions from EpsStmApi.dll
	int	nHandle ;	// The handle for the printer monitor
	if ( m_statAPI.Initialize() == FALSE ) {
        cout << "Failed to open StatusAPI." << endl;
		return 0;
	}

	//  Open a printer status monitor for the selected printer
	nHandle = m_statAPI.BiOpenMonPrinter(TYPE_PRINTER, EPS_PRINTER_NAME) ;
	if ( nHandle <= 0 )
	{
        cout << "Failed to open printer status monitor." << endl;
		return 0;
	}

	//Pop The Box
    if ( m_statAPI.BiOpenDrawer(nHandle, EPS_BI_DRAWER_1, EPS_BI_PULSE_100) != SUCCESS ) {
        cout << "Failed to open drawer." << endl;
    } else {
        cout << "Frikkin Rock" << endl;
    }


	// Always close the Status Monitor after using the Status API
	if ( m_statAPI.BiCloseMonPrinter(nHandle) != SUCCESS ) {
        cout << "Failed to close printer status monitor." << endl;
	}



return 0;
};
