static int print_i128(__int128 i) {
    char s[40], *c = s, *head = s;
    int len = 0;
    if(i < 0) {
        putchar('-');
        i = -i;
    }
    // Turn __int28 into char[] from lowest digit
    while(i > 9) {
        *c++ = i % 10 + '0';
        i /= 10;
    }
    *c = i + '0';
    // Print
    while(c >= head) {
        putchar(*c--);
    }
    return 1;
}
static int scan_i128(__int128 *in) {
    char s[40], *c = s;
    bool minus = false;
    __int128 &n = *in;
    n = 0; // reset n
    int ret = scanf("%s", s);
    if(ret == EOF) return EOF;
    // Judge if minus
    if(*c == '-') {
        minus = true;
        c++; // skip '-'
    }
    // Add the digit and multiply it by 10 one after another
    while(*c) {
        n *= 10;
        n += *c - '0';
        c++;
    }
    if(minus) n = -n;
    return 1;
}