
     --===================================================================--


with B393006_0;
with B393006_1;
with B393006_2;
package B393006 is

   type Nonabstract_Type is tagged record               -- Non-abstract type.
      Line : String (1 .. 80);
   end record;

   function Func return Nonabstract_Type;               -- Function with
                                                        -- controlling result
                                                        -- (no parameters).

   type Abstract_With_Proc is abstract tagged record    -- Abstract type with
      Msg : Nonabstract_Type;                           -- primitive subprog.
   end record;

   procedure Proc (Elem : Abstract_With_Proc)           -- Abstract primitive
     is abstract;                                       -- procedure (one
                                                        -- parameter).


   type Abstract_Diff_Proc is abstract tagged record    -- Abstract type with
      Msg : Nonabstract_Type;                           -- primitive subprog.
   end record;

   procedure Proc (P1, P2 : Abstract_Diff_Proc)         -- Abstract primitive
     is abstract;                                       -- procedure (two
                                                        -- parameters).

   type Abstract_With_Func is abstract tagged record    -- Abstract type with
      ID : Character;                                   -- prim. function with
   end record;                                          -- controlling result.

   function Func (Parm : Abstract_With_Func)            -- Abstract primitive
     return Abstract_With_Func is abstract;             -- function (one
                                                        -- parameter).

   type Nonabstract_With_Acc_Func is tagged record      -- Non-abstract type
      ID : Character;                                   -- with prim. function
   end record;                                          -- with controlling
                                                        -- access result.

   function Func (Parm : Nonabstract_With_Acc_Func)     -- Primitive function
     return access Nonabstract_With_Acc_Func;           -- (one parameter) with
                                                        -- controlling result.

   --
   -- Instantiations:
   --

   package Instance1 is new B393006_0 (Abstract_Diff_Proc);          -- ERROR:
                                      -- Non-abstract derived type in instance
                                      -- inherits procedure that requires
                                      -- overriding.

   package Instance2 is new B393006_0 (Abstract_With_Proc);          -- OK.
                                      -- Non-abstract derived type in instance
                                      -- overrides procedure that requires
                                      -- overriding.

   package Instance3 is new B393006_0 (Abstract_With_Func);          -- OK.
                                      -- Non-abstract derived type in instance
                                      -- overrides function that requires
                                      -- overriding.

   package Instance4 is new B393006_0 (Nonabstract_Type);            -- ERROR:
                                      -- Non-abstract derived type in instance
                                      -- inherits function that requires
                                      -- overriding.

   package Instance5 is new B393006_0 (Nonabstract_With_Acc_Func);   -- ERROR:
                                      -- Non-abstract derived type in instance
                                      -- inherits function that requires
                                      -- overriding.


   package Instance6 is new B393006_1 (Instance2);                   -- ERROR:
                                      -- Non-abstract derived type in instance
                                      -- inherits procedure that requires
                                      -- overriding.

   package Instance7 is new B393006_1 (Instance3);                   -- ERROR:
                                      -- Non-abstract derived type in instance
                                      -- inherits function that requires
                                      -- overriding.

   package Instance8 is new B393006_2 (Abstract_With_Func);          -- ERROR:
                                      -- Non-abstract derived type in instance
                                      -- inherits function that requires
                                      -- overriding.

   package Instance9 is new B393006_2 (Nonabstract_Type);            -- OK.
                                      -- Non-abstract derived type in instance
                                      -- inherits function that does not
                                      -- require overriding.

   package InstanceA is new B393006_2 (Nonabstract_With_Acc_Func);   -- ERROR:
                                      -- Non-abstract derived type in instance
                                      -- inherits function that requires
                                      -- overriding.


end B393006;
