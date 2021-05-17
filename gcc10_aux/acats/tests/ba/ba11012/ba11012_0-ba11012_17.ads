
-------------------------------------------------------
with BA11012_0.BA11012_1;               -- private generic parent package.
private
generic 
package BA11012_0.BA11012_17 is
   generic package BA11012_18 renames BA11012_0.BA11012_1;            -- OK.
end BA11012_0.BA11012_17;
