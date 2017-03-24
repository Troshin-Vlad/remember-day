#!/bin/bash

# start - start daemon
# stop	- stop daemon
# stoped - stop all daemon
# log	- print log
# clear - clear log file
# help  - print help page

RED="\033[31m"
DEF="\033[0m"

if [ $# -lt 1 ]
then
	echo "Using: dayd.sh [start|stop|stoped|log|clear|help]"
	echo -e $RED"error:$DEF required one parameter"
	exit 1
fi

ACTION=$1
FILE_LOG="dayd.log"
FILE_DAEMON="dayd"
FILE_PID="dayd.pid"
PID=$(cat $FILE_PID)

if [ $ACTION = "start" ]
then
	./$FILE_DAEMON
elif [ $ACTION = "stop" ]
then
	kill $PID
	echo -n "" > $FILE_PID
elif [ $ACTION = "stoped" ]
then
	killall $FILE_DAEMON
	echo -n "" > $FILE_PID
elif [ $ACTION = "log" ]
then
	cat $FILE_LOG
elif [ $ACTION = "clear" ]
then
	echo -en "" > $FILE_LOG
elif [ $ACTION = "help" ]
then
	echo "  start:  start day daemon"
	echo "  stop:   stop day daemon"
	echo "  stoped: stoped all daemons"
	echo "  log:    print log"
	echo "  clear:  clear log file"
	echo "  help:   print help page"
else 
	echo -e $RED"error:$DEF unknow command "\"$ACTION\"
fi

exit 0


