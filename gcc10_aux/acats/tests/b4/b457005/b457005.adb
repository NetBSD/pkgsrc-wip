
     --=================================================================--

with B457005_0;
procedure B457005 is

   Bool : Boolean := False;

   type Colors is (Red, Yellow, Green, Blue);

   Team : Colors := Red;

   Specific_Type_Const   :  constant B457005_0.Tagged_Type
                         := B457005_0.Tagged_Type'(Field => false);
   Specific_Type_Var     :  B457005_0.Tagged_Type
                         := B457005_0.Tagged_Type'(Field => false);
   Dynamic_Tagged_Obj    :  B457005_0.Tagged_Type'class
                         := B457005_0.Tagged_Type'(Field => false);
   Dynamic_Tagged_Const  :  constant B457005_0.Tagged_Type'class
                         := B457005_0.Tagged_Type'(Field => false);

begin

   Specific_Type_Var := (if Bool then Dynamic_Tagged_Obj
                                 else Specific_Type_Const);          -- ERROR:

   Specific_Type_Var := (if Bool then Dynamic_Tagged_Obj
                                 else B457005_0.Indeterminate);      -- ERROR:

   Specific_Type_Var := (case Team is
                            when Red | Yellow => Dynamic_Tagged_Obj,
                            when Blue => B457005_0.No_Parm,
                            when Green => Specific_Type_Const);      -- ERROR:

   Specific_Type_Var := (case Team is
                            when Red | Yellow => B457005_0.Indeterminate,
                            when Blue => B457005_0.No_Parm,
                            when Green => Dynamic_Tagged_Obj);       -- ERROR:

   -- Dispatching calls:
   B457005_0.Proc_One_Parm (if Bool then Specific_Type_Var
                                   else Specific_Type_Const);        -- OK.
   B457005_0.Proc_One_Parm (case Team is
                            when Red | Yellow => Specific_Type_Const,
                            when Blue | Green => Specific_Type_Var); -- OK.

   B457005_0.Proc_One_Parm (if Bool then Dynamic_Tagged_Obj
                                   else B457005_0.No_Parm);          -- OK.
   B457005_0.Proc_One_Parm (case Team is
                            when Red | Yellow => Dynamic_Tagged_Obj,
                            when Blue | Green => B457005_0.No_Parm); -- OK.

   B457005_0.Proc_One_Parm (if Bool then Specific_Type_Const
                            elsif (not Bool) then Specific_Type_Var
                                   else B457005_0.No_Parm);          -- ERROR:

   B457005_0.Proc_One_Parm (case Team is
                            when Red | Yellow =>
                                 B457005_0.One_Parm (B457005_0.No_Parm),
                            when Blue => Specific_Type_Var,
                            when Green => Specific_Type_Const);      -- ERROR:

   B457005_0.Proc_One_Parm (if Bool then B457005_0.Indeterminate
                                 else B457005_0.No_Parm);            -- ERROR:

   B457005_0.Proc_One_Parm (case Team is
                            when Red | Yellow =>
                                 B457005_0.One_Parm (B457005_0.No_Parm),
                            when Blue => B457005_0.Indeterminate,
                            when Green => Dynamic_Tagged_Obj);       -- ERROR:

   B457005_0.Proc_One_Parm (if Bool then B457005_0.Indeterminate
                                 else Specific_Type_Const);          -- OK.

   B457005_0.Proc_One_Parm (case Team is
                            when Red | Yellow =>
                                 B457005_0.One_Parm (Specific_Type_Var),
                            when Blue => B457005_0.Indeterminate,
                            when Green => Specific_Type_Const);      -- OK.

   -- If the expression is dynamically tagged, the rule doesn't apply:
   Dynamic_Tagged_Obj := (if Bool then Dynamic_Tagged_Obj
                                 else Specific_Type_Const);          -- OK.

   Dynamic_Tagged_Obj := (case Team is
                            when Red | Yellow => Dynamic_Tagged_Obj,
                            when Blue => B457005_0.No_Parm,
                            when Green => Specific_Type_Const);      -- OK.


end B457005;

