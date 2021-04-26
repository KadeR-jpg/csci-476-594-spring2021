import sqlite3
from sqlite3 import Error
from sqlite3.dbapi2 import Cursor, SQLITE_CREATE_TABLE, connect

def create_conn(path):
    connection = None
    try:
        connection = sqlite3.connect(path)
        print("Connection Successful")
    except Error as e:
        print(f'The error {e} occured')
    return connection   

def exe_query(connection, query):
    cursor = connection.cursor()
    try:
        cursor.execute(query)
        connection.commit()
        print("Query executed successfully")
    except Error as e:
        print(f"The error {e} occurred")

def exe_read_query(connection, query):
    cursor = connection.cursor()
    result = None
    try:
        cursor.execute(query)
        result = cursor.fetchall()
        return result
    except Error as e:
        print(f"The error {e} occurred")

create_user_table = """
    CREATE TABLE IF NOT EXISTS users (
        eid INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        pwd TEXT NOT NULL,
        salary INTEGER
    );
"""

create_users = """
INSERT INTO users(eid, name, pwd, salary)
VALUES
  (1234, 'Jeb', 'seedjeb', 80000),
  (1235, 'Jub', 'seedjub', 80000),
  (1236, 'Jab', 'seedjab', 80000),
  (1237, 'Job', 'seedjob', 80000),
  (1238, 'Paul', 'seedpaul', 10000);
"""


connection = create_conn('csci-476-594-spring2021-private\lab09\pyData.sqlite')
exe_query(connection, create_user_table)
exe_query(connection, create_users)
select_users = "SELECT * FROM users"
users = exe_read_query(connection, select_users)
print("THE TABLE users")
for user in users:
    print(user)
eid_inpt = 1234
pwd_inpt = "'; UPDATE users SET salary = 100 WHERE name='Paul';"
exe_stmt = f"SELECT * FROM users WHERE eid = {eid_inpt} AND pwd = '{pwd_inpt}"
print(exe_stmt)
usr_out = connection.executescript(exe_stmt)
for u in usr_out:
    print(u)
select_users = "SELECT * FROM users"
updated_users = exe_read_query(connection, select_users)
print("THE TABLE users")
for user in users:
    print(user)



