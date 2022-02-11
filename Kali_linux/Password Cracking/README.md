# Password Cracking
Password Cracking에는 4가지 종류가 있다.  
이 4가지 중에는 우리가 쉽게 생각할 수 있는 방법과 실제 2학년 2학기 정보보안에서 실습했던 Rainbow Hash Table 등 다양한 방법들이 있다.  

- Brute Force Attacks  
  - 모든 가능한 수단이 전부 시행된다.  
  - 패스워드 길이를 아는 것이 좋다.   
  (패스워드 길이가 길수록 올바른 패스워드를 찾는 데 걸리는 시간이 기하급수적으로 늘어나기 때문이다.)  
- Dictionary Attacks
  - 이미 만들어져 있는 워드리스트를 사용한다.  
  - 공격툴들이 다양한 방법들을 이용 - 대문자/소문자, 숫자를 앞뒤로 붙이기 등  
- Rainbow Table Attacks
  - 미리 컴파일된 잠재 해쉬들의 리스트해두고 이를 대입한다.  
  - 장점은 빠르지만 단점은 RAM을 많이 사용한다.
  이유는 모든 Table을 RAM에 올려두고 하나씩 수행하기 때문이다.  


## Password Hash
- Windows Hash
  UserName:UserID:LM Hash:NTML Hash:::  
  **이 구조는 실제 우리가 Pass The Hash를 할 때 미리 봤었다.**  
  ※LM Hash : 패스워드를 저장하는 데 사용되는 매우 약한 단방향 기능.  
- Linux Hash  
  UserName:Salt$Hash:Last Changed:Min:Max:Warn:::  
  /etc/shadows 파일들은 실제 패스워드를 암호화된 포맷으로 저장하는데, 해쉬나 사용자 계정의 정보를 담고 있다.  

## 패스워드 크래킹 툴
- HYDRA  
    - 온라인 패스워드 크래킹 툴 : 패스워드 해쉬에 직접 액세스하지 않고, 웹의 형태로 사용자이름과 패스워드를 요청한다. 매우 느리다.  
- Cain & Abel  
  - 패스워드 복원 툴. Microsoft OS에서 사용 가능.  
  - Brute Force Attack, Dictionary Attack, Rainbow Attack  
- John the Ripper  
  - 가장 유명한 패스워드 크래킹 툴 중 하나. Unix, Windows, OpenVMS 등에서 사용 가능.  
  - Brute Force Attack, Dictionary Attack, Rainbow Attack  
  - 수많은 패스워드 크래커들을 하나의 패키지로 합친다.  
  - 패스워드의 해쉬 타입을 자동으로 탐지한다.  
  - 세 가지 버전이 존재. (Free, Pro, Community-Enhanced)
