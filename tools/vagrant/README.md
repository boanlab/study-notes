# Vagrant

- 가상 머신을 통해 개발 환경을 자동으로 생성/관리하게 도와주는 툴이다
- VirtualBox와 기본적으로 연동되지만, VMware Workstation/Fusion 등 다른 플랫폼과도 연동 가능하다

## 1. Vagrant 다운로드 및 설치

- 아래의 링크로 들어가서 운영체제에 맞는 버전의 Vagrant를 다운로드 받은 후 설치한다

  [https://www.vagrantup.com/downloads](https://www.vagrantup.com/downloads)

- (옵션) VirtualBox가 설치되어 있지 않다면, 아래의 링크로 들어가서 운영체제에 맞는 버전의 VirtualBox를 다운로드 받은 후 설치한다

  [https://www.virtualbox.org/wiki/Downloads](https://www.virtualbox.org/wiki/Downloads)

## 2. 가상 머신 (Virtual Machine, VM)에서 사용할 운영체제 검색

- Vagrant를 통해 다양한 운영체제를 쉽게 설치하고 사용할 수 있도록 다양한 운영체제를 제공한다
- 원하는 운영체제가 있다면 Vagrant Cloud에서 검색해서 설치 가능 여부를 판단해볼 수 있다

  [https://app.vagrantup.com/boxes/search](https://app.vagrantup.com/boxes/search)

- 예를 들어, 우분투를 사용하고 싶다면, Ubuntu를 검색해 볼 수 있으며 여러 버전의 Ubuntu를 확인해 볼 수 있을 것이다
    
  [https://app.vagrantup.com/ubuntu](https://app.vagrantup.com/ubuntu)

## 3. 생성하고자 하는 가상 머신에 대한 환경 설정

- Vagrant에서는 'Vagrantfile' 이라는 이름의 환경 설정 파일을 사용한다
- 그리고 Vagrantfile에 가상 머신에 대한 환경 설정 방법은 아래와 같다

    ```
    Vagrant.configure("2") do |config|
        # 사용할 운영체제 이미지 (e.g., ubuntu/focal64)
        # https://app.vagrantup.com/boxes/search에서 이미지 찾음
        config.vm.box = "vm_image"

        config.vm.provider "virtualbox" do |vb|
            # VM 이름
            vb.name = "vm_name"
            # VM에 할당할 CPU 코어 개수
            vb.cpus = 4
            # VM에 할당할 메모리 크기
            vb.memory = 8192
        end

        # VM 내에서 사용할 호스트 이름
        config.vm.hostname = "vm_hostname"

        # 만약 호스트에서 VM 내 서비스를 이용하고 싶다면?
        config.vm.network :forwarded_port, host: 8080, guest: 80

        # VM을 생성하는 과정에서 특정 명령어들을 실행하고 싶다면?
        config.vm.provision :shell, :inline => "명령어"

        # 호스트에 위치한 디렉토리를 VM 내에서 사용하고 싶다면?
        config.vm.provision "file", source: "호스트에 위치한 파일", destination: "VM 내 복사할 파일"

        # if you want to use host-side files in the VM-side,
        # you can use 'synced_folder' to do so
        config.vm.synced_folder "호스트에 위치한 디렉토리 위치", "VM 내에서의 디렉토리 위치", owner:"vagrant", group:"vagrant"

        # VM 생성 과정에서 특정 명령어 실행 후 재부팅이 필요하다면?
        config.vm.provision :reload
    end
    ```

    - 좀 더 자세한 내용이 궁금하다면, 아래의 링크에서 확인해볼 수 있다

        [https://friendsofvagrant.github.io/v1/docs/vagrantfile.html](https://friendsofvagrant.github.io/v1/docs/vagrantfile.html)

## 4. Vagrant 명령어

- Vagrant에서 기본적으로 4개의 명령어만 알면 충분하다

  - vagrant up

      - 현재 위치의 Vagrantfile을 이용하여 VM 생성

  - vagrant halt

      - VM 종료

  - vagrant destroy

      - VM 삭제

  - vagrant ssh

      - SSH를 통해 VM 접속

- 사용할 일이 거의 없지만, 알고만 있자

  - vagrant init

    - Vagrant 템플릿 생성
    - Vagrantfile을 직접 만들었다면 vagrant init을 실행할 필요가 없다

## 5. Vagrant를 통해 가상 
머신 
머신 생성

