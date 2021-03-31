#pragma once
#include <Arduino.h>

class Angle {
	
	public: 
	
		jekaCode(String gCode = "000000", int pause = 50); // конструктор : gCode список координат; pause- задержка между поворотами в мили сек. 
		
		void normalno();        // функцию, которую мы вызываем в главном коде
		void ctrlV();           // перевод сервомоторов в нулевую позицию (smoothStart()) 
		void set_gCode(String gCode); // мы присваиваем нашему объекту gCode.
		void set_pause(int pause);
		
	private:
		
		void _simpleHogwarts(); // передаем ардуинке координаты с листа ( начальные и следующие )
		void _openHogwarts();	// превравращаем координаты листа в координаты на листе относительно манипулятора.
		void _closeHogwarts();  // переводим наши координаты из декартовой СК в полярные СК.
		void _magic();          // определяем длину gCode и кол-во координат.
		void _pAngle();         // определяем коэффициенты для расчета углов.
		void _coffe();          // изменение R в полярных координатах.
		void _tea();            // вычисление углов в полярных координатах
		
		void _ctrlC();          // вычисление нулевых координат.
		
		void _ctrlZ();
		
		int _pause;             // длина паузы
		
		int _sun;
		int _moon;
		int _rain = 0;
		int _cloud = 0;
		int _sugar = 0;
		
		int _simpleHogwartsXN;
		int _simpleHogwartsYN;
		int _simpleHogwartsXK;
		int _simpleHogwartsYK; 
		
		int _openHogwartsXN;
		int _openHogwartsYN;
		int _openHogwartsXK;
		int _openHogwartsYK;
		
		float _closeHogwartsCN;
		float _closeHogwartsCK;
		float _closeHogwartsCP;
		
		int _deadZone = 50; 
		
		float _closeHogwartsCN;
		float _closeHogwartsCK;

		float _pnin;
		float _pkin;
		float _error;
	
		float _dayAngleA;
		float _nightAngleA;
	
		float _dayAngleB;
		float _nightAngleB;
	
		float _dayAngleC;
		float _nightAngleC;
		
		String _gCode; 
		
		int _marmok;
		int _marin;
		int _marmelad;
		float _kfs;
		
		int _red_moon;
		
		float _green_tea;
		
		float _morningAngleA;
		float _morningAngleB;
		float _morningAngleC;
		
		int _eveningAngleA;
		int _eveningAngleB;
		int _eveningAngleC;
		
		float _burgerKing;
		float _mcDonalds;
		
		int _closeHogwartsCZ;

		int _dayAngleAZ
		int _dayAngleBZ
		int _dayAngleCZ
		
		int _buzofa = 0;
		int _trig = 0;
		int catGirl = 0;

		
		int _angleA;
		int _angleB;
		int _angleC;
		
}	
		
	
#endif
