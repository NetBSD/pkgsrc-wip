
with B651004_0;
package B651004 is

   type Child_1 is new B651004_0.Root_Type with null record;

   overriding
   procedure Test_1 (Obj : in Child_1) with No_Return;  -- OK. {4;1}

   overriding
   procedure Test_2 (Obj : in Child_1);                 -- ERROR: {4;1}

   overriding
   procedure Test_3 (Obj : in Child_1);                 -- OK. {4;1}

   type Child_2 is new B651004_0.Root_Type with null record;

   procedure Test_A (Obj : in Child_2);                 -- OK. {4;1}

   procedure Test_B (Obj : in Child_2) with No_Return;  -- OK. {4;1}

   overriding
   procedure Test_1 (Obj : in Child_2) renames Test_A;  -- ERROR: {4;1}

   overriding
   procedure Test_2 (Obj : in Child_2) renames Test_B;  -- OK. {4;1}

   overriding
   procedure Test_3 (Obj : in Child_2) with No_Return;  -- OK. {4;1}

   type Child_3 is new B651004_0.Root_Type with null record;

   overriding
   procedure Test_1 (Obj : in Child_3) is null;         -- ERROR: {4;1}

   overriding
   procedure Test_2 (Obj : in Child_3) is null with No_Return; -- ERROR: {4;1}
      -- Note: null procedures cannot be marked No_Return.

   overriding
   procedure Test_3 (Obj : in Child_3) is null;         -- OK. {4;1}

   type Child_4 is new B651004_0.Root_Type with null record;

   type Grandchild_4 is new Child_4 with null record;

   overriding
   procedure Test_1 (Obj : in Grandchild_4) with No_Return;-- OK. {4;1}

   overriding
   procedure Test_2 (Obj : in Grandchild_4);               -- ERROR: {4;1}

   overriding
   procedure Test_3 (Obj : in Grandchild_4);               -- OK. {4;1}


end B651004;

