

     --==================================================================--


with BC50003_0;
with BC50003_1;
package BC50003 is

   package Signed_OK_Actual is new BC50003_1.Signed_Integer_Formal
      (Formal_Signed_Integer => BC50003_0.Signed_Integer);            -- OK.

   package Signed_Bad_Actual is new BC50003_1.Signed_Integer_Formal
      (BC50003_0.Modular_Integer);                                    -- ERROR:
                                        -- Actual is modular; formal is signed.


   package Modular_OK_Actual is new BC50003_1.Modular_Integer_Formal
      (Formal_Modular_Integer => BC50003_0.Modular_Integer);          -- OK.

   package Modular_Bad_Actual is new BC50003_1.Modular_Integer_Formal
      (BC50003_0.Signed_Integer);                                     -- ERROR:
                                        -- Actual is signed; formal is modular.

end BC50003;
