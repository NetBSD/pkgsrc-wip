-- Lua socket autoloader for Debian
-- Use this with require "luasocket";

if( loadlib == nil ) then
   error( "Unable to load LuaSocket library. No Loadlib found" );
end

local libfile = "/usr/pkg/lib/libluasocket.so.2.0";
local funcname = "luaopen_socket";

local func,os_err,canonical_err;

func, os_err, canonical_err = loadlib( libfile, funcname );

if( not func ) then
   if( canonical_err == "absent" ) then
      error( "Unable to load LuaSocket library. Lua built without loadlib." );
   end
   if( canonical_err == "init" ) then
      error( "Luasocket library ("..libfile..") is missing init function ("..funcname..")\nOS said: "..os_err);
   end
   if( canonical_err == "open" ) then
      error( "Luasocket library ("..libfile..") cannot be loaded.\nOS said: "..os_err);
   end
end

-- Luasocket library loaded, call it...

func();

if not LUASOCKET_LIBNAME then 
   error("LuaSocket initialisation failed")
end
