
     --=================================================================--

with B392004_0;
procedure B392004 is

   Specific_Type_Const   :  constant B392004_0.Tagged_Type
                         := B392004_0.Tagged_Type'(Field => false);
   Specific_Type_Var     :  B392004_0.Tagged_Type
                         := B392004_0.Tagged_Type'(Field => false);
   Dynamic_Tagged_Obj    :  B392004_0.Tagged_Type'class
                         := B392004_0.Tagged_Type'(Field => false);
   Dynamic_Tagged_Const  :  constant B392004_0.Tagged_Type'class
                         := B392004_0.Tagged_Type'(Field => false);

   Specific_Type_Obj_1   :  constant B392004_0.Tagged_Type
                         := Dynamic_Tagged_Obj;              -- ERROR: {1:38;1}
                          -- Expected type of constant is specific tagged type.

   Specific_Type_Obj_2   :  B392004_0.Tagged_Type
                         := Dynamic_Tagged_Const;            -- ERROR: {1:29;1}
                          -- Expected type of variable is specific tagged type.

   Specific_Type_Obj_3   :  B392004_0.Tagged_Type
                         := B392004_0.No_Parm;               -- ERROR: {1:29;1}
                          -- Expected type of variable is specific tagged type.

   Specific_Type_Obj_4   :  B392004_0.Tagged_Type
     := B392004_0.Tagged_Type'Class(Specific_Type_Var);      -- ERROR: {1:29;1}
                          -- Expected type of variable is specific tagged type.

   Class_Wide_Acc_Obj    :  B392004_0.Access_To_Class_Wide_Type
                         := new B392004_0.Tagged_Type;       -- OK. {1:29;1}

   Rec_Obj : B392004_0.Rec_Anon_Acc_Disc (Class_Wide_Acc_Obj);-- ERROR: {14;1}
                           -- Expected type of discriminant is anonymous access
                           -- to specific tagged type.

   procedure Anon_Acc_Parm_Proc_1 (P : access B392004_0.Tagged_Type
     := Class_Wide_Acc_Obj) is                               -- ERROR: {1:36;4}
   begin                   -- Expected type of operand is anonymous access to
      null;                -- specific tagged type.
   end Anon_Acc_Parm_Proc_1;

   -----------------------------------------
   procedure Specific_Type_Parm_Proc
     (P : B392004_0.Tagged_Type) is
   begin
      null;
   end Specific_Type_Parm_Proc;

   -----------------------------------------
   procedure Anon_Acc_Parm_Proc_2
     (P : access B392004_0.Tagged_Type) is
   begin
      null;
   end Anon_Acc_Parm_Proc_2;

begin

   Specific_Type_Var := Dynamic_Tagged_Obj;                   -- ERROR: {4;1}
                         -- Expected type of variable is specific tagged type.

   Specific_Type_Var := B392004_0.No_Parm;                    -- ERROR: {4;1}
                         -- Expected type of variable is specific tagged type.

   Specific_Type_Var := B392004_0.One_Parm (B392004_0.No_Parm);-- ERROR: {4;1}
                         -- Expected type of variable is specific tagged type.

   Specific_Type_Var := B392004_0.One_Parm (Dynamic_Tagged_Obj);-- ERROR: {4;1}
                         -- Expected type of variable is specific tagged type.

   Specific_Type_Var := B392004_0.One_Parm
     (B392004_0.Tagged_Type'Class (Specific_Type_Var));       -- ERROR: {1:4;1}
                         -- Expected type of variable is specific tagged type.

   Specific_Type_Parm_Proc (Dynamic_Tagged_Obj);              -- ERROR: {4;1}
                           -- Expected type of actual is specific tagged type.

   Specific_Type_Parm_Proc (B392004_0.No_Parm);               -- ERROR: {4;1}
                           -- Expected type of actual is specific tagged type.

   Specific_Type_Parm_Proc
     (B392004_0.Tagged_Type'Class (Specific_Type_Var));       -- ERROR: {1:4;1}
                           -- Expected type of actual is specific tagged type.

   Anon_Acc_Parm_Proc_2 (Class_Wide_Acc_Obj);                 -- ERROR: {4;1}
                           -- Expected type of parameter is anonymous access
                           -- to specific tagged type.

   B392004_0.Proc_Specific_Type_Parms
     (Specific_Type_Var, Specific_Type_Const);                -- OK. {1:4;1}

   B392004_0.Proc_Specific_Type_Parms
     (Dynamic_Tagged_Obj, Dynamic_Tagged_Const);              -- OK. {1:4;1}

   B392004_0.Proc_Specific_Type_Parms
     (Specific_Type_Var, Dynamic_Tagged_Obj);                 -- ERROR: {1:4;1}
                                         -- Mixed tagged controlling operands.

   B392004_0.Proc_Specific_Type_Parms
     (Specific_Type_Var, B392004_0.No_Parm);                  -- ERROR: {1:4;1}
                                         -- Mixed tagged controlling operands.

   B392004_0.Proc_Specific_Type_Parms (Specific_Type_Var,
      B392004_0.Tagged_Type'Class(Specific_Type_Var));        -- ERROR: {1:4;1}
                                         -- Mixed tagged controlling operands.

   B392004_0.Proc_Specific_Type_Parms (Specific_Type_Var,
     B392004_0.One_Parm (B392004_0.No_Parm));                 -- ERROR: {1:4;1}
                                         -- Mixed tagged controlling operands.

   B392004_0.Proc_Specific_Type_Parms (Specific_Type_Var,
     B392004_0.One_Parm (Dynamic_Tagged_Obj));                -- ERROR: {1:4;1}
                                         -- Mixed tagged controlling operands.

   B392004_0.Proc_Specific_Type_Parms (Specific_Type_Var,
     B392004_0.Tagged_Type'(B392004_0.One_Parm
       (Dynamic_Tagged_Obj)));                                -- ERROR: {2:4;1}
                                         -- Mixed tagged controlling operands.
end B392004;
