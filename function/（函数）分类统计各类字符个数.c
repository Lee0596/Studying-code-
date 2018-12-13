void StringCount(char *s) {
	int cntlower = 0, cntupper = 0, cntnum = 0, cntother = 0, cntblank = 0, i;
	for (; *s!= '\0'; s++) {
		if (*s <= '9'&&*s >= '0') {
			cntnum++;
		}
		else {
			if (*s <= 'Z'&&*s >= 'A') {
				cntupper++;
			}
			else {
				if (*s <= 'z'&&*s >= 'a') {
					cntlower++;
				}
				else {
					if (*s == ' ') {
						cntblank++;
					}
					else {
						cntother++;
					}
				}
			}
		}
	}
	printf("%d %d %d %d %d", cntupper, cntlower, cntblank, cntnum, cntother);
}
