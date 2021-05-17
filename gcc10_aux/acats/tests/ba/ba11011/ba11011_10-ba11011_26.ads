                                           -- BA11011_24 is not a library unit.

-------------------------------------------------------
with BA11011_10.BA11011_23;
generic 
package BA11011_10.BA11011_26 is
   generic package BA11011_27 renames 
     BA11011_10.BA11011_23.BA11011_24;                                -- ERROR:
                     -- BA11011_10.BA11011_23.BA11011_24 is not a library unit.
end BA11011_10.BA11011_26;
