# wbz451

기능 설명

Reset Switch 누르면 ALL STOP
--

다시 누르면
"RTC_Initialize 업로드 완료 or 초기상태 진입(Power reset not MCLR)" 상태로 진입
/*참조 함수 : 
RTC_Timer32Start();
DEVICE_EnterDeepSleep(false,0);
*/
--

사용자 Switch 누르면 DeepSleepADvertising Start 
/*참조 함수 : 
APP_BleStackInit();
APP_BleDsadvStart(false);
*/
--

미리 정의 해둔 DSADV interval 값 만큼 시간이 지난후 RTC Callback 주기적으로 호출 -> DSADV 주기적으로 호출
/*참조 매크로 : 
#define DSADV_INTERVAL    1536
/*참조 함수 : 
APP_BleDsadvStart(true);
*/
--

Connect 시 DSADV 종료
/* DSADV 를 계속해서 안하면 종료라고 봐도 무방함.
*/

Disconnect 시 DSAD Restart
/*참조 함수 : 
APP_BleDsadvRestart();
*/


