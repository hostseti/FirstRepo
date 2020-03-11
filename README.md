

��������� �Window Chat� ������������ ����� ��������� ����, ���������� ���������� (��������) ���� � ����� �������� ������������ �������. ������� �������������� � �������� ��������� ����������� ����� ������ ��������. ��������� - ��� ������ ��������� ���� ���������.

��� ������ ��������� ���������� ��������� �����������:

- ���������� Qt ������ 5.12.x (https://download.qt.io/archive/qt/5.12);
- ������� ������ Cmake ������ 3.5 � ����;
- ���������� C++ � ���������� ��������� 11.

����� ������� ���������� ���������, ��� � ���������� PATH ��������� ���� ��� CMake � Qt. ��������, ���� Qt ����������� � ���������� C:\Qt, �� PATH ������ ����� ��������: C:\Qt\Qt5.12.7\5.12.7\mingw73_32\bin; C:\Qt\Qt5.12.7\Tools\mingw730_32\bin.

������: �����! ���� � ��������� ���� �� ������ ��������� ���������. ������� ��������� ������/�������� � ������� � ������� � �������� �����. ��������� ��������������� ������� ���� ��� ������� (������ ��� MinGW, � �� Windows):

�mkdir build�  
�cd build�  
�cmake -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Release ..�  
�mingw32-make�

(��������� Makefile ��� ������ ������������ ��. � ������� cmake �help, �������� ����� -G).  
����� �������� ������ ����� � �������� ����� � �������� build �������� ����������� ���� �WindowChat.exe�.