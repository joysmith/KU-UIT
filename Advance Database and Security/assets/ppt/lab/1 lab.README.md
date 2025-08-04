# MySQL Installation on Windows

### 1. MySQL Installation Prerequisite

- **Microsoft Visual C++ 2019 Redistributable Package**: X86, X64 both donload [click me](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170)

<br>
<br>

### 2. MySQL Community Server

- **MySQL Community Server download link**: select LTS version MSI: typical [click me](https://dev.mysql.com/downloads/mysql/)
- (Optional) Archives for older versions of MySQL Community Server (if running an old Windows version): [click me](https://downloads.mysql.com/archives/community/)

<br>
<br>

### 3. MySQL in the command line (terminal):

#### Opt 1: CLI version by MySQL

- Go to window search and type "MySQL 8.4 command line CLI"
- enter password "admin"

#### Opt 2: CLI version on power shell

- First, we need to add MySQL to the **environment variables**.
- Go to search and type 'Environment' click --> environment variable--> System variable: path--> edit--> new
- copy binary file path and paste "C:\Program Files\MySQL Server 8.4\bin"
- Open power shell Then, we can use this command to start MySQL in the terminal:

```bash
mysql -u root -p
```

<br>
<br>

### 4. MySQL Workbench

- Download link: [click me](https://dev.mysql.com/downloads/workbench/)
- Launch, connect db, type cmd, click on ⚡

```sql
SHOW DATABASES
```

<br>
<br>

### 5. DbGate Community edition

- Download link: [click me](https://dbgate.org/download-community/)
