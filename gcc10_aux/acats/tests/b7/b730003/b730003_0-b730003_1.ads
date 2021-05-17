

     --==================================================================--


private package B730003_0.B730003_1 is  -- Private child unit.

   type Der_Type1 is new Untag_Partial_02 with null record;           -- OK.
                                    -- Legal because derived from full view.

private

   type Der_Type2 is new Untag_Partial_02 with null record;           -- OK.

end B730003_0.B730003_1;
