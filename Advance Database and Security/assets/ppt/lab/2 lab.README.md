# Modeling and comparing data in Relational vs NoSQL (Document, Key-Value)

#### How to get all databases

```sql
show databases;
```

<br>

#### How to create databases

- The general command for creating a database: **CREATE DATABASE <database_name>;**

```sql
CREATE DATABASE joy_mart_store;
show databases;
```

<br>

#### How to delete database

To drop a database: **DROP DATABASE <database-name>;**

```sql
DROP DATABASE joy_mart_store;

show databases;

```

<br>

#### How to switch database

To use a database: USE <database-name>;

```sql
USE joy_mart_store;
```

<br>

#### How to know current working database

To know current working database: SELECT <database-name>;

```sql
SELECT database();
```
