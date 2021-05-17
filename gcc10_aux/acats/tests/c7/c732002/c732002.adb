
with Ada.Assertions;
with C732002_Places;
with C732002_Places.Inner;
with Report;

procedure C732002 is

   pragma Assertion_Policy (Check);

   My_Pt : C732002_Places.Disc_Pt_Type := C732002_Places.Init;

   My_Pt_Inner : C732002_Places.Inner.Ring_Pt_Type :=
                                               C732002_Places.Inner.Init;


   procedure Test_Invalid_Move_In_Inner is

      procedure Do_Invalid_Move_In_Inner is
      begin

         C732002_Places.Inner.Move_In (My_Pt_Inner);

      end Do_Invalid_Move_In_Inner;

   begin

      Do_Invalid_Move_In_Inner;

      Report.Failed
        ("Do_Invalid_Move_In_Inner should have raised Assertion_Error");

   exception

      when Ada.Assertions.Assertion_Error =>

         null; -- Invariant check failed, as expected.

   end Test_Invalid_Move_In_Inner;


   procedure Test_Invalid_Move_Out is

      procedure Do_Invalid_Move_Out is
      begin

         C732002_Places.Move_Out (My_Pt);

      end Do_Invalid_Move_Out;

   begin

      Do_Invalid_Move_Out;

      Report.Failed
           ("Do_Invalid_Move_Out should have raised Assertion_Error");

   exception

      when Ada.Assertions.Assertion_Error =>

         null; -- Invariant check failed, as expected.

   end Test_Invalid_Move_Out;


   procedure Test_Invalid_Negate is

      procedure Do_Invalid_Negate is
      begin

         C732002_Places.Negate (My_Pt);

      end Do_Invalid_Negate;

   begin

      Do_Invalid_Negate;

      Report.Failed
           ("Do_Invalid_Negate should have raised Assertion_Error");

   exception

      when Ada.Assertions.Assertion_Error =>

         null; -- Invariant check failed, as expected.

   end Test_Invalid_Negate;


   procedure Test_Invalid_Negate_Inner is

      -- The Positive_Quadrant invariant was class-wide so should apply.
      procedure Do_Invalid_Negate_Inner is
      begin

         C732002_Places.Inner.Negate (My_Pt_Inner);

      end Do_Invalid_Negate_Inner;

   begin

      Do_Invalid_Negate_Inner;

      Report.Failed
           ("Do_Invalid_Negate_Inner should have raised Assertion_Error");

   exception

      when Ada.Assertions.Assertion_Error =>

         null; -- Invariant check failed, as expected.

   end Test_Invalid_Negate_Inner;


   procedure Test_Valid_Move_In is
   begin

      C732002_Places.Move_In (My_Pt);

      if not C732002_Places.Check_Inside (My_Pt) then

         Report.Failed
           ("Incorrect moving in");

      end if;

   end Test_Valid_Move_In;


   procedure Test_Valid_Move_Out_Inner is
   begin

      -- The Check_In invariant was specific so should not apply.
      C732002_Places.Inner.Move_Out (My_Pt_Inner);

      if not C732002_Places.Inner.Check_Outside (My_Pt_Inner) then

         Report.Failed
           ("Incorrect moving out");

      end if;

   end Test_Valid_Move_Out_Inner;

begin

   Report.Test
     ("C732002",
      "Check differences between specific and class-wide type invariants");

   Test_Valid_Move_In;

   My_Pt := C732002_Places.Init;
   Test_Invalid_Move_Out;

   My_Pt := C732002_Places.Init;
   Test_Invalid_Negate;

   Test_Valid_Move_Out_Inner;

   My_Pt_Inner := C732002_Places.Inner.Init;
   Test_Invalid_Move_In_Inner;

   My_Pt_Inner := C732002_Places.Inner.Init;
   Test_Invalid_Negate_Inner;


   Report.Result;

end C732002;
