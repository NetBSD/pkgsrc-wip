
     --=================================================================--

with BA12008_0;                                                      -- OK
with BA12008_0.BA12008_1;                                            -- OK
with BA12008_0.BA12008_1.BA12008_2;                                  -- OK
with BA12008_0.BA12008_1.BA12008_2.BA12008_3;                        -- OK

with BA12008_3;                                                      -- ERROR:
                                          -- Great grandchild simple name.

with BA12008_0.BA12008_2;                                            -- ERROR:
                                          -- Parent.Grandchild name.

with BA12008_0.BA12008_3;                                            -- ERROR:
                                          -- Parent.Great grandchild name.

with BA12008_1;                                                      -- ERROR:
                                          -- Child simple name.

with BA12008_1.BA12008_2;                                            -- ERROR:
                                          -- Child.Grandchild name.

with BA12008_1.BA12008_3;                                            -- ERROR:
                                          -- Child.Great grandchild name.

with BA12008_2;                                                      -- ERROR:
                                          -- Grandchild simple name.

with BA12008_2.BA12008_3;                                            -- ERROR:
                                          -- Grandchild.Great grandchild name.

procedure BA12008 is

   Client_Var : BA12008_0.Parent_Type := 35;

begin
   null;
end BA12008;
