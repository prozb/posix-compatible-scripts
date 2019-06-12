
int func(int amnt) {
	int zero = 0;			
	int *ptr = &zero;

	if (amnt > 0) {
		int val = 42;
		ptr = &val;
	}
	else if (amnt < 0) {
		int val = -42;
		ptr = &val;
	}
	return *ptr;
} // func

// Es wird neuer Frame angelegt und lokalen Variablen auf stack 
// gepusht. In dem if-else Block wird der Variable ptr die Referenz 
// auf val zugewiesen. Nach dem if-else Block dereferenziert man den 
// ptr pointer und man schreibt diesen Wert in return Register. Danach 
// wird dieser Frame released, da aber wir die Konstante (nicht pointer)
// in return Register reinschreiben macht das nach dem release stack frame 
// nichts aus. Und es werden korrekte Werte zurueckgeliefert => Code ist
// korrekt.
//  
//  ------------
//  | amnt     | 0x0
//  |==========| 
//  | zero     | 0x1
//  | ptr = 0x3| 0x2
//  | val      | 0x3
//  |==========|
//
 

