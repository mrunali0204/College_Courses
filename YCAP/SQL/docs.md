SQL (Structured Query Language)

* use
1.Store data
2.Retrieve data
3.Update data
4.Delete data

Databases like:
MySQL
PostgreSQL
Oracle Database
Microsoft SQL Server

* commands:

1. SELECT (Read Data)

Get all data:

SELECT * FROM students;


Get specific columns:

SELECT name, age FROM students;

🔹 2. WHERE (Filter Data)

Get only CSE students:

SELECT * FROM students
WHERE branch = 'CSE';


Get students age > 19:

SELECT * FROM students
WHERE age > 19;

🔹 3. INSERT (Add Data)
INSERT INTO students (id, name, age, branch)
VALUES (4, 'Priya', 22, 'IT');

🔹 4. UPDATE (Modify Data)

Change Rahul’s age to 21:

UPDATE students
SET age = 21
WHERE name = 'Rahul';


* Always use WHERE in UPDATE.

🔹 5. DELETE (Remove Data)
DELETE FROM students
WHERE id = 3;