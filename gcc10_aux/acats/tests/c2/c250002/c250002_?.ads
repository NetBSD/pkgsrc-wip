
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-- no package body C250002_0 is required or allowed

----------------------------------------------------------------- C250002_Á

with Ada.Characters.Latin_1;
package C250002_Á is -- Á -> 16#C1#

  type Enum is ( Item, 'A', '­', -- 16#AD#
                  AE_Ææ_ae, -- 16#C6# 16#E6#
                 '-', -- 16#2D#
                 'ÿ' ); -- 16#FF#

  task type C2_Â is -- Â -> 16#C2#
    entry C2_Ã; -- Ã -> 16#C3#
  end C2_Â;

end C250002_Á;
