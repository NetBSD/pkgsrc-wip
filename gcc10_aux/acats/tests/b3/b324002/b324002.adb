
package body B324002 is

   function Is_Good(X: String) return Boolean is
   begin
      return True;
   end Is_Good;

   function Is_Good(X: String) return Integer is
   begin
      return 1;
   end Is_Good;

   ----------------

   subtype C is Boolean;

   subtype Static_Pred is Character range 'a'..'z'
      with Static_Predicate => True;
   subtype Dynamic_Pred is Integer range 1..10
      with Dynamic_Predicate => (Dynamic_Pred mod 2) = 0;
   subtype SubStc_Pred is Static_Pred range 'a'..'m';
   subtype SubDyn_Pred is Dynamic_Pred range 1 .. 9;

   -- Index subtype can't have predicate:
   type Bad_Index_Subtype_1 is array (Static_Pred range <>) of C; -- ERROR: (A)
   type Bad_Index_Subtype_2 is array (Dynamic_Pred range <>) of C;-- ERROR: (A)
   type Bad_Index_Subtype_3 is array (SubStc_Pred range <>) of C; -- ERROR: (A)
   type Bad_Index_Subtype_4 is array (SubDyn_Pred range <>) of C; -- ERROR: (A)

   type OK_Array is array (Character range <>) of C; -- OK.
   type OK_Int_Array is array (Integer range <>) of C; -- OK.
   -- Index constraint can't have a predicate:
   subtype Bad_Index_Constraint_1 is OK_Array(Static_Pred);       -- ERROR: (B)
   subtype Bad_Index_Constraint_2 is OK_Array(SubStc_Pred);       -- ERROR: (B)
   subtype Bad_Index_Constraint_3 is
      OK_Array(Static_Pred range 'a' .. 'b');                     -- ERROR: (B)
   subtype Bad_Index_Constraint_4 is OK_Int_Array(Dynamic_Pred);  -- ERROR: (B)
   subtype Bad_Index_Constraint_5 is OK_Int_Array(SubDyn_Pred);   -- ERROR: (B)
   subtype Bad_Index_Constraint_6 is
      OK_Int_Array(Dynamic_Pred range 1 .. 2);                    -- ERROR: (B)

   OK_Array_Obj: OK_Array := (False, True);
   OK_Int_Array_Obj: OK_Int_Array := (False, True);
   -- Slice can't have predicate:
   Bad_Slice_1: OK_Array := OK_Array_Obj(Static_Pred);            -- ERROR: (C)
   Bad_Slice_2: OK_Array := OK_Array_Obj(SubStc_Pred);            -- ERROR: (C)
   Bad_Slice_3: OK_Array :=
       OK_Array_Obj(Static_Pred range 'a'..'b');                  -- ERROR: (C)
   Bad_Slice_4: OK_Int_Array := OK_Int_Array_Obj(Dynamic_Pred);   -- ERROR: (C)
   Bad_Slice_5: OK_Int_Array := OK_Int_Array_Obj(SubDyn_Pred);    -- ERROR: (C)
   Bad_Slice_6: OK_Int_Array :=
       OK_Int_Array_Obj(Dynamic_Pred range 1 .. 2);               -- ERROR: (C)

   -- Constrained array index subtype can't have predicate:
   type Bad_Constrained_Index_Subtype_1 is
       array (Static_Pred) of C;                                  -- ERROR: (D)
   type Bad_Constrained_Index_Subtype_2 is
       array (SubStc_Pred range 'a' .. 'c') of C;                 -- ERROR: (D)
   type Bad_Constrained_Index_Subtype_3 is
       array (Boolean, Dynamic_Pred) of C;                        -- ERROR: (D)
   type Bad_Constrained_Index_Subtype_4 is
       array (SubDyn_Pred, Character) of C;                       -- ERROR: (D)
   type Bad_Constrained_Index_Subtype_5 is
       array (SubDyn_Pred range 1 .. 4) of C;                     -- ERROR: (D)

   -- Entry family subtype can't have a predicate:
   task type Tsk is
      entry Ent1 (Static_Pred);                                   -- ERROR: (E)
      entry Ent2 (Substc_Pred);                                   -- ERROR: (E)
      entry Ent3 (Static_Pred range 'a' .. 'b');                  -- ERROR: (E)
      entry Ent4 (Dynamic_Pred);                                  -- ERROR: (E)
      entry Ent5 (Dynamic_Pred);                                  -- ERROR: (E)
      entry Ent6 (Dynamic_Pred range 1 .. 4);                     -- ERROR: (E)
   end Tsk;

   task body Tsk is
   begin
      null;
   end Tsk;

   -- Entry family subtype can't have a predicate:
   protected type Prot is
      entry Ent1 (Static_Pred);                                   -- ERROR: (E)
      entry Ent2 (Substc_Pred);                                   -- ERROR: (E)
      entry Ent3 (Static_Pred range 'a' .. 'b');                  -- ERROR: (E)
      entry Ent4 (Dynamic_Pred);                                  -- ERROR: (E)
      entry Ent5 (SubDyn_Pred);                                   -- ERROR: (E)
      entry Ent6 (Dynamic_Pred range 1 .. 4);                     -- ERROR: (E)
   end Prot;

   protected body Prot is
      -- Note: This is an "OPTIONAL ERROR" as some error had to be
      -- reported for the specification, so reporting it here is
      -- necessarily redundant.
      entry Ent1 (for I in Static_Pred) when True is     -- OPTIONAL ERROR: (F)
      begin
          null;
      end Ent1;
      entry Ent2 (for I in Substc_Pred) when True is     -- OPTIONAL ERROR: (F)
      begin
          null;
      end Ent2;
      entry Ent3 (for I in Static_Pred range 'a' .. 'b') -- OPTIONAL ERROR: (F)
         when True is
      begin
          null;
      end Ent3;
      entry Ent4 (for I in Dynamic_Pred) when True is    -- OPTIONAL ERROR: (F)
      begin
          null;
      end Ent4;
      entry Ent5 (for I in SubDyn_Pred) when True is     -- OPTIONAL ERROR: (F)
      begin
          null;
      end Ent5;
      entry Ent6 (for I in Dynamic_Pred range 1 .. 4)    -- OPTIONAL ERROR: (F)
         when True is
      begin
          null;
      end Ent6;
   end Prot;

   ----------------

   Bad_First: Character := Static_Pred'First;                     -- ERROR: (G)
   Bad_Last: Character := SubStc_Pred'Last;                       -- ERROR: (G)
   subtype Bad_Range is
      Character range Static_Pred'range;                          -- ERROR: (G)
   Bad_First2: Integer := SubDyn_Pred'First;                      -- ERROR: (G)
   Bad_Last2: Integer := Dynamic_Pred'Last;                       -- ERROR: (G)
   subtype Bad_Range2 is
      Integer range Dynamic_Pred'range;                           -- ERROR: (G)

   ----------------

   procedure Loops is
      Ch : Character := 'd';
      subtype Dyn_Static_Pred is Static_Pred range 'a' .. Ch;
   begin
      for X in Static_Pred loop                                   -- OK.
         null;
      end loop;
      for X in Dynamic_Pred loop                                  -- ERROR: (H)
         null;
      end loop;
      for X in SubDyn_Pred loop                                   -- ERROR: (H)
         null;
      end loop;
      for X in Dynamic_Pred range 1 .. 8 loop                     -- ERROR: (H)
         null;
      end loop;
      for X in Dyn_Static_Pred loop                               -- ERROR: (H)
         null;
      end loop;
      if (for all X in Static_Pred => True) then                  -- OK.
         null;
      elsif (for all X in Dynamic_Pred => True) then              -- ERROR: (H)
         null;
      elsif (for some X in SubDyn_Pred => True) then              -- ERROR: (H)
         null;
      elsif (for all X in Dynamic_Pred range 1 .. 8 => True) then -- ERROR: (H)
         null;
      elsif (for some X in Dyn_Static_Pred => True) then          -- ERROR: (H)
         null;
      end if;
   end Loops;

   ----------------

   procedure Aggregate_Choices is
      -- Aggregate choice is nonstatic and has a predicate:
      Obj1 : OK_Int_Array (1 .. 10) := (Dynamic_Pred => True);    -- ERROR: (I)
      Obj2 : OK_Int_Array (1 .. 10) := (SubDyn_Pred => True);     -- ERROR: (I)
      Obj3 : OK_Int_Array (1 .. 10) :=
         (Dynamic_Pred range 1.. 6 => True);                      -- ERROR: (I)
      Ch : Character := 'd';
      subtype Dyn_Static_Pred is Static_Pred range 'a' .. Ch;
      Obj4 : OK_Array ('a' .. 'd') := (Dyn_Static_Pred => True);  -- ERROR: (I)
   begin
      null;
   end Aggregate_Choices;

   ----------------

   procedure Nonstatic (Y: Integer) is
      Good_Named : constant := Integer'(10);           -- OK.
      Bad_Named  : constant := SubDyn_Pred'(3);        -- ERROR: not static
   begin
      case Y is
         when Dynamic_Pred => null;                    -- ERROR: not static
         when others => null;
      end case;
   end Nonstatic;

end B324002;
