# My blog
블로그(노션) 링크. 자세하게 설명되어 있음 (코드에 주석 포함)

https://educated-tarsier-f16.notion.site/Minitalk-9edb5a628a9b4ec0990e114243654ebf

# Progress
<img width="200" alt="스크린샷 2022-01-16 오후 8 32 16" src="https://user-images.githubusercontent.com/65381957/149658099-32695a54-595a-411b-89eb-042e128eea0b.png">

Done (+ with bonus score)

+) i have plans to add comments on the code later.

# Overview
> Unix 시그널을 사용한 ipc 통신 시스템

>ipc communication program (small data exchange program using UNIX-signals)

+) bonus part - displaying unicode and implementing reception check system.

### <b>example (실행 예시) : </b>
* Client gets 3 arguments. (executable file itself, server pid, message to send).
    * After sending message, it displays the check meesage verifying if the prgress was successful or not.
* Server displays the recieved message. and send signals to client to confirm reception (reception check system)


<img width="1137" alt="스크린샷 2022-01-16 오후 8 57 27" src="https://user-images.githubusercontent.com/65381957/149658970-b8bbf54c-3b82-4ea5-badd-4187469bebcc.png">

(korean ver. 한국어 버전 설명)
* 클라이언트는 3개의 인자를 받는다 (실행파일 자신, 메시지를 보낼 서버의 pid, 보낼 메시지)
    * 메시지를 전송한 후에, 메시지 전송이 성공했는지 실패했는 지 알려주는 수신체크 메시지를 출력한다.
* 서버는 수신된 메시지를 화면에 출력한다. 그리고 수신 확인을 위해 클라이언트 측에 시그널을 보내준다.

# How to use

    $ git clone (github repo url)
    $ cd minitalk
    $ make
* Next step : from now on, you'll need 2 terminal window to execute either client or server.
    * <b>./server</b>
    * <b>./client (server pid) (message to send) </b>


# Feedbacks
<details>
<summary><p style="font-size:120%"><b>peer evaluation (in korean) </p></summary>
<div markdown="1">
1. 
<img width="685" alt="스크린샷 2022-01-16 오후 8 34 46" src="https://user-images.githubusercontent.com/65381957/149658176-be8fcc8a-701a-4935-9528-5037e278884e.png">
2. 
<img width="688" alt="스크린샷 2022-01-16 오후 8 35 50" src="https://user-images.githubusercontent.com/65381957/149658200-c84c310c-37a7-44d7-b1f8-cae309a990d2.png">
3.
<img width="685" alt="스크린샷 2022-01-16 오후 8 38 02" src="https://user-images.githubusercontent.com/65381957/149658265-b75f5154-1c74-43ac-9a27-727ede3bc59e.png">
</b>
</div>
</details>


# ETC
## <U>The reason why i use sigaction() instead of signal</U>()
-> to get client pid from server. (using siginfo_t type struct)

* <b> signal()이 아닌 sigaction()을 쓰기로 한 이유 </b>

    보너스 파트의 수신 확인 시스템을 만들고 싶었는데, 그러려면 server 측에서 내게 시그널을 보낸 client의 pid에 시그널을 보내야한다. 그러나 signal() 함수를 통해서는 상대방의 pid 정보같은 것을 얻을 수 없다. 반면에 sigaction 함수에서는 구조체로 여러 정보를 담아서 전달하기 때문에 그것으로부터 클라이언트의 pid를 얻는 것이 가능하다.
<br>


## things to check when working on this project
<details>
<summary>과제 진행 시 주의사항</summary>
<div markdown="1">
1. signal 관련 함수의 리턴값을 받아서 그부분까지 에러처리
2. ./client (pid) "메시지" 이렇게 줬을 때, 메시지 인자 안에 공백문자가 텍스트형식으로 들어가있는걸 다시 공백문자로 바꿔주기. (꼭 해야하는 것은 아님. 본인 희망사항에 따라 구현)
3. main 인자로 실행파일 포함 인자 3개가 안들어오면 에러처리
4. 인자로 들어온 pid에 숫자가 아닌 문자가 포함되있으면 에러처리
5. kill() 리턴값 에러처리 (더 자세하게 하려면 함수 하나로 빼서 errno에 따른 예외처리도 가능)
6. sigaction 함수에서 시그널 핸들러 등록에 실패할 시 -1 반환하므로 그것도 에러처리.
7. 시그널 전송 시간이 너무 오래걸리지는 않는 지 에러처리.
(참고) 시그널 전송 시간 재는 법 👉 
time ./client <서버pid> <문자열> 하시면 송신완료 후 걸린 시간이 밑에 나온다.
</div>
</details>
<br>

## history of progress
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
<details>
<summary>3. 전역변수 줄이고 makefile 만듬, client 인자 개수 에러 메시지 추가</summary>

1. makefile 만듬 (남의 꺼 갖다 씀)
2. 전역 변수 client 파일과 server 파일에 둘다 1개씩 있었는데, server 전역 1개 없애서 총 전역변수 1개로 맞춤.
3. client 실행파일에 main 인자 안들어갔을 때 에러메시지 출력하는 거 고침 
    -> fd를 3으로 stderr로 출력해서 터미널에 안 나타난거였음
4. libft 폴더에서 필요한 함수만 추림.
</div>
</details>
<details>
<summary>4. 노미넷에 맞게 다 고치고 예외처리 추가</summary>

1. 노미넷에 맞게 다 고침 (노미넷 = 42코드 문법 규정)
2. 공백문자열 바꿔주는 함수 다 만듬. (여러 번 테스트함)
3. 한글 주석 달아서 노션에 백업함.
</details>
<br>

## References
</details>
<details>
<summary>참고한 자료 링크</summary>

* char과 unsigned char의 비교 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221877901901

* 10진수를 2진수로 바꾸는 법(비트연산) : https://coding-factory.tistory.com/655
* 비트 연산자의 이해 : https://itbeginner2020.tistory.com/18
* 유니코드와 아스키코드의 비교 : https://whatisthenext.tistory.com/103
* 시그널을 받은 client측에서 서버의 pid 받아오는 법 : https://stackoverflow.com/questions/11508427/linux-c-upon-receiving-a-signal-is-it-possible-to-know-the-pid-of-the-sender
* printf가 asyc signal safe가 아닌 이유 : https://unix.stackexchange.com/questions/609210/why-printf-is-not-asyc-signal-safe-function

* sigaction() 함수의 활용 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=skssim&logNo=121271980

* 42 minitalk 블로그 : https://bingu.tistory.com/5
</details>
