
     --==================================================================--

private package B330001_0.B330001_1 is

   Priv_Child_Indef_Var_W_Int :  FullViewIsIndefinite
                              := Indef_Func (4);                     -- OK.

   Priv_Child_Indef_Var       :  FullViewIsIndefinite;               -- ERROR:
                             -- Subtype is unconstrained and no initialization
                             -- expression.

   type Priv_Child_Array_Indef is
     array (1 .. 2) of FullViewIsIndefinite;                         -- ERROR:
                                           -- Component subtype is indefinite.

   Priv_Child_Def_Var_W_Int   :  FullViewIsDefinite
                              := Def_Func (4);                       -- OK.

   Priv_Child_Def_Var         :  FullViewIsDefinite;                 -- OK.

   type Priv_Child_Array_Def is array (1 .. 2) of FullViewIsDefinite;-- OK.

end B330001_0.B330001_1;
