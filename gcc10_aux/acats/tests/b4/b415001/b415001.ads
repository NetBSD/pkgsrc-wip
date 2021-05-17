
with B415001_A;
package B415001 is

    type Ref1 (D : Natural) is null record
       with Implicit_Dereference => D;                           -- ERROR: (1)

    type Ref2 is record
       D : access Integer;
    end record
       with Implicit_Dereference => D;                           -- ERROR: (1)

    type Ref3 (D : Natural) is record
       C : access Integer;
    end record
       with Implicit_Dereference => C;                           -- ERROR: (1)

    type Ref4 (D : access Integer) is record
       C : Natural;
    end record
       with Implicit_Dereference => D;                           -- OK.

    type Acc_Int is access Integer;

    type Ref5 (D : Acc_Int) is null record
       with Implicit_Dereference => D;                           -- ERROR: (1)

    Obj : aliased Integer;

    type Ref6 (D : Natural) is record
       C : Ref4 (Obj'Access);
    end record
       with Implicit_Dereference => C.D;                         -- ERROR: (1)

    type Ref7 (D1 : access Integer;
               D2 : access String) is
       new B415001_A.Priv_Ref(D1) with null record
       with Implicit_Dereference => D2;                          -- ERROR: (2)

    type Ref8 (D1 : access Integer;
               D2 : access String) is
       new B415001_A.Dbl_Ref(D1, D2)
       with Implicit_Dereference => D2;                          -- ERROR: (2)

    type Ref9 (D1 : access Integer;
               D2 : access String) is
       new B415001_A.Priv_Ref(D1) with null record
       with Implicit_Dereference => D1;                          -- OK.
          -- Confirming.

    type RefA (D1 : access Integer;
               D2 : access String) is
       new B415001_A.Dbl_Ref(D1, D2)
       with Implicit_Dereference => D1;                          -- OK.
          -- Confirming.

    type Priv1 (D : access Integer) is private;

    type Priv2 (D : access Integer) is private
       with Implicit_Dereference => D;                           -- OK.

    type Priv3 (D : access Integer) is new B415001_A.Root with private;

    type Priv4 (D : access Integer) is new B415001_A.Root with private
       with Implicit_Dereference => D;                           -- OK.

    type Priv5 (D : access Integer) is tagged private;

    type Priv6 (D : access Integer) is tagged private
       with Implicit_Dereference => D;                           -- OK.

    type Priv7 (D : access Integer) is new B415001_A.Root with private;

    type Priv8 (D : access Integer) is new B415001_A.Root with private
       with Implicit_Dereference => D;                           -- OK.

    type Priv9 is new B415001_A.Der with private;

    type PrivA (D1 : access Integer;
                D2 : access String) is new B415001_A.Root with private;

    type PrivB (D1 : access Integer;
                D2 : access String) is new B415001_A.Root with private
       with Implicit_Dereference => D2;                          -- OK.

private

    type Priv1 (D : access Integer) is null record
       with Implicit_Dereference => D;                           -- ERROR: (3)

    type Priv2 (D : access Integer) is null record
       with Implicit_Dereference => D;                           -- ERROR: (3)
       -- Note that this is illegal even though the aspect is confirming.

    type Priv3 (D : access Integer) is new B415001_A.Root with null record
       with Implicit_Dereference => D;                           -- ERROR: (3)

    type Priv4 (D : access Integer) is new B415001_A.Root with null record
       with Implicit_Dereference => D;                           -- ERROR: (3)
       -- Note that this is illegal even though the aspect is confirming.

    type Priv5 (D : access Integer) is
       new B415001_A.Der(D) with null record;                    -- ERROR: (4)

    type Priv6 (D : access Integer) is
       new B415001_A.Der(D) with null record;                    -- OK.

    type Priv7 (D : access Integer) is
       new B415001_A.Der(D) with null record;                    -- ERROR: (4)

    type Priv8 (D : access Integer) is
       new B415001_A.Der(D) with null record;                    -- OK.

    type Priv9 is new B415001_A.Der with null record;            -- OK.

    type PrivA (D1 : access Integer;
                D2 : access String) is
       new B415001_A.Dbl_Der(D1, D2) with null record;           -- ERROR: (4)

    type PrivB (D1 : access Integer;
                D2 : access String) is
       new B415001_A.Dbl_Der(D1, D2) with null record;           -- ERROR: (4)
       -- The value of the inherited aspect is different than
       -- the specified one fpr the partial view.

end B415001;
