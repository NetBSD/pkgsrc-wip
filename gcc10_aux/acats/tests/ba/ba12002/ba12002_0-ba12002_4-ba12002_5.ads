

-- No body for BA12002_0.BA12002_4.

     --=================================================================--

-- Public grandchild

with BA12002_0.BA12002_1;                                            -- ERROR:
                                    -- private descendant of the same ancestor

with BA12002_0.BA12002_1.BA12002_2;                                  -- ERROR:
                                    -- private descendant of the same ancestor

with BA12002_0.BA12002_1.BA12002_3;                                  -- ERROR:
                                    -- private descendant of the same ancestor

package BA12002_0.BA12002_4.BA12002_5 is

   Public_Grandchild_Var : Child_Type := 532;

end BA12002_0.BA12002_4.BA12002_5;


-- No body for BA12002_0.BA12002_4.BA12002_5.
