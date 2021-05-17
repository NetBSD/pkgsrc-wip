
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-- there is no package body CD30002_0

------------------------------------------------------------------- CD30002

with Report;
with Impdef;
with CD30002_0;
with System.Storage_Elements;
procedure CD30002 is

  My_Stuff   : CD30002_0.Some_Stuff;
    -- Impdef.Max_Default_Alignment

  My_Quarter : CD30002_0.Quarter;
    -- CD30002_0.S_Units_per_Word / 2

  My_Half    : CD30002_0.Half;
    -- CD30002_0.S_Units_per_Word * 2

  Stuff_Object   : CD30002_0.O_Some_Stuff;
    for Stuff_Object'Alignment
      use Impdef.Max_Default_Alignment;                       -- ANX-C RQMT.

  Quarter_Object : CD30002_0.O_Quarter;
    for Quarter_Object'Alignment
        use CD30002_0.Small_Alignment;                        -- ANX-C RQMT.

  Half_Object    : CD30002_0.O_Half;
    for Half_Object'Alignment
        use CD30002_0.Multiple_Object_Alignment;              -- ANX-C RQMT.

  subtype IntAdd is System.Storage_Elements.Integer_Address;
    use type System.Storage_Elements.Integer_Address;

  function A2I(Value: System.Address) return IntAdd renames
    System.Storage_Elements.To_Integer;

  NAC : constant String := " not aligned correctly";

begin  -- Main test procedure.

  Report.Test ("CD30002", "Check that the implementation supports " &
                          "Alignments for subtypes and objects specified " &
                          "as factors and multiples of the number of " &
                          "storage elements per word, unless those values " &
                          "cannot be loaded and stored. Check that the " &
                          "largest alignment returned by default is " &
                          "supported. Check that the implementation " &
                          "supports Alignments supported by the target " &
                          "linker for stand-alone library-level objects " &
                          "of statically constrained subtypes" );

  if A2I(CD30002_0.Library_Level_Object'Address)
     mod Impdef.Max_Linker_Alignment /= 0 then
    Report.Failed("Library_Level_Object" & NAC);
  end if;

  if A2I(My_Stuff'Address) mod Impdef.Max_Default_Alignment /= 0 then
    Report.Failed("Max alignment subtype" & NAC);
  end if;

  if A2I(My_Quarter'Address) mod (CD30002_0.Small_Alignment) /= 0 then
    Report.Failed("Factor of words subtype" & NAC);
  end if;

  if A2I(My_Half'Address) mod (CD30002_0.Multiple_Type_Alignment) /= 0 then
    Report.Failed("Multiple of words subtype" & NAC);
  end if;

  if A2I(Stuff_Object'Address) mod Impdef.Max_Default_Alignment /= 0 then
    Report.Failed("Stuff alignment object" & NAC);
  end if;

  if A2I(Quarter_Object'Address) 
       mod (CD30002_0.Small_Alignment) /= 0 then
    Report.Failed("Factor of words object" & NAC);
  end if;

  if A2I(Half_Object'Address) mod (CD30002_0.Multiple_Object_Alignment) /= 0 then
    Report.Failed("Multiple of words object" & NAC);
  end if;

  Report.Result;

end CD30002;
