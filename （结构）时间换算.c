#include <stdio.h>
struct time {
	int hour;
	int minute;
	int second;
};
int main()
{
	struct time time1;
	time1.hour = 0;
	time1.minute = 0;
	time1.second = 0;
	int n;
	scanf("%d:%d:%d", &time1.hour, &time1.minute, &time1.second);
	scanf("%d", &n);
	time1.second += n;
	if (time1.second >= 60) {
		time1.minute++;
		time1.second -= 60;
	}
	if (time1.minute >= 60) {
		time1.minute -= 60;
		time1.hour++;
	}
	if (time1.hour >= 24) {
		time1.hour -= 24;
	}
	printf("%02d:%02d:%02d", time1.hour, time1.minute, time1.second);
	return 0;
}
