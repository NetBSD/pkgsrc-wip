#!/usr/bin/env bash
#
# Create role and database for PostgreSQL.

dbuser=dotclear
dbname=dotclear

createuser --no-createdb --encrypted --no-superuser --pwprompt \
	--username=pgsql ${dbuser}
createdb --owner==${dbuser} --username=pgsql ${dbname}
