#include <Vector.h>

// song class h

class song{
private:
	Vector<int> melody;
	Vector<int> beats;
	int tempo;
	int pause;
  int duration;
  int buzzer;

public:
  song();
  void setBuzzer(int b);
	void setMelody(Vector<int> m, Vector<int> b);
	void setTempo(int t);
	void setPause(int p);
	void play();
};
