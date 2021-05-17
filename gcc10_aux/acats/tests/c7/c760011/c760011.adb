
--------------------------------------------------------------------- C760011

with Report;
with TCTouch;
with C760011_0;
with Ada.Finalization; -- needed to be able to create extension aggregates
procedure C760011 is

  use type C760011_0.Controlled_Type;
  use type C760011_0.Controlled_Type'Class;
  use type C760011_0.Non_Controlled;

  subtype AFC is Ada.Finalization.Controlled;

  procedure Check_Result( Tag : Character; Message : String ) is
  -- make allowance for 7.6(21) optimizations
  begin
    if C760011_0.Initialized(Tag) then
      TCTouch.Assert(C760011_0.Finalized(Tag),Message);
    elsif C760011_0.Under_Debug then
      Report.Comment("Optimized away: " & Tag );
    end if;
  end Check_Result;

  procedure Subtest_1 is


    procedure Subtest_1_Local_1 is
      An_Object : C760011_0.Controlled_Type'Class
                := C760011_0.Controlled_Type'(AFC with 'X', "ONE*");
                   -- initialize An_Object
    begin
      if C760011_0.Controlled_Type(An_Object)   
         = C760011_0.Controlled_Type'(AFC with 'A', "ONE*") then
        Report.Failed("Comparison bad");  -- A = X !!!
      end if;
    end Subtest_1_Local_1;
    -- An_Object must be Finalized by this point.

    procedure Subtest_1_Local_2 is
      An_Object : C760011_0.Controlled_Type('B');
    begin
      An_Object := (AFC with 'B',  "TWO!" );
      if Report.Ident_Char(An_Object.Tag) /= 'B' then
        Report.Failed("Subtest_1_Local_2 Optimization Foil: Bad Data!");
      end if;
    exception
      when others => Report.Failed("Bad controlled assignment");
    end Subtest_1_Local_2;
    -- An_Object must be Finalized by this point.

    procedure Subtest_1_Local_3 is
      An_Object : C760011_0.Non_Controlled('C');
    begin
      TCTouch.Assert_Not(C760011_0.Finalized('C'),
                           "Non_Controlled declaration C");
      An_Object := C760011_0.Non_Controlled'('C', Controlled_Component
                                     => (AFC with 'C', "TEE!"));
      if Report.Ident_Char(An_Object.Tag) /= 'C' then
        Report.Failed("Subtest_1_Local_3 Optimization Foil: Bad Data!");
      end if;
    end Subtest_1_Local_3;
    -- Only controlled components of An_Object must be finalized; it is an
    -- error to call Finalize for An_Object

  begin
    Subtest_1_Local_1;
    Check_Result( 'A', "Aggregate in subprogram 1" );

    Subtest_1_Local_2;
    Check_Result( 'B', "Aggregate in subprogram 2" );

    Subtest_1_Local_3;
    Check_Result( 'C', "Embedded aggregate in subprogram 3" );
  end Subtest_1;


  procedure Subtest_2 is
    -- using 'Z' for both evades order issues
    Con_Object : C760011_0.Controlled_Type('Z');
    Non_Object : C760011_0.Non_Controlled('Z');
  begin
    if Report.Ident_Bool( Con_Object = C760011_0.Create('D') ) then
      Report.Failed("Con_Object catastrophe");
    end if;
     -- Controlled function result should be finalized by now
    Check_Result( 'D', "Function Result" );

    if Report.Ident_Bool( Non_Object = C760011_0.Create('E') ) then
      Report.Failed("Non_Object catastrophe");
    end if;
     -- Controlled component of function result should be finalized by now
    Check_Result( 'E', "Function Result" );
  end Subtest_2;


  procedure Subtest_3(Con : in C760011_0.Controlled_Type) is
  begin
    if Con.Tag not in 'F'..'G' then  
      Report.Failed("Bad value passed to subtest 3 " & Con.Tag & ' ' 
                    & Report.Ident_Str(Con.TC_Component));
    end if;
  end Subtest_3;


  procedure Subtest_4(Non : in C760011_0.Non_Controlled) is
  begin
    if Non.Tag not in 'H'..'I' then  
      Report.Failed("Bad value passed to subtest 4 "
                   & Non.Tag & ' ' 
                   & Report.Ident_Str(Non.Controlled_Component.TC_Component));
    end if;
  end Subtest_4;


begin  -- Main test procedure.

  Report.Test ("C760011", "Check that anonymous objects of controlled " &
                          "types or types containing controlled types " &
                          "are finalized no later than the end of the " &
                          "innermost enclosing declarative_item or " &
                          "statement" );

  Subtest_1;

  Subtest_2;

  Subtest_3(C760011_0.Create('F'));
  Check_Result( 'F', "Function as formal F" );

  Subtest_3(C760011_0.Controlled_Type'(AFC with 'G',"GIGI"));
  Check_Result( 'G', "Aggregate as formal G" );

  Subtest_4(C760011_0.Create('H'));
  Check_Result( 'H', "Function as formal H" );

  Subtest_4(C760011_0.Non_Controlled'('I', (AFC with 'I',"IAGO")));
  Check_Result( 'I', "Aggregate as formal I" );

  Report.Result;

end C760011;
