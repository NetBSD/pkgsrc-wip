
     --=================================================================--

with B392006_0;
package B392006 is

   type New_Tag is new B392006_0.Tag with
     record
        New_Field : Integer;
     end record;

   -- Need to override Func_1_1 and Func_2_1.  
   function Func_1_1 (P1 : B392006_0.Tag'Class)     return New_Tag; 
   function Func_2_1 (P1, P2 : B392006_0.Tag'Class) return New_Tag;   

   function No_Parm_1 return New_Tag;                   -- Calls to No_Parm_1
                                                        -- will not have a 
                                                        -- controlling operand.
   function No_Parm_2 return New_Tag'Class;             -- Function returning
                                                        -- class-wide value.
   -- A class-wide deferred constant.
   Deferred_Class_Wide_Const : constant New_Tag'Class;

   -- Dispatching operations on New_Tag.

   procedure Proc_1 (P : New_Tag := No_Parm_1);                       -- OK.

   procedure Proc_2 (P : New_Tag := Deferred_Class_Wide_Const);       -- ERROR:
                                           -- Default expression is class-wide.

   procedure Proc_3 (P : New_Tag := Func_1_1 
                                    (Deferred_Class_Wide_Const));     -- OK.

   procedure Proc_4 (P : New_Tag := Func_2_1 
     (Deferred_Class_Wide_Const, No_Parm_1));                         -- OK.

   procedure Proc_5 (P : New_Tag := No_Parm_2);                       -- ERROR:
                                           -- Default expression is class-wide.

   procedure Proc_6 (P : New_Tag := Func_1_1 (No_Parm_2));            -- OK.

private
   Deferred_Class_Wide_Const :  constant New_Tag'Class
                             := New_Tag'(Field => False, New_Field => 12);
end B392006;
