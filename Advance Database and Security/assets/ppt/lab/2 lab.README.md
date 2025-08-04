# Modeling and comparing data in Relational vs NoSQL (Document, Key-Value)

- [Facebook modelling](https://upload.wikimedia.org/wikipedia/commons/9/95/Metamodel_of_Facebook.jpg)
- [Instagram schema](https://upload.wikimedia.org/wikipedia/commons/thumb/9/94/MediaWiki_1.28.0_database_schema.svg/1750px-MediaWiki_1.28.0_database_schema.svg.png)
- [Wikipedia schema](https://upload.wikimedia.org/wikipedia/commons/f/f8/MediaWiki_1.10_dbschema.svg)

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

<br>
<br>

## Data type

- [My SQL reference](https://dev.mysql.com/doc/refman/8.4/en/data-types.html)

<br>

#### How to create a new table inside database

```sql
CREATE DATABASE pet_shop;
USE pet_shop;
SELECT database();


-- Main code --
CREATE TABLE cats (
    name VARCHAR(50),
    age INT
);

CREATE TABLE dogs (
    name VARCHAR(50),
    breed VARCHAR(50),
    age INT
);
```

<br>

#### How to get structure of table

```sql
-- How to get all table from database
SHOW tables;

-- How to get columns/header with type of specific table
SHOW COLUMNS FROM cats;

-- (Shortcut) How to get columns/header with type of specific table
DESC cats;
```

<br>

#### How to delete a table from database

To drop a table: DROP TABLE <table-name>;

```sql
DROP TABLE cats;
```

<br>
<br>

## Inserting Data into table

#### How to insert data into table

Lets create a cats table first

```sql
CREATE TABLE cats (
    name VARCHAR(50),
    age INT
);
```

Lets insert information/data into cats table

```sql
INSERT INTO cats (name, age)
VALUES ('Blue Steele', 5);

INSERT INTO cats (name, age)
VALUES ('Jenkins', 7);
```

<br>

#### How to get everything from cats table

To view all rows in our table:

```sql
SELECT * FROM cats;
```

<br>

#### How to do multiple insert into cats table

```sql
INSERT INTO cats (name, age)
VALUES
  ('Tom', 5),
  ('Timmy', 1),
  ('Potato Face', 15);

-- to get everything from cats table
SELECT * FROM cats;
```

<br>

#### How to add NOT NULL constrain in table structure

```sql
-- create new table cats2
CREATE TABLE cats2 (
    name VARCHAR(100) NOT NULL,
    age INT NOT NULL
);


-- 🔴 (gives error) insert multiple data into cats2 table
INSERT INTO cats (name, age)
VALUES
  ('Tom', 5),
  ('Timmy', ),
  ('Potato Face', 15);


-- ✅ insert multiple data into cats2 table
INSERT INTO cats (name, age)
VALUES
  ('Tom', 5),
  ('Timmy', 1),
  ('Potato Face', 15);
```

<br>
