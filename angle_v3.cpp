//добавить дублирующие углы
//обнуление переменных после конца класса

#include <angle_v2.h>

Angle::jekaCode(String gCode = "000000", int _pause = 100) { // конструктор : gCode список координат; pause- задержка между поворотами в мили сек. 
		
		_gCode = gCode;
		_pause = pause;

}

void Angle::_magic() { // определяем длину gCode и кол-во координат.
	
	_sun = _gCode.lenght();
	_moon = _sun/6;
	
}

void Angle::set_gCode(String gCode){
	
	_gCode = gCode; 
	
} 

void Angle::set_pause(int pause){
	
	_pause = pause; 
	
}

void Angle::_simpleHogwarts() { // передаем ардуинке координаты с листа ( начальные и следующие )

		_gCode = cCode;

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

		_sugar = 0;

}

void Angle::_openHogwarts() { // превравращаем координаты листа в координаты на листе относительно манипулятора.
	
		_openHogwartsXN = _simpleHogwartsXN;
		_openHogwartsYN = _simpleHogwartsYN+_deadZone;
		
		_openHogwartsXK = _simpleHogwartsXK;
		_openHogwartsYK = _simpleHogwartsYK+_deadZone;
	
	}

void Angle::_closeHogwarts() { // переводим наши координаты из декартовой СК в полярные СК.
	
		_closeHogwartsCN = sqrt(_openHogwartsXN*_openHogwartsXN+_openHogwartsYN*_openHogwartsYN);
		_closeHogwartsCK = sqrt(_openHogwartsXK*_openHogwartsXK+_openHogwartsYK*_openHogwartsYK);
		
		_pnin = _openHogwartsYN/_closeHogwartsCN; // косинус нацального
		_pkin = _openHogwartsYK/_closeHogwartsCK; // косинус конецного

		_nightAngleA = degrees(acos(_pnin)); // нацальный угол А
		_dayAngleA = degrees(acos(_pkin)); // конецный угол А

		_error = (_closeHogwartsCN-_slaver)/_slave; // промежуточная переменная 
		_dayAngleC = degrees(acos(_error)); // конецный угол С
		_dayAngleC =  _dayAngleC + 90;
		
		_error = (_closeHogwartsCK-_slaver)/_slave;
		_nightAngleC = degrees(acos(_error)); // нацальный угол С
		_nightAngleC = _nightAngleC+90;

		_dayAngleB = degrees(asin(_slave*sin(radians(_dayAngleC-90))/_slaver)); // конецный угол В
		_nightAngleB = degrees(asin(_slave*sin(radians(_nightAngleC-90))/_slaver)); // нацальный угол В

	}
	
void Angle::_pAngle() { // определяем коэффициенты для расчета углов.

		_kfs = (abs(_nightAngleC-_dayAngleC))/abs((_nightAngleA-_dayAngleA));

		if (_closeHogwartsCN < _closeHogwartsCK) { _marin = 1; }
		if (_closeHogwartsCN == _closeHogwartsCK) { _marin = 0; }
		else { _marin = -1; }

		if (_nightAngleA < _dayAngleA) { _marmok = 1; }
		if (_nightAngleA == _dayAngleA) { _marmok = 0; }
		else { _marmok = -1; }
		
		_red_moon = round(abs(_closeHogwartsCP-_closeHogwartsCK));

	}
	
void Angle::_coffe() { // изменение R в полярных координатах.

		if ( _sugar == 0 ) {

			_morningAngleA = _nightAngleA+1*(_kfs*_nightAngleA);
			
			_closeHogwartsCP = _closeHogwartsCN + 1*_marin;
			
			_sugar++;

			}
		
		if (round(_closeHogwartsCK) == round(_closeHogwartsCP)) {

			_sugar = 2;

		}

		if (round(_closeHogwartsCP) < round(_closeHogwartsCK))and(_sugar==1) {

			_closeHogwartsCP = _closeHogwartsCP + 1*_marin;

		}

	}

void Angle::_tea() { // вычисление углов в полярных координатах

		_green_tea = (_closeHogwartsCP-_slaver)/_slave;
		_morningAngleC = degrees(acos(_green_tea));
		_morningAngleC = _morningAngleC+90;

		_morningAngleB = degrees(asin(_slave*sin(radians(_morningAngleC-90))/_slaver));
		_morningAngleB = _morningAngleB+90;
		_morningAngleA = _nightAngleA+1*(_kfs*_nightAngleA);

	}
	
void Angle::ctrlV() { // перевод сервомоторов в нулевую позицию (smoothStart()) 
	
	servoB.attach(3, _dayAngleBZ);
	smoothStart();

    servoC.attach(1, _dayAngleCZ);
	smoothStart();
	
	servoA.attach(4, _dayAngleAZ);
	smoothStart();
	
}

