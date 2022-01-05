## 과제 진행 시 주의사항
1. signal 관련 함수의 리턴값을 받아서 그부분까지 에러처리
2. ./client (pid) "메시지" 이렇게 줬을 때, 메시지 인자 안에 공백문자가 텍스트형식으로 들어가있는걸 다시 공백문자로 바꿔주기. (꼭 해야하는 게 맞나? - 본인이 하고 싶다면 해라)
3. main 인자로 실행파일 포함 인자 3개가 안들어오면 에러처리
4. 인자로 들어온 pid에 숫자가 아닌 문자가 포함되있으면 에러처리
5. kill() 리턴값 에러처리 (더 자세하게 하려면 함수 하나로 빼서 errno에 따른 예외처리도 가능)
6. sigaction 또는 signal 함수에서 시그널 핸들러가 등록되지 않았을 시 0 반환하므로 그것도 에러처리.
7. 시그널 전송 시간이 너무 오래걸리지는 않는 지 에러처리.
(참고) 시그널 전송 시간 재는 법)
time ./client <서버pid> <문자열> 하시면 송신완료 후 걸린 시간이 밑에 나온다.
<!--(참고) 시그널 전송 시간 재는 법
다음 코드를 client.c의 메인함수에 넣어준다 👉
int start = clock(); // 시그널 보내기 전
int end = clock(); // 시그널 보낸 후
printf("글자 수 %d개인 메시지 보내는 데 걸린 시간 : %.3lf 밀리초, %.3lf 초\n", (int)ft_strlen(argv[2]), (double)end-start, (end-start)/(double)1000);-->

## 현재 진행현황
보너스 파일 따로 만들어야하는 지 아닌지만 알아보고, 노션에 동료평가용 설명 자료만 만들어놓으면 당장 평가받을 수 있음.

## 과거 진행 기록 (history of progress)
<details>
<summary>1. mendatory part 마무리 + 보너스파트에 unicode 까지 나타나게 함.</summary>
<div markdown="1">
<img width="858" alt="스크린샷 2022-01-04 오후 12 39 22" src="https://user-images.githubusercontent.com/65381957/148006591-fffd5a23-2635-4e32-86c3-7e2fa9201a85.png">

그렇지만 수신확인 시스템을 만들려면 시그널을 보낸 상대편의 pid를 알아야함. 이때 signal() 함수에는 해당 기능이 없으므로 이를 sigaction() 함수로 대체하려고 함.

signal 함수의 핸들러 프로토타입은 void 핸들러(int signo)로 정해져있었는데 sigaction 함수에는 핸들러를 어떻게 만들어야할 지 고민 중.
여기서 어떻게 siginfo_t를 얻어 si_pid로 보낸 상대의 pid를 얻는 지도...
</div>
</details>

<details>
<summary>2. 1번 현황에서 그대로 signal() 다 sigaction()으로. [보너스] 수신확인 시스템 구현. </summary>
<img width="1296" alt="스크린샷 2022-01-04 오후 2 22 46" src="https://user-images.githubusercontent.com/65381957/148013113-2b614fbd-3fd3-4603-b2bf-cd83552511ea.png">

1. signal 보내는 함수 리턴값에 따라 전부 추가로 예외처리해줘야함.
2. 아직 norminette 규정 맞추기랑 허용불가 함수 지우고 libft와 makefile 추가하는 것 남아있음.
3. 과제에서 전역변수가 허용되는 지 확인해야함.
4. 근데 아직 개행문자가 문자그대로 \n 이렇게 나오는 현상 못고침.
5. makefile 못만듬
</div>
</details>
<br>

<details>
<summary>3. 전역변수 줄이고 makefile 만듬, client 인자 개수 에러 메시지 추가</summary>

1. makefile 만듬 (남의 꺼 갖다 씀)
2. 전역 변수 client 파일과 server 파일에 둘다 1개씩 있었는데, server 전역 1개 없애서 총 전역변수 1개로 맞춤.
3. client 실행파일에 main 인자 안들어갔을 때 에러메시지 출력하는 거 고침 
    -> fd를 3으로 stderr로 출력해서 터미널에 안 나타난거였음
4. libft 폴더에서 필요한 함수만 추림.
</div>
</details>
<br>

<details>
<summary>4. 노미넷에 맞게 다 고치고 예외처리 추가</summary>

1. 노미넷 다 고침
2. 공백문자열 바꿔주는 함수 다 만듬. (여러 번 검토함)
3. 한글 주석 달아서 노션에 백업함.
</details>
<br>

## signal()이 아닌 sigaction()을 쓰기로 한 이유
보너스 파트의 수신 확인 시스템을 만들고 싶었는데, 그러려면 client 측에서 내게 시그널을 보낸 server의 pid에 시그널을 보내야한다. 그러나 signal() 함수를 통해서는 서버의 pid 정보같은 것을 얻을 수 없다. 반면에 sigaction 함수에서는 구조체로 여러 정보를 담아서 전달하기 때문에 그것으로부터 서버의 pid를 얻는 것이 가능하다
<br>

## 참고한 자료
* char과 unsigned char의 비교 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221877901901

* 10진수를 2진수로 바꾸는 법(비트연산) : https://coding-factory.tistory.com/655
* 비트 연산자의 이해 : https://itbeginner2020.tistory.com/18
* 유니코드와 아스키코드의 비교 : https://whatisthenext.tistory.com/103
* 시그널을 받은 client측에서 서버의 pid 받아오는 법 : https://stackoverflow.com/questions/11508427/linux-c-upon-receiving-a-signal-is-it-possible-to-know-the-pid-of-the-sender
* printf가 asyc signal safe가 아닌 이유 : https://unix.stackexchange.com/questions/609210/why-printf-is-not-asyc-signal-safe-function

* sigaction() 함수의 활용 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=skssim&logNo=121271980