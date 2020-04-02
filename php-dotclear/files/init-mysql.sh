#!/usr/bin/env bash
#
# Create role and database for MySQL.

dbuser=dotclear
dbname=dotclear

echo -n "Enter administrator password: "
read -s admpasswd
echo ""
echo -n "Enter ${dbuser} user password: "
read -s dcpasswd
echo ""
echo "CREATE USER '${dbuser}'@'localhost' IDENTIFIED BY '${dcpasswd}';" | mysql --password=${admpasswd}
echo "CREATE DATABASE ${dbname};" | mysql --password=${admpasswd}
echo "GRANT ALL ON ${dbname}.* TO '${dbuser}'@'localhost';" | mysql --password=${admpasswd}
