# [User guide](user_manual.md)



> [!IMPORTANT]  
> Need to install ansible run the following
<br>
`sudo apt-add-repository --yes --update ppa:ansible/ansible && sudo apt install ansible`

<br>

> [!IMPORTANT]  
> Cannot find community.general.snap 
<br>
`ansible-galaxy collection install community.general`

<br>

> [!CAUTION]
> terminate called after throwing an instance of 'std::filesystem::__cxx11::filesystem_error'
>  what():  filesystem error: cannot create directory: Permission denied [/etc/ansible/playbooks]
### Run the following
`sudo chown -R {user}:{group} /etc/ansible`
> [!NOTE]  
> Group is optional, if your ansible folder is in a different location, place it as such!

Example
sudo chown -R knovel /etc/ansible