
     --=================================================================--

with BA12004_0.BA12004_1;                                          -- OK.

with BA12004_0.BA12004_2;                                          -- ERROR:
                          -- Child BA12004_2 is not visible in this context.

with BA12004_0.BA12004_1.BA12004_3;                                -- ERROR:
                          -- Child BA12004_3 is not visible in this context.

with BA12004_0.BA12004_2.BA12004_4;                                -- ERROR:
                          -- Child BA12004_4 is not visible in this context.

with BA12004_0.BA12004_2.BA12004_4.BA12004_5;                      -- ERROR:
                          -- Child BA12004_5 is not visible in this context.

package BA12004 is

   Client_Var : BA12004_0.Grandparent_Type := 451;

end BA12004;
