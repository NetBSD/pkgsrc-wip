
package body B324001 is

   type T1 is range 1..10
      with Static_Predicate => Named_Number;           -- ERROR: (A)

   subtype T2 is Integer
      with Dynamic_Predicate => Int_Func(T2);          -- ERROR: (A)

   subtype T3 is String
      with Dynamic_Predicate => Is_Good(T3);           -- OK.

   function Int_Func (X: Integer) return Integer is
   begin
      return 1;
   end Int_Func;

   function Is_Good (X: String) return Boolean is
   begin
      return True;
   end Is_Good;

   function Is_Good (X: String) return Integer is
   begin
      return 1;
   end Is_Good;

   function Is_OK (X: String) return Boolean is
   begin
      return True;
   end Is_OK;

   ----------------

   An_Exception: exception
      with Static_Predicate => True;                   -- ERROR: (B)
   Another_Exception: exception
      with Dynamic_Predicate => True;                  -- ERROR: (B)
   A_Variable: Natural := 0
      with Dynamic_Predicate => A_Variable mod 2 = 0;  -- ERROR: (B)

   function Fooey (X: String) return Natural is
      (X'Length)
      with Dynamic_Predicate => X < 80;                -- ERROR: (B)
   procedure Bar (X: String) is null
      with Static_Predicate => True;                   -- ERROR: (B)

   package Inner
      with Dynamic_Predicate => True is                -- ERROR: (B)
      Blah : Natural;
   end Inner;

   protected type Prot (A : Natural)
      with Dynamic_Predicate => Prot.A mod 2 = 0 is    -- OK.
      procedure Do_It (B: Natural);
   private
      Local : Natural;
   end Prot;

   protected body Prot is
      procedure Do_It (B: Natural) is
      begin
         Local := (if B < A then B else A);
      end Do_It;
   end Prot;

   task type Tsk (C : Natural)
      with Dynamic_Predicate => Tsk.C mod 2 = 1 is     -- OK.
      entry Do_It (D: Natural);
   end Tsk;

   task body Tsk is
      Local : Natural;
   begin
      accept Do_It (D: Natural) do
         Local := (if D < C then D else C);
      end Do_It;
   end Tsk;

   ----------------

   type Rec;
   subtype SRec is Rec
      with Dynamic_Predicate => True;                  -- ERROR: (C)
   type Ptr is access Rec;
   type Rec is record
      Next : Ptr;
   end record;

   ----------------

   Global_Var : Natural := 0;
   subtype Dyn is Integer range 0 .. Global_Var;
   subtype Dyn_Bool is Boolean range False .. (Dyn'Last > 0);
   Global_Bool_Var : Boolean := Dyn'Last >= 0;

   type Static_Predicate is null record
     with Static_Predicate => Is_OK("Hello");          -- ERROR: (D)

   type Even is new Integer
     with Static_Predicate => (Even mod 2) = 0;        -- ERROR: (E)

   subtype Nonstatic_1 is Integer
     with Static_Predicate => (Nonstatic_1 * 2) >= 10; -- ERROR: (E)

   subtype Nonstatic_2 is Integer
     with Static_Predicate => (4096 / Nonstatic_2) > 2;-- ERROR: (E)

   subtype Nonstatic_3 is Integer
     with Static_Predicate =>
        (Dyn'(10) - 2) > Nonstatic_3;                  -- ERROR: (E) (K)

   subtype Nonstatic_4 is Integer
     with Static_Predicate => 10 in Dyn;               -- ERROR: (F)

   subtype Nonstatic_5 is Integer
     with Static_Predicate =>
        Nonstatic_5 in 1 | 2 | Dyn'(8);                -- ERROR: (G)

   subtype Nonstatic_6 is Integer
     with Static_Predicate => Nonstatic_6 in Dyn;      -- ERROR: (G)

   subtype Nonstatic_7 is Integer
     with Static_Predicate =>
        (case 10 is
           when 1 => True,
           when 2 => True,
           when others => Dyn_Bool'(False));           -- ERROR: (H)

   subtype Nonstatic_8 is Integer
     with Static_Predicate =>
        (case Nonstatic_8 is
           when 1 => True,
           when 2 => True,
           when others => Dyn_Bool'(False));           -- ERROR: (I)

   subtype Nonstatic_9 is Integer
     with Static_Predicate => Dyn'(8) > 2;             -- ERROR: (J)

   subtype Nonstatic_10 is Integer
     with Static_Predicate => Nonstatic_10 > Dyn'(0);  -- ERROR: (K)

   subtype Nonstatic_11 is Integer
     with Static_Predicate =>
        Nonstatic_11 > 0 and Nonstatic_11 in Dyn;      -- ERROR: (L) (G)

   subtype Nonstatic_12 is Integer
     with Static_Predicate =>
        Nonstatic_12 > 0 or Is_OK ("Ugh");             -- ERROR: (L) (A)

   subtype Nonstatic_13 is Integer
     with Static_Predicate =>
        Nonstatic_13 >= 0 and then
        Nonstatic_13 / 2 < 1000;                       -- ERROR: (M) (E)

   subtype Nonstatic_14 is Integer
     with Static_Predicate =>
        (Nonstatic_14 > Dyn'(0));                      -- ERROR: (N) (J)

   subtype Nonstatic_15 is Integer
     with Static_Predicate =>
        (Nonstatic_15 >= Global_Var);                  -- ERROR: (N) (Q)

   subtype Nonstatic_16 is Integer
     with Static_Predicate => Global_Bool_Var;         -- ERROR: (Q)

end B324001;
