

     --===================================================================--


with B393004_0;
with B393004_1;
package B393004 is

   package Instance01 is new B393004_1.Tag_Formal_Derived_Proc
      (B393004_0.Field, B393004_0.Ancestor, B393004_0.Process);       -- ERROR:
                                              -- Actual subprogram is abstract.

   package Instance02 is new B393004_1.Tag_Formal_Derived_Proc
      (B393004_0.Field, B393004_0.Child, B393004_0.Process);          -- OK.


   package Instance03 is new B393004_1.Tag_Formal_Derived_Proc
      (B393004_0.Field, B393004_0.Grandchild, B393004_0.Process);     -- OK.


   package Instance04 is new B393004_1.Tag_Formal_Derived_Proc
      (B393004_0.New_Field, B393004_0.Ancestor, B393004_0.Process);   -- ERROR:
                                              -- Actual subprogram is abstract.

   package Instance05 is new B393004_1.Tag_Formal_Derived_Proc
      (B393004_0.New_Field, B393004_0.Child, B393004_0.Process);      -- OK.




   package Instance06 is new B393004_1.Tag_Formal_Private_Func
      (B393004_0.Field, B393004_0.Ancestor, B393004_0.Fetch);        -- ERROR:
                                              -- Actual subprogram is abstract.

   package Instance07 is new B393004_1.Tag_Formal_Private_Func
      (B393004_0.Field, B393004_0.Child, B393004_0.Fetch);           -- OK.


   package Instance08 is new B393004_1.Tag_Formal_Private_Func
      (B393004_0.Field, B393004_0.Grandchild, B393004_0.Fetch);      -- ERROR:
                                              -- Actual subprogram is abstract.

   package Instance09 is new B393004_1.Tag_Formal_Private_Func
      (B393004_0.New_Field, B393004_0.Ancestor, B393004_0.Fetch);    -- ERROR:
                                              -- Actual subprogram is abstract.

   package Instance10 is new B393004_1.Tag_Formal_Private_Func
      (B393004_0.New_Field, B393004_0.Child, B393004_0.Fetch);       -- OK.


   package Instance11 is new B393004_1.Tag_Formal_Private_Func
      (B393004_0.New_Field, B393004_0.Grandchild, B393004_0.Fetch);  -- ERROR:
                                              -- Actual subprogram is abstract.



   package Instance12 is new B393004_1.Tag_Ancestor_Func
      (B393004_0.Field, B393004_0.Fetch);                            -- ERROR:
                                              -- Actual subprogram is abstract.

   package Instance13 is new B393004_1.Tag_Ancestor_Func
      (B393004_0.New_Field, B393004_0.Fetch);                        -- ERROR:
                                              -- Actual subprogram is abstract.



   package Instance14 is new B393004_1.Tag_Ancestor_Proc
      (B393004_0.Field, B393004_0.Process);                           -- ERROR:
                                              -- Actual subprogram is abstract.

   package Instance15 is new B393004_1.Tag_Ancestor_Proc
      (B393004_0.New_Field, B393004_0.Process);                       -- ERROR:
                                              -- Actual subprogram is abstract.




   package Instance16 is new B393004_1.Tag_Grandchild_Func
      (B393004_0.Field, B393004_0.Fetch);                            -- ERROR:
                                              -- Actual subprogram is abstract.

   package Instance17 is new B393004_1.Tag_Grandchild_Func
      (B393004_0.New_Field, B393004_0.Fetch);                        -- ERROR:
                                              -- Actual subprogram is abstract.


end B393004;
