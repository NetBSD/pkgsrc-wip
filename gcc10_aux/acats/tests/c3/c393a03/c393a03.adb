
--------------------------------------------------------------------- C393A03

with Report;
with F393A00_0;
with F393A00_1;
with C393A03_0;
with C393A03_1;
procedure C393A03 is

  A_Thing       : C393A03_1.Modular_Object;
  Another_Thing : C393A03_1.Modular_Object;

  procedure Initialize( It: in out C393A03_0.Counting_Object'Class ) is
  begin
    C393A03_0.Initialize( It );  -- dispatch to inherited procedure
  end Initialize;

  procedure Bump( It: in out C393A03_0.Counting_Object'Class ) is
  begin
    C393A03_0.Bump( It ); -- dispatch to non-abstract procedure
  end Bump;

  procedure Set_Max( It  : in out C393A03_1.Modular_Object'Class;
                     Val : Natural) is
  begin
    C393A03_1.Set_Max( It, Val ); -- dispatch to non-abstract procedure
  end Set_Max;

  procedure Swap( A, B  : in out C393A03_0.Counting_Object'Class ) is
  begin
    C393A03_0.Swap( A, B ); -- dispatch to inherited abstract procedure
  end Swap;

  procedure Zero( It: in out C393A03_0.Counting_Object'Class ) is
  begin
    C393A03_0.Zero( It ); -- dispatch to non-abstract procedure
  end Zero;

begin  -- Main test procedure.

   Report.Test ("C393A03", "Check that a non-abstract primitive subprogram "
			 & "of an abstract type can be called as a "
			 & "dispatching operation and that the body of this "
			 & "subprogram can make a dispatching call to an "
			 & "abstract operation of the corresponding "
			 & "abstract type" );

   A_Thing := C393A03_1.Create; -- Max_Value = Natural'Last
   F393A00_0.TC_Validate( "4", "Overridden primitive layer 2");

   Initialize( A_Thing );
   Initialize( Another_Thing );
   F393A00_0.TC_Validate( "aa", "Non-abstract primitive layer 0");
   
   Bump( A_Thing ); -- Tally = 1
   F393A00_0.TC_Validate( "A", "Non-abstract primitive layer 1");

   Set_Max( A_Thing, 42 ); -- Max_Value = 42
   F393A00_0.TC_Validate( "3", "Non-abstract normal layer 2");

   if not F393A00_1.Initialized( A_Thing ) then
     Report.Failed("Initialize didn't");
   end if;
   F393A00_0.TC_Validate( "b", "Class-wide layer 0");

   Swap( A_Thing, Another_Thing );
   F393A00_0.TC_Validate( "1", "Overridden abstract layer 2");

   Zero( A_Thing );
   F393A00_0.TC_Validate( "B2", "Non-abstract layer 0, calls dispatch");

   if C393A03_0.Value( A_Thing ) /= 0 then
     Report.Failed("Zero didn't");
   end if;
   F393A00_0.TC_Validate( "C", "Class-wide normal layer 2");

   Report.Result;

end C393A03;
