#!/bin/bash_

printf "#Architecture: "
 uname -srvmo
 # Check the System information (시스템 정보 확인)

printf "#CPU physical : "
 nproc --all
 # Check the number of physical CPU (물리적 cpu의 개수 확인)


printf "#vCPU : "
 cat /proc/cpuinfo | grep processor | wc -l
 # Check the number of physical CPU allocated on this Virtual machine (가상머신에 할당된 물리적 CPU의 개수 확인)

printf "#Memory Usage: "
 free -m | grep Mem | awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'
 # Check the memory occupation rate (메모리 점유율 확인)

printf "#Disk Usage: "
 df -BM -a | grep /dev/mapper/ | awk '{sum+=$3}END{print sum}' | tr -d '\n'
printf "/"
 df -H -a | grep /dev/mapper/ | awk '{sum+=$4}END{print sum}' | tr -d '\n'
printf "GB ("
 df -BM -a | grep /dev/mapper/ | awk '{sum1+=$3 ; sum2+=$4 }END{printf "%d", sum1 / sum2 * 100}' | tr -d '\n'
printf "%%)\n"
 # Check Disk's space and it's utilization (디스크의 공간 및 디스크 사용률 확인)

printf "#CPU load: "
 mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'
 # Check CPU utilization (CPU 사용률 확인)
printf "#Last boot: "
 who -b | sed 's/^ *system boot //g'
 # Check last booted time of the system (마지막으로 시스템 부팅한 시간 확인)
printf "#LVM use: "
 if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi
 # Check if LVM is used on this machine (LVM이 사용되었는 지 여부 확인)
printf "#Connections TCP : "
 ss | grep -i tcp | wc -l | tr -d '\n'
printf " ESTABLISHED\n"
 # Check TCP connection (TCP 연결을 확인)
printf "#User log: "
 who | wc -l
 # Check the number of users who is currently loggined in (현재 로그인 중인 이용자의 수를 확인)
printf "#Network: IP"
 /sbin/ifconfig | grep broadcast | sed 's/inet//g' | sed 's/netmask.*//g' | sed 's/ //g' | tr -d '\n'

printf " ("
 /sbin/ifconfig | grep 'ether ' | sed 's/.*ether //g' | sed 's/ .*//g' | tr -d '\n'
printf ")\\n"
 # Check present ip address and mac address (현재 ip주소와 mac주소 확인)
printf "#Sudo : "
 grep -a 'sudo:' /var/log/auth.log | grep 'COMMAND=' | wc -l | tr -d '\n'
printf " cmd\n"
 # Check the number of using sudo command (sudo 명령어 사용 횟수 확인)
exit 0