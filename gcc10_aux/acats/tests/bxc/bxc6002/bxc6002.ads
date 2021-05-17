

     --==================================================================--


with BXC6002_0;
with BXC6002_1;

package BXC6002 is

   VowelObj : BXC6002_0.Vowels;

   VowelArr : BXC6002_0.Array_Of_Vowels;

   BitsObj  : BXC6002_0.Four_Bits;

   BitsAtom : BXC6002_0.Four_Bits;
   pragma Atomic (BitsAtom);                                   -- N/A => ERROR.
          -- Implementation must reject this pragma if it does not support
          -- indivisible read/write for Four_Bits objects.  

   BitsArr  : aliased BXC6002_0.Array_Of_Four_Bits;

   ModAtom  : aliased BXC6002_0.Modular;
   pragma Atomic (ModAtom);                                    -- N/A => ERROR.
          -- Implementation must reject this pragma if it does not support
          -- indivisible read/write for Modular objects.  

   NewMod   : aliased BXC6002_0.Atomic_Modular;


--
-- Formal objects:
--

   package Vowel1 is new BXC6002_1.Vowels_Formal (VowelObj);          -- OK.
                                         -- Type of formal object is atomic.

   package Vowel2 is new BXC6002_1.Vowels_Formal (VowelArr(3));       -- OK.
                                         -- Type of formal object is atomic.

   package Bits1 is new BXC6002_1.Four_Bits_Formal (BitsObj);         -- OK.
                                             -- Actual object is not atomic.

   package Bits2 is new BXC6002_1.Four_Bits_Formal (BitsAtom);        -- ERROR:
                                        -- Type of formal object is not atomic.
                 -- NOTE: if pragma Atomic is rejected for BitsAtom, this case
                 --       need NOT be flagged as an error.

   package Bits3 is new BXC6002_1.Four_Bits_Formal (BitsArr(1));      -- ERROR:
                                        -- Type of formal object is not atomic.
                              -- NOTE: if pragma Atomic_Components is rejected
                              --       for Array_Of_Four_Bits, this case need
                              --       NOT be flagged as an error.

   package BitArray1 is new BXC6002_1.BitArray_Formal (BitsArr);      -- OK.
                                             -- Actual object is not atomic.

   package Mod1 is new BXC6002_1.Private_Formal
     (BXC6002_0.Modular, ModAtom);                                    -- ERROR:
                                        -- Type of formal object is not atomic.
                  -- NOTE: if pragma Atomic is rejected for ModAtom, this case
                  --       need NOT be flagged as an error.

   package Mod2 is new BXC6002_1.Private_Formal
     (BXC6002_0.Atomic_Modular, NewMod);                              -- ERROR:
                                        -- Type of formal object is not atomic.


--
-- Prefix of 'Access:
--

   Ptr_Mod   : BXC6002_0.Acc_Modular := ModAtom'Access;               -- ERROR:
                      -- Designated type of expected access type is not atomic.
                  -- NOTE: if pragma Atomic is rejected for ModAtom, this case
                  --       need NOT be flagged as an error.

   Ptr_NewMod: BXC6002_0.Acc_Atomic_Mod := NewMod'Access;             -- OK.
                       -- Designated type of expected access type is atomic.

   Ptr_Array : BXC6002_0.Acc_Array := BitsArr'Access;                 -- OK.
                                         -- Prefix of 'Access is not atomic.

   Ptr_Comp  : BXC6002_0.Acc_Four_Bits := BitsArr(2)'Access;          -- ERROR:
                      -- Designated type of expected access type is not atomic.
                              -- NOTE: if pragma Atomic_Components is rejected
                              --       for Array_Of_Four_Bits, this case need
                              --       NOT be flagged as an error.

end BXC6002;
