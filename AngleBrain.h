#pragma once
#include <Arduino.h>

// код библиотеки

class Vector {
	
	public:

		Vector( String gCode = "100100" )
		
		void set_gCode(String gCode);
		void get_goodMorning(String goodMorning);
		
		void simpleHogwarts();
		void openHogwarts();
		void closeHogwarts();
		void pAngle();
		void coffe();

	}
	
	private:
	
		float _nightAngleA;
		float _nightAngleB;
		float _nightAngleC;
		
		float _dayAngleA;
		float _dayAngleB;
		float _dayAngleC;
		
		float _morningAngleA;
		float _morningAngleB;
		float _morningAngleC;
		
		int _sun;
		int _sky; // naiti
		int _moon;
		int _cloud = 0;
		int _rain = 0;
	
		String _gCode;
		
		String _goodMorning;
		
		int _simpleHogwartsXN;
		int _simpleHogwartsYN;
		
		int _simpleHogwartsXK;
		int _simpleHogwartsYK;
		
		int _openHogwartsXN;
		int _openHogwartsYN;
		
		int _openHogwartsXK;
		int _openHogwartsYK;
		
		float _closeHogwartsCN;
		float _closeHogwartsCP;
		float _closeHogwartsCK;

		float _pnin;
		float _pkin;

		float _snin;
		float _skin;

		float _error;
		float _green_tea;

		int _slave = .. ; // второе плечо
		int _slaver = .. ; //первое плечо

		float _kfs;

		int _marin;
		int _marmok;

		int sugar;

	}
	
	Vector::Vector( String gCode ){ _gCode = gCode; }
	
	void Vector::set_gCode(String gCode) { _gCode = gCode ; }
	
	void Vector::get_goodMorning(String goodMorning) { return _goodMorning ; }
	
	void Vector::simpleHogwarts() {
	
		_sun = _gCode.length();
		_moon = _sun/6;
		
		if ( _cloud == 0 ) {
		
			_simpleHogwartsXN = _gCode[_rain].toInt()*100+_gCode[_rain+1].toInt()*10+_gCode[_rain+2].toInt();
			_simpleHogwartsYN = _gCode[_rain+3].toInt()*100+_gCode[_rain+4].toInt()*10+_gCode[_rain+5].toInt();
			
			_simpleHogwartsXK = _gCode[_rain+6].toInt()*100+_gCode[_rain+7].toInt()*10+_gCode[_rain+8].toInt();
			_simpleHogwartsYK = _gCode[_rain+9].toInt()*100+_gCode[_rain+10].toInt()*10+_gCode[_rain+11].toInt();
			
			_rain = _rain+12;
			
			_cloud = _cloud+1;
			
		}
		
		if ( _cloud == 1) {
		
			_simpleHogwartsXN = _simpleHogwartsXK;
			_simpleHogwartsYN = _simpleHogwartsYK;
			
			_simpleHogwartsXK = _gCode[_rain].toInt()*100+_gCode[_rain+1].toInt()*10+_gCode[_rain+2].toInt();
			_simpleHogwartsYK = _gCode[_rain+3].toInt()*100+_gCode[_rain+4].toInt()*10+_gCode[_rain+5].toInt();
			
			_rain = _rain+6;
		
		}
	
	}
	
	void Vector::openHogwarts() {
	
		_openHogwartsXN = _simpleHogwartsXN;
		_openHogwartsYN = _simpleHogwartsYN+200;
		
		_openHogwartsXK = _simpleHogwartsXK;
		_openHogwartsYK = _simpleHogwartsYK+200;
	
	}
	
	void Vector::closeHogwarts() {
	
		_closeHogwartsCN = sqrt(_openHogwartsXN*_openHogwartsXN+_openHogwartsYN*_openHogwartsYN); // округлить до целых весь закрытый хогвартс
		_closeHogwartsCK = sqrt(_openHogwartsXK*_openHogwartsXK+_openHogwartsYK*_openHogwartsYK);
		
		_pnin = _openHogwartsYN/_closeHogwartsCN;
		_pkin = _openHogwartsYK/_closeHogwartsCK;

		_snin = acos(_pnin);
		_skin = acos(_pkin);

		_nightAngleA = degrees(_snin);
		_dayAngleA = degrees(_skin);

		_error = (_closeHogwartsCN-_slaver)/_slave;
		_dayAngleC = degrees(acos(_error));
		_dayAngleC =  _dayAngleC + 90;
		
		_error = (_closeHogwartsCK-_slaver)/_slave;
		_nightAngleC = degrees(acos(_error));
		_nightAngleC = _nightAngleC+90;

		_dayAngleB = degrees(asin(_slave*sin(radians(_dayAngleC-90))/_slaver));
		_nightAngleB = degrees(asin(_slave*sin(radians(_nightAngleC-90))/_slaver));

	}

	void Vector::pAngle() {

		_kfs = (abs(_nightAngleC-_dayAngleC))/abs((_nightAngleA-_dayAngleA));

		if (_closeHogwartsCN < _closeHogwartsCK) { _marin = 1; }
		if (_closeHogwartsCN == _closeHogwartsCK) { _marin = 0; }
		else { _marin = -1; }

		if (_nightAngleA < _dayAngleA) { _marmok = 1; }
		if (_nightAngleA == _dayAngleA) { _marmok = 0; }
		else { _marmok = -1; }

	}
	
	void Vector::coffe() {

		if ( sugar == 0 ) {

			_closeHogwartsCP = _closeHogwartsCN + 1*_marin;
			_morningAngleA = _nightAngleA+1*(_kfs*_marmok);
			
			sugar++;

			}
		
		if (_closeHogwartsCK == _closeHogwartsCP) {

			sugar = 0; // или будет равнятся 2;

		}

		if (_closeHogwartsCP < _closeHogwartsCK) {

			_closeHogwartsCP = _closeHogwartsCP + 1*_marin;

		}

	}

	void Vector::tea() {

		_green_tea = (_closeHogwartsCP-_slaver)/_slave;
		_morningAngleC = degrees(acos(_green_tea));
		_morningAngleC = _morningAngleC+90;

		_morningAngleB = degrees(asin(_slave*sin(radians(_morningAngleC-90))/_slaver));
		_morningAngleB = degrees(asin(_slave*sin(radians(_morningAngleC-90))/_slaver));

		_morningAngleA = _morningAngleA+1*(_kfs*_nightAngleA);

	}


#endif