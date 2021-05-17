
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C332001_0 is

  procedure Assert( Truth : Boolean; Message: String ) is
  begin
    if not Truth then
      Report.Failed("Assertion " & Message & " not true" );
    end if;
  end Assert;

  procedure Check_Values is
  begin

    Assert( Nothing_New_Integer * Named_Integer = Named_Modular,
           "Nothing_New_Integer * Named_Integer = Named_Modular" ); -- 1*2 = 2
    Assert( Nothing_New_Real * Named_Float = Named_Fixed,
           "Nothing_New_Real * Named_Float = Named_Fixed" );-- 1.0*2.0 = 2.0

    Assert( Fn_Integer = Int2Mod + Flt2Int,
           "Fn_Integer = Int2Mod + Flt2Int" );              -- 4 = 2+2
    Assert( Fn_Modular = Flt2Int * 2,
           "Fn_Modular = Flt2Int * 2" );                    -- 4 = 2*2
    Assert( Fn_Float   = Mod2Flt ** Fix2Mod,
           "Fn_Float   = Mod2Flt ** Fix2Mod" );             -- 4.0 = 2.0**2
    Assert( Fn_Fixed   = (- Mod2Flt),
           "Fn_Fixed   = (- Mod2Flt)" );                    -- -2.0 = (-2.0)

    Assert( ITF = Modular_Type'First,
           "ITF = Modular_Type'First" );                    -- 0 = 0
    Assert( MTL < Integer_Type'Last,
           "MTL < Integer_Type'Last" );                     -- 255 < 1023
    Assert( MTM < Integer_Type'Last,
           "MTM < Integer_Type'Last" );                     -- 256 < 1023
    Assert( ENP > MTP,
           "ENP > MTP" );                                   -- 3 > 1
    Assert( (FTS < MTL) or (FTS >= MTL),  -- given FTS is impdef...
           "(FTS < MTL) or (FTS >= MTL)" );                 -- True
    Assert( FTS > ITS,
           "FTS > ITS" );                                   -- impdef > 3

    Assert( MAFirst = Int_Array_Object'First,
           "MAFirst = Int_Array_Object'First" );            -- 0 = 0
    Assert( IALast  > MAFirst,
           "IALast  > MAFirst" );                           -- 1023 > 0
    Assert( MAL     < IAL,
           "MAL     < IAL" );                               -- 255 < 1024

    Assert( Mod2Flt = Flt2Fix,
           "Mod2Flt = Flt2Fix" );                           -- 2.0 = 2.0

  end Check_Values;

end C332001_0;
