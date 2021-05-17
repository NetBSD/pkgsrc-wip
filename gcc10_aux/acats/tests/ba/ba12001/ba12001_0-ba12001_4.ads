                       
     --=================================================================--

-- Public child

with BA12001_0.BA12001_1;                                            -- ERROR:
                                         -- private child of the same ancestor

with BA12001_0.BA12001_1.BA12001_2;                                  -- ERROR:
                                         -- private child of the same ancestor

with BA12001_0.BA12001_1.BA12001_3;                                  -- ERROR:
                                         -- private child of the same ancestor

package BA12001_0.BA12001_4 is

   Public_Child_Var : Grandparent_Type := 21;

end BA12001_0.BA12001_4;


-- No body for BA12001_0.BA12001_4.
