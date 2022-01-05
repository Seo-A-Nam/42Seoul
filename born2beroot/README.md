# 내 노션 페이지
굉장히 자세하게 내용을 정리해두었습니다. 많은 참고 바랍니다.
<br>

<a href="https://educated-tarsier-f16.notion.site/42-born2beroot-668fb0b76de248ddbbc7d667f2e22b7f" target="_blank"><img src="https://img.shields.io/badge/Blog-000000?stylef=for-the-badge&logo=notion&logoColor=white"/></a>


# Overview
### The project consists of creating and configuring a virtual machine following strict rules. 

### 이 프로젝트는 엄격한 규칙을 통해 가상머신을 생성하고 구성하는 것을 다루고 있습니다. 

<br>

* 저는 Debian 운영체제를 선택하였고, VirtualBox를 통해 virtual machine을 생성하였습니다. 

* 우선, 가상머신의 정의와 가상머신 OS의 종류, debian과 centOS의 각각의 차이점에 대해서 비교하면서 설명해야합니다. 

* LVM의 생성과 디스크의 파티셔닝을 수행하고, LVM과 파티션의 차이점에 대해 설명합니다.

* 가상 머신 내에서 SSH, UFW, SUDO, 비밀번호 정책, sudo 정책, 포트 정책 등의 설정을 통해, 제시된 사항에 맞게 가상머신을 구성할 수 있도록 합니다.

	동료 평가 중에 평가자는 피평가자가 가상 머신에서 명령어들을 사용하여 사용자 그룹을 더하고 삭제하는 과정과 호스트 네임을 확인하고 변경하는 과정 등을 확인할 수 있어야 합니다.

* 평가 중에, 가상머신에서 4242 포트만 열려있는 것을 확인하고 호스트 OS의 터미널에서 포트포워딩하여 해당 설정 사항이 올바르게 적용된 것을 확인 받았습니다. 
	
	(보안 상의 목적으로 루트 유저에서는 ssh를 사용할 수 없도록 설정하였기 때문에, root가 아닌 일반 계정에서만 포트포워딩 할 수 있습니다)

* 자동 스캐쥴러인 cron 설정을 통해, 10분마다 한번씩 monitoring.sh가 실행되도록 합니다.

	다음은 monitoring.sh가 cron을 통해 실행된 결과입니다. monitoring.sh의 스크립트 파일도 이 레포지터리에서 확인할 수 있습니다.
<br>

## monitoring.sh의 cron 실행 화면 
![image](https://user-images.githubusercontent.com/65381957/148267122-a84ea0a3-c93c-4c8e-871b-7083807636ad.png)

## signature.txt
제 virtual machine (Virtual Box)의 해시값을 추출한 것입니다.
* 제 윈도우에서 %HOMEDRIVE%%HOMEPATH%VirtualBox VMs\ 의 경로로 먼저 들어가줍니다.

* 그 다음 .vdi 형식 파일로부터 sha1 형식의 해시값을 추출해줍니다.

	윈도우 커멘드 창에서 certUtil -hashfile born2beroot.vdi sha1 을 입력해주었습니다.
