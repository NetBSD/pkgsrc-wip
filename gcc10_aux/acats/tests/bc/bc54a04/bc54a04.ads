

     --===================================================================--


with FC54A00;
with BC54A04_0;
with BC54A04_1;
package BC54A04 is

--
-- Instantiations:
--

   -- Discrete (integer) designated type:

   package Instance01 is new BC54A04_0.Gen_Access_To_Constant_Numerals
     (BC54A04_1.Acc_Pos);                                             -- ERROR:
                                  -- Designated subtypes have different bounds.

   package Instance02 is new BC54A04_0.Gen_Access_To_Constant_Numerals
     (BC54A04_1.Acc_Same_Num);                                        -- OK.


   package Instance03 is new BC54A04_0.Gen_Access_To_Constant_Numerals
     (BC54A04_1.Acc_Num_Nonstat);                                     -- ERROR:
                -- Designated type in formal is static; in actual is nonstatic.

   package Instance04 is new BC54A04_0.Gen_Access_To_Constant_Pos_Nonstatic
     (BC54A04_1.Acc_Pos);                                             -- ERROR:
                -- Designated type in formal is nonstatic; in actual is static.

   package Instance05 is new BC54A04_0.Gen_Access_To_Constant_Pos_Nonstatic
     (BC54A04_1.Acc_Pos_Du_Nonstat);                                  -- ERROR:
                     -- Constraints of designated types do not result from same
                     -- evaluation/elaboration of a range/constraint.



   -- Array designated type:

   package Instance06 is new BC54A04_0.Gen_Access_To_Constant_String
     (BC54A04_1.Acc_String);                                          -- OK.


   package Instance07 is new BC54A04_0.Gen_Access_To_Constant_String
     (BC54A04_1.Acc_New_String);                                      -- ERROR:
                                             -- Designated types are different.

   package Instance08 is new BC54A04_0.Gen_Access_To_Constant_Msg_Static
     (BC54A04_1.Acc_String);                                          -- ERROR:
                       -- Designated subtypes do not both have null constraint.

   package Instance09 is new BC54A04_0.Gen_Access_To_Constant_Msg_Static
     (BC54A04_1.Acc_Msg20);                                           -- ERROR:
                            -- Designated subtypes have different index ranges.

   package Instance10 is new BC54A04_0.Gen_Access_To_Constant_Msg_Static
     (BC54A04_1.Acc_Msg_Nonstat);                                     -- ERROR:
                -- Designated type in formal is static; in actual is nonstatic.


   package Instance11 is new BC54A04_0.Gen_Access_To_Constant_Msg_Nonstatic
     (BC54A04_1.Acc_Msg_Sa_Nonstat);                                  -- OK.


end BC54A04;
