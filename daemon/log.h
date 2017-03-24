#define LOG_H
#define LOG_NAME "dayd.log"

FILE *fd_log;

void open_log();
void close_log();
void daemon_log(const char*,...);

void gettm(const char*, char*, int);
void gettime(char*, int);
void getdate(char*, int);

// open log file
void open_log(){
	if( !(fd_log = fopen(LOG_NAME, "a")) ){
		error("open log file");
	}
}

// close log file
void close_log(){
	if(fd_log != NULL){
		fclose(fd_log);
	}
}

// write log in file
void daemon_log(const char *fmt, ...){

	va_list arg;
	char tm_time[31];
	char tm_date[31];
	getdate(tm_date, 30);
	gettime(tm_time, 30);
	
	open_log();
	va_start(arg, fmt);

	fprintf(fd_log, "[%s][%s]: ", tm_date, tm_time);
	vfprintf(fd_log, fmt, arg);
	fprintf(fd_log, "\n");

	va_end(arg);
	close_log();
}

// get time 12:00:00
void gettime(char *buf, int size){
	gettm("%H:%M:%S", buf, size);
}

// get date 12.03.17
void getdate(char *buf, int size){
	gettm("%d.%m.%y", buf, size);
}

// get format time
void gettm(const char *fmttime, char *buf, int size){
	long int s_time;
	struct tm *m_time;

	s_time = time(NULL);
	m_time = localtime(&s_time);

	strftime(buf, size, fmttime, m_time);
}