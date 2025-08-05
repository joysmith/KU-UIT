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

#### How to add NOT-NULL constrain in table structure

```sql
-- create new table movie
CREATE TABLE movie (
    name VARCHAR(100) NOT NULL,
    age INT NOT NULL
);


-- 🔴 (gives error) insert multiple data into cats2 table
INSERT INTO movie(name, age)
VALUES
  ('Tom', 5),
  ('Timmy', ),
  ('Potato Face', 15);


-- ✅ insert multiple data into cats2 table
INSERT INTO movie (name, age)
VALUES
  ('Tom', 5),
  ('Timmy', 1),
  ('Potato Face', 15);
```

<br>

#### How to define table with default value

```sql
CREATE TABLE marvel  (
    name VARCHAR(20) DEFAULT 'no name provided',
    age INT DEFAULT 99
);

-- Notice the change when you describe the table:
DESC marvel;

-- Insert a marvel character without a name but give age:
INSERT INTO marvel(age) VALUES(13);

-- Or a nameless, ageless cat:
INSERT INTO marvel() VALUES();
```

<br>

#### How to add primary key aka (unique id)

```sql
-- One way of specifying a PRIMARY KEY
CREATE TABLE songs (
	song_id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INT NOT NULL
);

-- Another option:
CREATE TABLE songs2 (
	song_id INT,
    name VARCHAR(100) NOT NULL,
    age INT NOT NULL,
    PRIMARY KEY (cat_id)
);

-- Inserting info/data to playlist
INSERT INTO songs(song_id, name, age) VALUES(99998, 'hall of fame', 3);
INSERT INTO songs(song_id, name, age) VALUES(99999, 'Super hero', 5);


-- to get everything from songs table
SELECT * FROM songs;
```

<br>

#### How to add-on "auto-increment" to primary key aka (unique id)

```sql
CREATE TABLE amazon_cart (
    item_id INT AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    price INT NOT NULL,
    PRIMARY KEY (item_id)
);


-- Inserting info/data to playlist
INSERT INTO amazon_cart(name, price) VALUES('playstation 5', 5000);
INSERT INTO amazon_cart(name, price) VALUES('playstation 5', 5000);
INSERT INTO amazon_cart(name, price) VALUES('playstation 5', 5000);
INSERT INTO amazon_cart(name, price) VALUES('playstation 5', 5000);
INSERT INTO amazon_cart(name, price) VALUES('playstation 5', 5000);
INSERT INTO amazon_cart(name, price) VALUES('playstation 5', 5000);
INSERT INTO amazon_cart(name, price) VALUES('playstation 5', 5000);


-- to get everything from songs table
SELECT * FROM amazon_cart;
```

<br>
<br>

## CRUD Operations

#### How to create table and insert data

```sql
-- Drop the current cats table (if you have one)
DROP TABLE cats;

-- Create the new cats table:
CREATE TABLE cats (
    cat_id INT AUTO_INCREMENT,
    name VARCHAR(100),
    breed VARCHAR(100),
    age INT,
    PRIMARY KEY (cat_id)
);

-- Insert some cats:
INSERT INTO cats(name, breed, age)
VALUES ('Ringo', 'Tabby', 4),
       ('Cindy', 'Maine Coon', 10),
       ('Dumbledore', 'Maine Coon', 11),
       ('Egg', 'Persian', 4),
       ('Misty', 'Tabby', 13),
       ('George Michael', 'Ragdoll', 9),
       ('Jackson', 'Sphynx', 7);
```

<br>

#### How to Read data

```sql
-- To get all the columns:
SELECT * FROM cats;

-- To only get the age column:
SELECT age FROM cats;

-- To select multiple specific columns:
SELECT name, breed FROM cats;
```

<br>

#### How to use 'where ' clause

```sql
-- Use where to specify a condition:
SELECT * FROM cats WHERE age = 4;

SELECT * FROM cats WHERE name ='Egg';

-- select specific column only by using condition
SELECT name, age FROM cats WHERE age = 4;
```

<br>

#### How to give header an alias when querying as output

```sql
-- Use 'AS' to alias a column in your results (it doesn't actually change the name of the column in the table)
SELECT cat_id AS id, name FROM cats;
```

<br>

#### How to Update data

```sql
-- Change tabby cats to shorthair:
UPDATE cats SET breed='Shorthair' WHERE breed='Tabby';

-- Another update:
UPDATE cats SET age=14 WHERE name='Misty';

-- Update all column:
UPDATE cats SET age=14;
```

<br>

#### How to delete

```sql
-- Delete all cats with name of 'Egg':
DELETE FROM cats WHERE name='Egg';

-- Delete all rows in the cats table:
DELETE FROM cats;
```

<br>
