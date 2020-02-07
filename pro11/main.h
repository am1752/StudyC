#pragma once

void k(char path[]) {
	HKEY k;
	LONG r;

	r = RegOpenKey(HKEY_LOCAL_MACHINE, TEXT(path), &k);


}
