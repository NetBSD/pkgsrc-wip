
      --=================================================================--
 
with BA11008_0.BA11008_1.BA11008_2;   -- Generic grandchild package,
                                      -- implicitly with BA11008_0,
                                      -- BA11008_0.BA11008_1.
 
procedure BA11008 is
 
   package BA11008_22 is new BA11008_0.BA11008_1;                    -- ERROR:
                               -- Must be a child of an instance of BA11008_0.

   package BA11008_23 is new BA11008_0.BA11008_1.BA11008_2;          -- ERROR:
                     -- Must be a child of an instance of BA11008_0.BA11008_1.
 
begin
   null;
end BA11008;
