/* controll error .header */

#define CERR_H

void error(const char*,...);

void error(const char *fmt,...){
	va_list arg;

	va_start(arg, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, arg);
	fprintf(stderr, "\n");
	va_end(arg);

	exit(1);
}