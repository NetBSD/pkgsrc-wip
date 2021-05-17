
package body B324003 is

   package body Gen_C is
      protected body Prot is
         entry Ent (for I in GInt) when True is
         begin
            null;
         end Ent;
      end Prot;
   end Gen_C;

   ----------------

   subtype C is Boolean;

   subtype Static_Pred is Character range 'a'..'z'
      with Static_Predicate => True;
   subtype Dynamic_Pred is Integer range 1..10
      with Dynamic_Predicate => (Dynamic_Pred mod 2) = 0;
   subtype SubStc_Pred is Static_Pred range 'a'..'m';
   subtype SubDyn_Pred is Dynamic_Pred range 1 .. 9;
   Ch : Character := 'd';
   subtype Dyn_Static_Pred is Static_Pred range 'a' .. Ch;
   subtype Ch_Dyn_Pred is Character range 'a' .. 'z'
      with Dynamic_Predicate => (Character'Pos(Ch_Dyn_Pred) mod 2) = 0;

   -- Index subtype can't have predicate:
   package Bad_1 is new Gen_A (Static_Pred);                   -- ERROR: (A)
   package Bad_2 is new Gen_A (Dynamic_Pred);                  -- ERROR: (A)
   package Bad_3 is new Gen_A (SubStc_Pred);                   -- ERROR: (A)
   package Bad_4 is new Gen_A (SubDyn_Pred);                   -- ERROR: (A)
   package OK_1  is new Gen_A (Positive);                      -- OK.
   package OK_2  is new Gen_A (Character);                     -- OK.

   -- Constrained index subtype can't have predicate:
   package Bad_11 is new Gen_B (Static_Pred);                  -- ERROR: (B)
   package Bad_12 is new Gen_B (Dynamic_Pred);                 -- ERROR: (B)
   package Bad_13 is new Gen_B (SubStc_Pred);                  -- ERROR: (B)
   package Bad_14 is new Gen_B (SubDyn_Pred);                  -- ERROR: (B)
   package OK_11  is new Gen_B (Positive);                     -- OK.
   package OK_12  is new Gen_B (Character);                    -- OK.

   -- Entry family subtype can't have predicate:
   package Bad_16 is new Gen_C (Dynamic_Pred);                 -- ERROR: (C)
   package Bad_17 is new Gen_C (SubDyn_Pred);                  -- ERROR: (C)
   package OK_18  is new Gen_C (Positive);                     -- OK.

--   -- Index constraint subtype can't have predicate:
--   package Bad_21 is new Gen_D (Dynamic_Pred);                 -- ERROR: (D)
--   package Bad_22 is new Gen_D (SubDyn_Pred);                  -- ERROR: (D)
--   package OK_21  is new Gen_D (Positive);                     -- OK.
--
--   -- Slice subtype can't have predicate:
--   package Bad_25 is new Gen_E (Static_Pred);                  -- ERROR: (E)
--   package Bad_26 is new Gen_E (SubStc_Pred);                  -- ERROR: (E)
--   package Bad_27 is new Gen_E (Ch_Dyn_Pred);                  -- ERROR: (E)
--   package Bad_28 is new Gen_E (Dyn_Static_Pred);              -- ERROR: (E)
--   package OK_25  is new Gen_E (Character);                    -- OK.

   -- 'First, 'Last prefix can't have predicate:
   package Bad_31 is new Gen_F1 (Dynamic_Pred);                -- ERROR: (F)
   package Bad_32 is new Gen_F1 (SubDyn_Pred);                 -- ERROR: (F)
   package OK_31  is new Gen_F1 (Positive);                    -- OK.

   package Bad_33 is new Gen_F2 (Static_Pred);                 -- ERROR: (F)
   package Bad_34 is new Gen_F2 (Dynamic_Pred);                -- ERROR: (F)
   package Bad_35 is new Gen_F2 (SubStc_Pred);                 -- ERROR: (F)
   package Bad_36 is new Gen_F2 (SubDyn_Pred);                 -- ERROR: (F)
   package OK_32  is new Gen_F2 (Positive);                    -- OK.
   package OK_33  is new Gen_F2 (Character);                   -- OK.

   -- Quantified expression subtype can't have a nonstatic subtype with
   -- a predicate:
   package OK_41  is new Gen_G (Static_Pred);                  -- OK.
   package Bad_42 is new Gen_G (Dynamic_Pred);                 -- ERROR: (G)
   package OK_43  is new Gen_G (SubStc_Pred);                  -- OK.
   package Bad_44 is new Gen_G (SubDyn_Pred);                  -- ERROR: (G)
   package Bad_45 is new Gen_G (Dyn_Static_Pred);              -- ERROR: (G)
   package Bad_46 is new Gen_G (Ch_Dyn_Pred);                  -- ERROR: (G)
   package OK_47  is new Gen_G (Positive);                     -- OK.
   package OK_48  is new Gen_G (Character);                    -- OK.

--   -- Aggregate choice subtype can't have a nonstatic subtype with
--   -- a predicate:
--   package OK_51  is new Gen_H (Static_Pred);                  -- OK.
--   package OK_52  is new Gen_H (SubStc_Pred);                  -- OK.
--   package Bad_53 is new Gen_H (Dyn_Static_Pred);              -- ERROR: (H)
--   package Bad_54 is new Gen_H (Ch_Dyn_Pred);                  -- ERROR: (H)
--   package OK_55  is new Gen_H (Character);                    -- OK.

end B324003;
