#!/bin/sh

LUA_CPATH='/usr/local/lib/lua/5.0/?.so'
LUA_PATH='/usr/local/share/dfuibe_lua/lib/?.lua'

exec /usr/local/bin/lua -l/usr/local/share/lua/5.0/compat-5.1.lua $*
