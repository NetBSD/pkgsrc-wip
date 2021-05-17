

     --==================================================================--


with FXC6A00;
with BXC6A02_0;

package BXC6A02 is

   VolTag      : FXC6A00.Volatile_Tagged;

   RootTag     : FXC6A00.Tagged_Type;
   pragma Volatile (RootTag);

   TagArray    : aliased FXC6A00.Array_Type;

   NonVolTag_A : FXC6A00.NonVolatile_Tagged;

   NonVolTag_B : FXC6A00.NonVolatile_Tagged;
   pragma Volatile (NonVolTag_B);

   VolProt  : aliased FXC6A00.Volatile_Protected;

   Comp     : FXC6A00.Composite_Type;

   type Roman_Array is array (1 .. 7) of FXC6A00.Roman;
   pragma Atomic_Components (Roman_Array);                     -- N/A => ERROR.
              -- Implementation must reject this pragma if it does not support
              -- indivisible read/write for Roman objects.

   RomArray    : Roman_Array;

   AtomRom     : aliased FXC6A00.Roman;
   pragma Atomic (AtomRom);                                    -- N/A => ERROR.
              -- Implementation must reject this pragma if it does not support
              -- indivisible read/write for Roman objects.


--
-- Formal objects:
--

   package Tag_FormObjTypeIsVol1 is new BXC6A02_0.Volatile_Tagged_Formal
     ( VolTag );                                                      -- OK.
                                      -- Type of formal object is volatile.

   package Tag_FormObjTypeIsVol2 is new BXC6A02_0.Volatile_Tagged_Formal
     ( Comp.D );                                                      -- OK.
                                      -- Type of formal object is volatile.


   package Rom_CompOfVolType is new BXC6A02_0.Roman_Formal
     ( VolTag.R1 );                                                   -- ERROR:
                                      -- Type of formal object is not volatile.

   package Rom_CompOfVolObj is new BXC6A02_0.Roman_Formal
     ( NonVolTag_B.R2 );                                              -- ERROR:
                                      -- Type of formal object is not volatile.

   package Rom_CompOfNonVolObj is new BXC6A02_0.Roman_Formal
     ( NonVolTag_A.R2 );                                              -- OK.
                                      -- Actual is not volatile.

   package Rom_AtomCompDueToPragma is new BXC6A02_0.Roman_Formal
     ( RomArray(7) );                                                 -- ERROR:
                                      -- Type of formal object is not volatile.
              -- NOTE: if pragma Atomic_Components is rejected for Roman_Array,
              --       this case need NOT be flagged as an error.

   package Rom_AtomDueToPragma is new BXC6A02_0.Roman_Formal
     ( AtomRom );                                                     -- ERROR:
                                      -- Type of formal object is not volatile.
                            -- NOTE: if pragma Atomic is rejected for AtomRom,
                            --       this case need NOT be flagged as an error.


--
-- Prefix of 'Access:
--

   Ptr_VolProt : FXC6A00.Acc_Vol_Protected := VolProt'Access;         -- OK.
                    -- Designated type of expected access type is volatile.

   Ptr_VolTagC : FXC6A00.Acc_Volatile_Tagged := Comp.D'Access;        -- OK.
                    -- Designated type of expected access type is volatile.

   Ptr_Arr     : FXC6A00.Acc_Array_Type := TagArray'Access;           -- OK.
                    -- Prefix of 'Access is not volatile.

   Ptr_CompNon : FXC6A00.Acc_Roman := NonVolTag_A.R2'Access;          -- OK.
                    -- Prefix of 'Access is not volatile.

   Ptr_CompVol : FXC6A00.Acc_Roman := NonVolTag_B.R2'Access;          -- ERROR:
                    -- Designated type of expected access type is not volatile.

   Ptr_RomObj  : FXC6A00.Acc_Roman := AtomRom'Access;                 -- ERROR:
                    -- Designated type of expected access type is not volatile.
                            -- NOTE: if pragma Atomic is rejected for AtomRom,
                            --       this case need NOT be flagged as an error.

end BXC6A02;
