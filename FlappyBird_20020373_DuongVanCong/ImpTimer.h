
#ifndef IMP_TIMER_H_
#define IMP_TIMER_H_

class ImpTimer
{
public:
	ImpTimer();
	void start();
	void stop();
	void pause();
	void unpause();
	int get_ticks();
	bool is_started();
	bool is_paused();

private:
	//thoi gian bat dau
	int start_tick_;
	//tich tac duoc tru khi bo hen gio bi tam dung
	int paused_ticks_;
	bool is_paused_;
	bool is_started_;
};

#endif