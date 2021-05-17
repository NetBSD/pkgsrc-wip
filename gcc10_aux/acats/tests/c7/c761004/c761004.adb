
------------------------------------------------------------------- C761004

with Report;
with TCTouch;
with C761004_0;
with C761004_Support;
with Ada.Finalization; -- needed to be able to create extension aggregates
procedure C761004 is

  Verbose : constant Boolean := False;

  package Sup renames C761004_Support;

  -- Subtest 1, general case.  Check that several objects declared in a
  -- subprogram are created, and finalized in opposite order.

  Subtest_1_Expected_Inits : constant := 3;

  procedure Subtest_1 is
    Item_1 : C761004_0.Global;
    Item_2, Item_3 : C761004_0.Global;
 begin
    if Item_2.Tag = Item_3.Tag then  -- not germane to the test
      Report.Failed("Duplicate tag");-- but helps prevent code elimination
    end if;
  end Subtest_1;

  -- Subtest 2, extension of the general case.  Check that several objects
  -- created identically on the stack (via a recursive procedure) are
  -- finalized in the opposite order of their creation.
  Subtest_2_Expected_Inits : constant := 12;
  User_Exception : exception;
  
  procedure Subtest_2 is
    
    Item_1 : C761004_0.Global;

    -- combine recursion and exit by exception:

    procedure Nested(Recurs: Natural) is
      Item_3 : C761004_0.Global;
    begin
      if Verbose then
        Report.Comment("going in: " & Item_3.Tag);
      end if;
      if Recurs = 1 then
        raise User_Exception;
      else
        Nested(Recurs -1);
      end if;
    end Nested;
    
    Item_2 : C761004_0.Global;
  
  begin
    Nested(10);
  end Subtest_2;

  -- subtest 3, check the case of objects embedded in structures:
  -- an array
  -- a record
  Subtest_3_Expected_Inits : constant := 3;
  procedure Subtest_3 is
    type G_List is array(Positive range <>) of C761004_0.Global;
    type Pandoras_Box is record
      G : G_List(1..1);
    end record;

    procedure Nested(Recursions: Natural) is
      Merlin : Pandoras_Box;
    begin
      if Recursions > 1 then
        Nested(Recursions-1);
      else
        TCTouch.Validate("","Final Nested call");
      end if;
    end Nested;

  begin
    Nested(3);
  end Subtest_3;

  -- subtest 4, check the case of objects embedded in structures:
  -- an array
  -- a record
  Subtest_4_Expected_Inits : constant := 3;
  procedure Subtest_4 is
    type S_List is array(Positive range <>) of C761004_0.Second;
    type Pandoras_Box is record
      S : S_List(1..1);
    end record;

    procedure Nested(Recursions: Natural) is
      Merlin : Pandoras_Box;
    begin
      if Recursions > 1 then
        Nested(Recursions-1);
      else
        TCTouch.Validate("","Final Nested call");
      end if;
    end Nested;

  begin
    Nested(3);
  end Subtest_4;

begin  -- Main test procedure.

  Report.Test ("C761004", "Check that an object of a controlled type "
                        & "is finalized when the enclosing master is "
                        & "complete, left by a transfer of control, "
                        & "and performed in the correct order" );

  Subtest_1;
  Sup.Validate(Subtest_1_Expected_Inits,1); 

  Subtest_2_Frame: begin
    Sup.Inits_Called := 0;
    Subtest_2;
  exception           
    when User_Exception => null;
    when others => Report.Failed("Wrong Exception, Subtest 2");
  end Subtest_2_Frame;
  Sup.Validate(Subtest_2_Expected_Inits,2);
  
  Sup.Inits_Called := 0;
  Subtest_3;
  Sup.Validate(Subtest_3_Expected_Inits,3);
  
  Sup.Inits_Called := 0;
  Subtest_4;
  Sup.Validate(Subtest_4_Expected_Inits,4);
  
  Report.Result;

end C761004;
