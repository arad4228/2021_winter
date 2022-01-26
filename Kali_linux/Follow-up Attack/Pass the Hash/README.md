### Pass the Hash attack
</br>
# Password에 대한 hash값을 사용하는 환경(NTLM/LM 인증 프로토콜을 사용하는 환경)에서, 획득한 hash 값을 사용하여 인증을 통과하는 공격 
(사용자의 실제 Password는 몰라도 됨)
</br>

## Mechanism
NTLM/LM 인증을 사용하는 서버/서비스는 해시로 암호를 제공
cleartext 암호는 원격 서버를 전송하기전에 해시로 전환
인증을 완료하는데에 Cleartext 암호는 필요하지 않음
기능적으로 해시는 원래 암호와 동일
→ Complete network 인증올 완료하는데에는 hash만 있으면 된다.
</br>

## Pass-the-Hash 공격 과정
1. 시스템에 침투
2. 시스템의 보호된 자원에 접근할 수 있는 권한 획득
3. 메모리 상에 있는 Password Hash값 수집
4. 새로운 logon session을 생성하여 획득한 hash 값으로 접속
→ LM/NTLM 인증 프로토콜을 사용하는 Network의 특정 시스템에 침투한 후에는, Network에 연결된 다른 시스템에 속한 모든 시스템에도 침투할 수 있다.
(보통 사용자는 Password를 플랫폼마다 바꾸지 않음을 이용한다.)

# 따라서 우리는 'Pass the Hash' 공격을 하기위해 다음과 같은 모듈을 사용할 것이다.

## Metasploit PsExec
→ PSExec 모듈은 암호학적 개인정보를 이미 알고있는 특정 시스템에 대한 접근을 얻기 위해 침투테스터에 의해 사용된다.

# Metasploit PsExec를 사용하기 위해 필요한 것
1. 타겟 IP
2. 타겟 시스템의 username
3. Password Hash(or Password)
4. Administractive Shares
우리는 가상환경에 설치한 winXP, windows 8 에 대한 대다수의 정보 가지고 있다. win xp와 windows 8을 PsExec 모듈을 사용하여 해킹할 것이다.

그렇다면 가장 중요한 Hash 암호는 어떻게 모을 것인가?
→ 미터프리터를 사용한다!
