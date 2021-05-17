                                -- BA11011_20.BA11011_11 is not a library unit.
                       -- BA11011_20.BA11011_11 is not an explicit declaration.

-------------------------------------------------------
with BA11011_10.BA11011_11;
generic 
package BA11011_10.BA11011_23 is
   generic package BA11011_24 renames BA11011_10.BA11011_11;          -- OK.
end BA11011_10.BA11011_23;
