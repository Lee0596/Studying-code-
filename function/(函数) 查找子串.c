char *search(char *s, char *t) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == t[0]) {
            int j = 1;
            while (s[i + j] == t[j] && t[j] != '\0') {
                j++;
            }
            if (t[j] == '\0') {
                return s + i;
            }
        }
        i++;
    }
    return NULL;
}
