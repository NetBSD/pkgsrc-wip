
     --=================================================================--

-- Public child.
package B392005_0.B392005_1 is
   -- Parameters declared in parent package.
   procedure Both_Types_In_Parent_Proc1
             (P1 : Parent_Tagged_T;
              P2 : Parent_Tagged_R);                         -- OK. {2:4;1}

   function Both_Types_In_Parent_Func (P1 : New_Parent_Tagged_T1)
     return New_Parent_Tagged_T2;                            -- OK. {1:4;1}

   procedure Both_Types_In_Parent_Proc2
             (P1 : Parent_Tagged_T;
              P2 : Parent_Tagged_Private);                   -- OK. {2:4;1}

   procedure Both_Types_In_Parent_Proc3
             (P1 : Parent_Tagged_T;
              P2 : Parent_Private_Tagged);                   -- OK. {2:4;1}

   procedure Both_Types_In_Parent_Proc4
             (P1 : Parent_Private_Tagged;
              P2 : Parent_Tagged_Private);                   -- OK. {2:4;1}

   -------------------------------------------------------------
   -- Type extensions.
   type New_Child_Tagged_T1 is new Parent_Tagged_T with null record;
   type New_Child_Tagged_T2 is new Parent_Tagged_T with null record;
   type Child_Tagged_X is tagged null record;
   type Child_Tagged_Y is tagged null record;

   -- One parameter declared in parent package.
   procedure Child_Primitive_Of_One_Proc1
             (P1 : Parent_Tagged_T;
              P2 : Child_Tagged_X);                          -- OK. {2:4;1}

   procedure Child_Primitive_Of_One_Proc2
             (P1 : Parent_Tagged_T;
              P2 : New_Child_Tagged_T1);                     -- OK. {2:4;1}

   function Child_Primitive_Of_One_Func1 (P1 : Child_Tagged_X)
     return Parent_Tagged_R;                                 -- OK. {1:4;1}

   function Child_Primitive_Of_One_Func2 (P1 : New_Parent_Tagged_T1)
     return New_Child_Tagged_T1;                             -- OK. {1:4;1}

   -- Parameter types are declared in child package.
   procedure Same_Type_Of_Both_Proc1
             (P1 : New_Child_Tagged_T1;
              P2 : New_Child_Tagged_T1);                     -- OK. {2:4;1}

   -- Parameter types are declared in parent package.
   function Same_Type_Of_Both_Func (P1 : Parent_Tagged_T)
     return Parent_Tagged_T;                                 -- OK. {1:4;1}
   -------------------------------------------------------------
   -- Parameter types are declared in child package.
   procedure Child_Primitive_Of_Both_Proc1
             (P1 : Child_Tagged_X;
              P2 : Child_Tagged_Y);                          -- ERROR: {2:4;1}
                      -- Primitive operation for two different tagged types.

   procedure Child_Primitive_Of_Both_Proc2
             (P1 : New_Child_Tagged_T1;
              P2 : New_Child_Tagged_T2);                     -- ERROR: {2:4;1}
                      -- Primitive operation for two different tagged types.

   function Child_Primitive_Of_Both_Func1 (P1 : Child_Tagged_X)
     return New_Child_Tagged_T2;                             -- ERROR: {1:4;1}
                      -- Primitive operation for two different tagged types.
   -------------------------------------------------------------
   type Child_Tagged_Z is tagged null record;
   type New_Child_Tagged_Z1 is new Child_Tagged_Z with private;
   type New_Child_Tagged_Z2 is new Child_Tagged_Z with private;

   -- Parameter types are declared in child package.
   procedure Child_Primitive_Of_Both_Proc3
             (P1 : Child_Tagged_Z;
              P2 : New_Child_Tagged_Z1);                     -- ERROR: {2:4;1}
                      -- Primitive operation for two different tagged types.

   function Child_Primitive_Of_Both_Func3 (P1 : New_Child_Tagged_Z1)
     return New_Child_Tagged_Z2;                             -- ERROR: {1:4;1}
                      -- Primitive operation for two different tagged types.

   -------------------------------------------------------------
   type Child_Tagged_Private is tagged private;

   procedure Same_Type_Of_Both_Proc2
             (P1, P2 : Child_Tagged_Private);                -- OK. {1:4;1}

   procedure Child_Primitive_Of_Both_Proc5
             (P1 : Child_Tagged_Private;
              P2 : Child_Tagged_Z);                          -- ERROR: {2:4;1}
                      -- Primitive operation for two different tagged types.

   -------------------------------------------------------------
   type Child_Private_Tagged is private;

   procedure Same_Type_Of_Both_Proc3
             (P1, P2 : Child_Private_Tagged);                -- OK. {1:4;1}

   procedure Same_Type_Of_Both_Proc4
             (P1 : Child_Private_Tagged;
              P2 : Child_Tagged_Private);     -- POSSIBLE ERROR: [Set1] {2:4;1}
                      -- Primitive operation for two different tagged types.

   type Child_Private_Tagged_Again is private;

   procedure Same_Type_Of_Both_Proc5
             (P1 : Child_Private_Tagged_Again;
              P2 : Child_Tagged_Z);           -- POSSIBLE ERROR: [Set2] {2:4;1}
                      -- Primitive operation for two different tagged types.

private
   type New_Child_Tagged_Z2 is new Child_Tagged_Z with null record;

   type New_Child_Tagged_Z1 is new Child_Tagged_Z with null record;

   -------------------------------------------------------------
   procedure Child_Private_Primitive_Of_Both_Proc1
             (P1 : New_Child_Tagged_Z1;
              P2 : Child_Tagged_Y);                          -- ERROR: {2:4;1}
                      -- Primitive operation for two different tagged types.
   -------------------------------------------------------------
   type Child_Tagged_V is tagged null record;
   type Child_Tagged_W is tagged null record;

   procedure Child_Private_Primitive_Of_Both_Proc2
             (P1 : Child_Tagged_V;
              P2 : Child_Tagged_W);                          -- ERROR: {2:4;1}
                      -- Primitive operation for two different tagged types.
   -------------------------------------------------------------
   type Child_Tagged_Private is tagged
     record
        Field_1 : Boolean;
     end record;

   type Child_Private_Tagged is tagged
     record           -- Primitive operation for two different tagged types:
                      -- Same_Type_Of_Both_Proc4.
        Field_1 : Child_Tagged_Private;
     end record;                              -- POSSIBLE ERROR: [Set1] {4:4;1}

   procedure Child_Private_Primitive_Of_Both_Proc3
             (P1 : Child_Private_Tagged;
              P2 : Child_Tagged_Private);                    -- ERROR: {2:4;1}
                      -- Primitive operation for two different tagged types.

   procedure Child_Private_Primitive_Of_Both_Proc4
             (P1 : Child_Private_Tagged;
              P2 : New_Child_Tagged_Z1);                     -- ERROR: {2:4;1}
                      -- Primitive operation for two different tagged types.

   type Child_Private_Tagged_Again is tagged
     record           -- Primitive operation for two different tagged types:
                      -- Same_Type_Of_Both_Proc5.
        Field_1 : Child_Tagged_Private;
     end record;                              -- POSSIBLE ERROR: [Set2] {4:4;1}

end B392005_0.B392005_1;
