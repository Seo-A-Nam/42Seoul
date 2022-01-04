## 현재 진행현황
___
mendatory part 마무리 + 보너스파트에 unicode 까지 나타나게 함.
<img width="858" alt="스크린샷 2022-01-04 오후 12 39 22" src="https://user-images.githubusercontent.com/65381957/148006591-fffd5a23-2635-4e32-86c3-7e2fa9201a85.png">

그렇지만 수신확인 시스템을 만들려면 시그널을 보낸 상대편의 pid를 알아야함. 이때 signal() 함수에는 해당 기능이 없으므로 이를 sigaction() 함수로 대체하려고 함.

signal 함수의 핸들러 프로토타입은 void 핸들러(int signo)로 정해져있었는데 sigaction 함수에는 핸들러를 어떻게 만들어야할 지 고민 중.
여기서 어떻게 siginfo_t를 얻어 si_pid로 보낸 상대의 pid를 얻는 지도...

<br>

## sigaction을 쓰기로 한 이유
___
수신 확인 시스템을 만들고 싶었는데, 그러려면 client 측에서 내게 시그널을 보낸 server의 pid에 시그널을 보내야한다. 그러나 signal() 함수를 통해서는 서버의 pid 정보같은 것을 얻을 수 없다. 반면에 sigaction 함수에서는 구조체로 여러 정보를 담아서 전달하기 때문에 서버의 pid를 얻는 것이 가능하다
<br>

## 참고한 자료
____
* char과 unsigned char의 비교 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221877901901

* 10진수를 2진수로 바꾸는 법(비트연산) : https://coding-factory.tistory.com/655
* 비트 연산자의 이해 : https://itbeginner2020.tistory.com/18
* 유니코드와 아스키코드의 비교 : https://whatisthenext.tistory.com/103
* 시그널을 받은 client측에서 서버의 pid 받아오는 법 : https://stackoverflow.com/questions/11508427/linux-c-upon-receiving-a-signal-is-it-possible-to-know-the-pid-of-the-sender
* printf가 asyc signal safe가 아닌 이유 : https://unix.stackexchange.com/questions/609210/why-printf-is-not-asyc-signal-safe-function