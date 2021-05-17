
     --==================================================================--

package B330001_0.B330001_2 is

   Pub_Child_Indef_Var_W_Int :  FullViewIsIndefinite
                             := Indef_Func (4);                      -- OK.

   Pub_Child_Indef_Var       :  FullViewIsIndefinite;                -- ERROR:
                 -- Subtype is unconstrained and no initialization expression.

   type Pub_Child_Array_Indef is
     array (1 .. 2) of FullViewIsIndefinite;                         -- ERROR:
                                           -- Component subtype is indefinite.

   Pub_Child_Def_Var_W_Int   :  FullViewIsDefinite
                             := Def_Func (4);                        -- OK.

   Pub_Child_Def_Var         :  FullViewIsDefinite;                  -- ERROR:
 -- Partial view of subtype is unconstrained and no initialization expression.

   type Pub_Child_Array_Def is
     array (1 .. 2) of FullViewIsDefinite;                           -- ERROR:
                                           -- Component subtype is indefinite.

end B330001_0.B330001_2;
