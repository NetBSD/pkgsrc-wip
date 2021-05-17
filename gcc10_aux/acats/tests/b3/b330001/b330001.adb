
     --==================================================================--

with B330001_0;
procedure B330001 is

   Constraint_Arr_Var     :  B330001_0.Uncons_Arr_Type (1..3, 1..3);

   Constraint_Rec_Var     :  B330001_0.Uncons_Rec_Type (4);

   Uncons_Rec_Var_W_Int   :  B330001_0.Uncons_Rec_Type
                          := (Side => 3, Com => Constraint_Arr_Var); -- OK.

   Uncons_Tag_Var_W_Int   :  B330001_0.Uncons_Tag_Type
       := ( Dimension => 1, Left => Constraint_Rec_Var,
            Right     => (Side => 3, Com => Constraint_Arr_Var) );   -- OK.

   Constraint_Prot_Var    :  B330001_0.Protected_Type (7);           -- OK.

   Uncons_Prot_Var        :  B330001_0.Protected_Type;               -- ERROR:
                                                  -- Subtype is unconstrained.

   Constraint_Task_Var    :  B330001_0.Task_Type (42);               -- OK.

   Uncons_Task_Var        :  B330001_0.Task_Type;                    -- ERROR:
                                                  -- Subtype is unconstrained.

   Uncons_Indef_Var       :  B330001_0.FullViewIsIndefinite;         -- ERROR:
                 -- Subtype is unconstrained and no initialization expression.

   My_Var                 :  B330001_0.Sub_Type := 3;

   Uncons_Indef_Var_W_Int :  B330001_0.FullViewIsIndefinite
                          := B330001_0.Indef_Func (My_Var);          -- OK.

   Uncons_NTag_Var        :  B330001_0.NUncons_Tag_Type;             -- ERROR:
                 -- Subtype is unconstrained and no initialization expression.

   Uncons_Def_Var_W_Int   :   B330001_0.FullViewIsDefinite
                          :=  B330001_0.Def_Func (4);                -- OK.

   Uncons_Def_Var         :   B330001_0.FullViewIsDefinite;          -- ERROR:
                 -- Subtype is unconstrained and no initialization expression.

   type Def_Array is array (1 .. 2) of B330001_0.FullViewIsDefinite; -- ERROR:
                                           -- Component subtype is indefinite.

   type Rec_Of_Protected_Type is record
      Field : B330001_0.Protected_Type;                              -- ERROR:
                                           -- Component subtype is indefinite.
   end record;

   type Arr is array (1 .. 3) of B330001_0.Uncons_Tag_Type;          -- ERROR:
                                           -- Component subtype is indefinite.

   type Indef_Array is array (1 .. 3) of
     B330001_0.FullViewIsIndefinite;                                 -- ERROR:
                                           -- Component subtype is indefinite.

   type Tag_Arr is array (1 .. 3) of B330001_0.Cons_Tag_Type;        -- OK.

   type CW_Rec is record
     Component : B330001_0.Cons_Tag_Type'Class;                      -- ERROR:
                                           -- Component subtype is indefinite.
   end record;

   type CW_Arr is array (1 .. 3) of B330001_0.Cons_Tag_Type'Class;   -- ERROR:
                                           -- Component subtype is indefinite.

   type Flt_Arr is array (Positive range <>) of Float;

   Flt_Arr_Var : Flt_Arr (1 .. 25);

   Arr_Of_Arr : array (1 .. 2) of Flt_Arr := (others => Flt_Arr_Var);-- ERROR:
                                           -- Component subtype is indefinite.

   Int_Arr_W_Init :  array (Positive range <>) of Integer
                  := (1, 2, 3, 4, 5, 6, 7);                          -- OK.

   Int_Arr : array (Positive range <>) of Integer;                   -- ERROR:
                                   -- Indefinite since index is unconstrained.

begin
   null;
end B330001;
