

-- No body for BA12003_0.BA12003_1.BA12003_3.BA12003_5.

     --=================================================================--

-- Public child

with BA12003_0.BA12003_1.BA12003_3;                 -- OK

with BA12003_0.BA12003_1.BA12003_3.BA12003_4;       -- OK

with BA12003_0.BA12003_1.BA12003_2;                                  -- ERROR:
                                   -- private descendant of (immediate) parent

with BA12003_0.BA12003_1.BA12003_3.BA12003_5;                        -- ERROR:
                                   -- private descendant of (immediate) parent

package BA12003_0.BA12003_1.BA12003_6 is

   Public_Child_Var : Grandparent_Type := 35;

end BA12003_0.BA12003_1.BA12003_6;


-- No body for BA12003_0.BA12003_1.BA12003_6.
