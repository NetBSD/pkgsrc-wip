

     --==================================================================--


with C460007_0;
use  C460007_0;

with Report;
procedure C460007 is

--
-- Target integer subtype (nonstatic):
--

   Limit : Static_Integer_Subtype :=
           Static_Integer_Subtype(Report.Ident_Int(128));

   subtype Nonstatic_Integer_Subtype is Static_Integer_Subtype
     range -Limit .. Limit;

   Nonstatic_Target : Static_Integer_Subtype;

begin

   Report.Test ("C460007", "Rounding for type conversions of real operand " &
                "to integer target");


   -- --------------------------
   -- Named number/literal cases:
   -- --------------------------

   Nonstatic_Target := Nonstatic_Integer_Subtype(NN_Half);
   
   if not Equal(Nonstatic_Target, 1) then                           -- Case 1.
      Report.Failed ("Wrong result for named number operand" &
                     "(case 1), nonstatic target subtype");
   end if;

   if not Equal(Nonstatic_Integer_Subtype(NN_Less_Half), 126) then  -- Case 2. 
      Report.Failed ("Wrong result for named number operand" &
                     "(case 2), nonstatic target subtype");
   end if;

   Static_Target := Static_Integer_Subtype(NN_More_Half);
   
   if not Equal(Static_Target, -1) then                             -- Case 3.
      Report.Failed ("Wrong result for named number operand" &
                     "(case 3), static target subtype");
   end if;

   if not Equal(Static_Integer_Subtype(-0.50), -1) then             -- Case 4.
      Report.Failed ("Wrong result for literal operand" &
                     "(case 4), static target subtype");
   end if;

   if not Equal(Static_Integer_Subtype(29_546.5001), 29_547) then   -- Case 5.
      Report.Failed ("Wrong result for literal operand" &
                     "(case 5), static target subtype");
   end if;

   if not Equal(Nonstatic_Integer_Subtype(-66.499), -66) then       -- Case 6.
      Report.Failed ("Wrong result for literal operand" &
                     "(case 6), nonstatic target subtype");
   end if;


   -- --------------------
   -- Floating point cases:
   -- --------------------

   Nonstatic_Target := Nonstatic_Integer_Subtype(Flt_Rnd_Away_Zero);

   if not Equal(Nonstatic_Target, -114) then                        -- Case 7.
      Report.Failed ("Wrong result for floating point operand" &
                     "(case 7), nonstatic target subtype");
   end if;
                                                                    -- Case 8.
   if not Equal(Static_Integer_Subtype(Flt_Rnd_Toward_Zero), 0) then
      Report.Failed ("Wrong result for floating point operand" &
                     "(case 8), static target subtype");
   end if;


   -- -----------------
   -- Fixed point cases:
   -- -----------------

   Static_Target := Static_Integer_Subtype(Fix_Half);

   if not Equal(Static_Target, 1) then                              -- Case 9.
      Report.Failed ("Wrong result for fixed point operand" &
                     "(case 9), static target subtype");
   end if;

   if not Equal(Static_Integer_Subtype(Fix_Rnd_Away_Zero), 1) then  -- Case 10.
      Report.Failed ("Wrong result for fixed point operand" &
                     "(case 10), static target subtype");
   end if;

   Nonstatic_Target := Nonstatic_Integer_Subtype(Fix_Rnd_Toward_Zero);

   if not Equal(Nonstatic_Target, -3) then                          -- Case 11.
      Report.Failed ("Wrong result for fixed point operand" &
                     "(case 11), nonstatic target subtype");
   end if;


   Report.Result;

end C460007;
