
with Report;
with Impdef;
package body TCTouch is

  procedure Assert( SB_True : Boolean; Message : String ) is
  begin
    if not SB_True then
      Report.Failed( "Assertion failed: " & Message );
    end if;
  end Assert;

  procedure Assert_Not( SB_False : Boolean; Message : String ) is
  begin
    if SB_False then
      Report.Failed( "Assertion failed: " & Message );
    end if;
  end Assert_Not;

  Collection : String(1..Max_Touch_Count);
  Finger     : Natural := 0;
  Overflow_Count : Natural := 0;

  procedure Touch ( A_Tag : Character ) is
  begin
    Finger := Finger+1;
    Collection(Finger) := A_Tag;
  exception
    when Constraint_Error =>
      if Overflow_Count = 0 then
        Report.Failed("Trace Overflow: " & Collection);
      end if;
      if Overflow_Count <= Natural'Last - Max_Touch_Count then
        Overflow_Count := Overflow_Count + Max_Touch_Count;
      -- else the overflow count would overflow. :-)
      end if;
      Finger := 0;
  end Touch;

  procedure Sort_String( S: in out String ) is
  -- algorithm from Booch Components Page 472
    No_Swaps : Boolean;
    procedure Swap(C1, C2: in out Character) is
      T: Character := C1;
    begin  C1 := C2; C2 := T; end Swap;
  begin
    for OI in S'First+1..S'Last loop
      No_Swaps := True;
      for II in reverse OI..S'Last loop
        if S(II) < S(II-1) then
          Swap(S(II),S(II-1));
          No_Swaps := False;
        end if;
      end loop;
      exit when No_Swaps;
    end loop;
  end Sort_String;

  procedure Check_Overflow is
    -- Check and report on any overflow, clearing the overflow information
    -- afterwards.
  begin
    if Overflow_Count > Max_Touch_Count then
      if Overflow_Count > Natural'Last - Max_Touch_Count then
        Report.Comment ("More than " & Natural'Image(Overflow_Count) &
	  " excess Touch calls discarded");
      else
        Report.Comment (Natural'Image(Overflow_Count) &
	  " excess Touch calls discarded");
      end if;
    end if;
    Overflow_Count := 0;
  end Check_Overflow;

  procedure Validate( Expected: String;
                      Message : String;
                      Order_Meaningful : Boolean := True) is
    Want : String(1..Expected'Length) := Expected;
  begin
    Check_Overflow;
    if not Order_Meaningful then
      Sort_String( Want );
      Sort_String( Collection(1..Finger) );
    end if;
    if Collection(1..Finger) /= Want then
      Report.Failed( Message & " Expecting: " & Want
			     & " Got: " & Collection(1..Finger) );
    end if;
    Finger := 0;
  end Validate;

  procedure Validate_One_Of (Expected_1: String;
                             Expected_2: String;
                             Expected_3: String := "";
                             Expected_4: String := "";
                             Expected_5: String := "";
                             Expected_6: String := "";
                             Message : String) is
     -- OK if any of the expected strings is found.
     -- If the null string is a legitimate result, it must be given
     -- first.
  begin
    Check_Overflow;
    if Collection(1..Finger) = Expected_1 then
       Finger := 0;
       return; -- OK.
    elsif Collection(1..Finger) = Expected_2 then
       Finger := 0;
       return; -- OK.
    elsif Expected_3 /= "" and then Collection(1..Finger) = Expected_3 then
       Finger := 0;
       return; -- OK.
    elsif Expected_4 /= "" and then Collection(1..Finger) = Expected_4 then
       Finger := 0;
       return; -- OK.
    elsif Expected_5 /= "" and then Collection(1..Finger) = Expected_5 then
       Finger := 0;
       return; -- OK.
    elsif Expected_6 /= "" and then Collection(1..Finger) = Expected_6 then
       Finger := 0;
       return; -- OK.
    else
       if Expected_3 = "" and Expected_4 = "" and
          Expected_5 = "" and Expected_6 = "" then
          Report.Failed( Message & " Expecting: " & Expected_1
              & " or: " & Expected_2
 	      & " but got: " & Collection(1..Finger) );
       elsif Expected_4 = "" and
          Expected_5 = "" and Expected_6 = "" then
          Report.Failed( Message & " Expecting: " & Expected_1
              & " or: " & Expected_2
              & " or: " & Expected_3
 	      & " but got: " & Collection(1..Finger) );
       elsif Expected_5 = "" and Expected_6 = "" then
          Report.Failed( Message & " Expecting: " & Expected_1
              & " or: " & Expected_2
              & " or: " & Expected_3
              & " or: " & Expected_4
 	      & " but got: " & Collection(1..Finger) );
       elsif Expected_6 = "" then
          Report.Failed( Message & " Expecting: " & Expected_1
              & " or: " & Expected_2
              & " or: " & Expected_3
              & " or: " & Expected_4
              & " or: " & Expected_5
 	      & " but got: " & Collection(1..Finger) );
       else
          Report.Failed( Message & " Expecting: " & Expected_1
              & " or: " & Expected_2
              & " or: " & Expected_3
              & " or: " & Expected_4
              & " or: " & Expected_5
              & " or: " & Expected_6
 	      & " but got: " & Collection(1..Finger) );
       end if;
       Finger := 0;
    end if;
  end Validate_One_Of;

  procedure Flush is
  begin
    Finger := 0;
  end Flush;

  procedure Implementation_Check( Message : in String;
                                  Annex   : in Special_Needs_Annexes
                                          := Annex_C ) is
                                          -- default to cover some legacy
  -- USAGE DISCIPLINE:
  --   Implementation_Check is designed to be used in tests that have
  --   interdependency on one of the Special Needs Annexes, yet are _really_
  --   tests based in the core language.  There will be instances where the
  --   execution of a test would be failing in the light of the requirements
  --   of the annex, yet from the point of view of the core language without
  --   the additional requirements of the annex, the test does not apply.
  --   In these cases, rather than issuing a call to Report.Failed, calling
  --   TCTouch.Implementation_Check will check that sensitivity, and if
  --   the implementation is attempting to validate against the specific
  --   annex, Report.Failed will be called, otherwise, Report.Not_Applicable
  --   will be called.
  begin

    case Annex is
      when Annex_C =>
        if ImpDef.Validating_Annex_C then
          Report.Failed( Message );
        else
          Report.Not_Applicable( Message & " Annex C not supported" );
       end if;

      when Annex_D =>
        if ImpDef.Validating_Annex_D then
          Report.Failed( Message );
        else
          Report.Not_Applicable( Message & " Annex D not supported" );
       end if;

      when Annex_E =>
        if ImpDef.Validating_Annex_E then
          Report.Failed( Message );
        else
          Report.Not_Applicable( Message & " Annex E not supported" );
       end if;

      when Annex_F =>
        if ImpDef.Validating_Annex_F then
          Report.Failed( Message );
        else
          Report.Not_Applicable( Message & " Annex F not supported" );
       end if;

      when Annex_G =>
        if ImpDef.Validating_Annex_G then
          Report.Failed( Message );
        else
          Report.Not_Applicable( Message & " Annex G not supported" );
       end if;

      when Annex_H =>
        if ImpDef.Validating_Annex_H then
          Report.Failed( Message );
        else
          Report.Not_Applicable( Message & " Annex H not supported" );
       end if;
    end case;
 end Implementation_Check;

end TCTouch;