void Angle::_ctrlC() { // вычисление нулевых координат.
	
	_closeHogwartsCZ = _deadZone;
	
	_error = (_closeHogwartsCZ-_slaver)/_slave; // промежуточная переменная 
	_dayAngleCZ = degrees(acos(_error)); // конецный угол С
	_dayAngleCZ =  _dayAngleCZ + 90;
	
	_dayAngleBZ = degrees(asin(_slave*sin(radians(_nightAngleCZ-90))/_slaver)); // нацальный угол В
	
	_dayAngleAZ = 90;
	
}

void Angle::_ctrlZ() {
	
				_angleA = _dayAngleA;
				_angleB = _dayAngleB;
				_angleC = _dayAngleC;
	
				_burgerKing = (abs(_dayAngleCZ-_dayAngleC))/abs((_dayAngleAZ-_dayAngleA));
				_mcDonalds = (abs(_dayAngleCZ-_dayAngleC))/abs((_dayAngleBZ-_dayAngleB));
	
				if (_dayAngleAZ < _dayAngleA) { _marmok = 1; }
				if (_dayAngleAZ == _dayAngleA) { _marmok = 0; }
				else { _marmok = -1; }
			
				if (_dayAngleBZ < _dayAngleB) { _marin = 1; }
				if (_dayAngleBZ == _dayAngleB) { _marin = 0; }
				else { _marin = -1; }
			
				if (_dayAngleCZ < _dayAngleC) { _marmelad = 1; }
				if (_dayAngleCZ == _dayAngleC) { _marmelad = 0; }
				else { _marmelad = -1; }	
				
			while (catGirl == 0) {	
				
				if (round(_angleA) != round(_dayAngleAZ)) {_angleA = _angleA+1*_marmok*_burgerKing;}
				if (round(_angleB) != round(_dayAngleBZ)) {_angleB = _angleB+1*_marin*_mcDonalds;}
				if (round(_angleC) != round(_dayAngleCZ)) {_angleC = _angleC+1*_marmelad;}
				
				servoA.write(_angleA);
				servoB.write(_angleB);
				servoC.write(_angleC);
				
				if ((round(_angleA))=round(_dayAngleAZ))and((round(_angleB))=round(_dayAngleBZ))and((round(_angleC))=round(_dayAngleCZ)) {catGirl = 1;}
				
				
				delayMicroseconds(_pause);
		
		}
			
}

void Angle::normalno() { // функцию, которую мы вызываем в главном коде.
		
		_ctrlC();
		_magic();
		
		
		
		while (_trig <= _moon){
		
			_simpleHogwarts();
			_openHogwarts();
			_closeHogwarts();
				
			if (_buzofa == 0) { // (был Путин, а стал Бузофа) Переход в начальные координаты
			
				_burgerKing = (abs(_dayAngleCZ-_dayAngleC))/abs((_dayAngleAZ-_dayAngleA));
				_mcDonalds = (abs(_dayAngleCZ-_dayAngleC))/abs((_dayAngleBZ-_dayAngleB));
	
		
				if (_dayAngleAZ < _dayAngleA) { _marmok = 1; }
				if (_dayAngleAZ == _dayAngleA) { _marmok = 0; }
				else { _marmok = -1; }
			
				if (_dayAngleBZ < _dayAngleB) { _marin = 1; }
				if (_dayAngleBZ == _dayAngleB) { _marin = 0; }
				else { _marin = -1; }
			
				if (_dayAngleCZ < _dayAngleC) { _marmelad = 1; }
				if (_dayAngleCZ == _dayAngleC) { _marmelad = 0; }
				else { _marmelad = -1; }

				//alcochidochi

				_eveningAngleA = _dayAngleAZ;
				_eveningAngleB = _dayAngleBZ;
				_eveningAngleC = _dayAngleCZ;
	
				while (_buzofa == 0) {
				
					_eveningAngleA = _eveningAngleA+1*_marmok*_burgerKing;
					_eveningAngleB = _eveningAngleB+1*_marin*_mcDonalds;
					_eveningAngleC = _eveningAngleC+1*_marmelad;
				
					servoA.write(_eveningAngleA);
					servoB.write(_eveningAngleB);
					servoC.write(_eveningAngleC);
				
				delayMicroseconds(_pause);
				
				if (_eveningAngleC == _nightAngleC) { _buzofa = 1}
				
			}

		}
			
			_pAngle();
			
			 while (_sugar != 2) { // при помощи этой штуки углы двигаются))) @Ceмен
				 
				 _coffe();
				 _tea();

				_angleA = round(_morningAngleA);
				_angleB = round(_morningAngleB);
				_angleC = round(_morningAngleC);


				 servoA.write(_angleA);
				 servoB.write(_angleB);
				 servoC.write(_angleC);
				 
				 delayMicroseconds(_pause);

			 }                    
		
	}
	
			 _rain = 0;
			 _cloud = 0;
			 _sugar = 0;
	 		 _buzofa = 0;
			 _trig = 0;
			 
			 _ctrlZ();
			 
			 catGirl = 0;
			 
}
