with Ada.Assertions;
with F611A00;
with C611A010;
with C611A010.Child;
with Report;

procedure C611A01 is

   pragma Assertion_Policy (Check);

   Assertion_Error_Raised : Boolean;
   Order_Error_Raised : Boolean;

   Outer_Distance : Float;

   My_Triangle : C611A010.Child.Triangle :=
                  C611A010.Child.Make_Triangle
                   (A => 3.0, B => 4.0, C => 5.0);

   My_X_Coord : Float;

   procedure Test_Get_Distance (O : in C611A010.Object'Class) is

      function Call_Get_Distance (O : in C611A010.Object'Class) return Float is
         Inner_Distance : Float;
      begin
         -- Dispatching call
         Inner_Distance := C611A010.Distance (O);
         return Inner_Distance;
      end Call_Get_Distance;
   begin
      begin
         Assertion_Error_Raised := False;
         Order_Error_Raised := False;
         Outer_Distance := Call_Get_Distance (O);
      exception
         when Ada.Assertions.Assertion_Error =>
            Assertion_Error_Raised := True;
         when F611A00.TC_Order_Error =>
            Order_Error_Raised := True;
      end;
   end Test_Get_Distance;

begin

   Report.Test
     ("C611A01",
      "Check that if both specific and class-wide preconditions (or " &
      "postconditions) are enabled and apply to a subprogram, then " &
      "Assertion_Error is raised appropriately");


   -- Should pass Object's Pre'Class and Post'Class, and
   -- Triangle's Pre and Post.

   F611A00.TC_Clear;

   My_Triangle.Move (X => 3.0, Y => 4.0);

   Test_Get_Distance (My_Triangle);

   if Assertion_Error_Raised then
      Report.Failed ("Assertion_Error raised (1)");
   elsif Order_Error_Raised then
      Report.Failed ("Postcondition should only have been called after the" &
        " subprogram body (1)");
   end if;

   if F611A00.TC_Object_X_Coord_Called or
      F611A00.TC_Object_Y_Coord_Called or
      (not F611A00.TC_Triangle_X_Coord_Called) or
      (not F611A00.TC_Triangle_Y_Coord_Called) then
      Report.Failed
        ("Precondition expressions should only have called " &
         "primitives appropriate for the tag, and should have called " &
         "both of them (1)");
      F611A00.TC_Output;
   end if;

   if F611A00.TC_Object_Not_Too_Near_Called or
      F611A00.TC_Object_Not_Too_Far_Called or
      (not F611A00.TC_Triangle_Not_Too_Near_Called) or
      (not F611A00.TC_Triangle_Not_Too_Far_Called) then
      Report.Failed
        ("Postconndition expressions should only have called " &
         "primitives appropriate for the tag, and should have called " &
         "both of them (1)");
      F611A00.TC_Output;
   end if;

   -- Should pass Object's Pre'Class but fail Triangle's Pre (postconditions
   -- are irrelevant here).

   F611A00.TC_Clear;

   My_Triangle.Move (X => 3.0, Y => 8.0);

   Test_Get_Distance (My_Triangle);

   if not Assertion_Error_Raised then
      Report.Failed ("Triangle precondition failure not detected");
   end if;

   if F611A00.TC_Object_X_Coord_Called or
      F611A00.TC_Object_Y_Coord_Called or
      (not F611A00.TC_Triangle_Y_Coord_Called) then
      -- Note: We don't know if X_Coord is called, as it doesn't have to
      -- be evaluated if the specific Pre was evaluated first.
      Report.Failed
        ("Precondition expressions should only have called " &
         "primitives appropriate for the tag, and should have called " &
         "at least Y Coord (2)");
      F611A00.TC_Output;
   end if;

   -- Should fail Object's Pre'Class but pass Triangle's Pre (postconditions
   -- are irrelevant here).

   F611A00.TC_Clear;

   My_Triangle.Move (X => -3.0, Y => 4.0);

   Test_Get_Distance (My_Triangle);

   if not Assertion_Error_Raised then
      Report.Failed ("Object precondition failure not detected");
   end if;

   if F611A00.TC_Object_X_Coord_Called or
      F611A00.TC_Object_Y_Coord_Called or
      (not F611A00.TC_Triangle_X_Coord_Called) then
      -- Note: We don't know if Y_Coord is called, as it doesn't have to
      -- be evaluated if the class-wide Pre was evaluated first.
      Report.Failed
        ("Precondition expressions should only have called " &
         "primitives appropriate for the tag, and should have called " &
         "at least X Coord (3)");
      F611A00.TC_Output;
   end if;

   -- Should fail Object's Post'Class but pass Triangle's Post.

   F611A00.TC_Clear;

   My_Triangle.Move (X => 0.0, Y => 0.0);

   Test_Get_Distance (My_Triangle);

   if not Assertion_Error_Raised then
      Report.Failed ("Object postcondition failure not detected");
      F611A00.TC_Output;
   end if;
   if Order_Error_Raised then
      Report.Failed ("Postcondition should only have been called after the" &
        " subprogram body (4)");
   end if;

   if F611A00.TC_Object_X_Coord_Called or
      F611A00.TC_Object_Y_Coord_Called or
      (not F611A00.TC_Triangle_X_Coord_Called) or
      (not F611A00.TC_Triangle_Y_Coord_Called) then
      Report.Failed
        ("Precondition expressions should only have called " &
         "primitives appropriate for the tag, and should have called " &
         "both of them (4)");
      F611A00.TC_Output;
   end if;

   if F611A00.TC_Object_Not_Too_Near_Called or
      F611A00.TC_Object_Not_Too_Far_Called or
      (not F611A00.TC_Triangle_Not_Too_Near_Called) then
      -- Note: We don't know if Not_Too_Far is called, as it doesn't have to
      -- be evaluated if the class-wide Post was evaluated first.
      Report.Failed
        ("Postcondition expressions should only have called " &
         "primitives appropriate for the tag, and should have called " &
         "at least Not_Too_Near (4)");
      F611A00.TC_Output;
   end if;

   -- Should fail Triangle's Post but pass Object's Post'Class.

   F611A00.TC_Clear;

   My_Triangle.Move (X => 12.0, Y => 4.0);

   Test_Get_Distance (My_Triangle);

   if not Assertion_Error_Raised then
      Report.Failed ("Triangle postcondition failure not detected");
      F611A00.TC_Output;
   end if;
   if Order_Error_Raised then
      Report.Failed ("Postcondition should only have been called after the" &
        " subprogram body (5)");
   end if;

   if F611A00.TC_Object_X_Coord_Called or
      F611A00.TC_Object_Y_Coord_Called or
      (not F611A00.TC_Triangle_X_Coord_Called) or
      (not F611A00.TC_Triangle_Y_Coord_Called) then
      Report.Failed
        ("Precondition expressions should only have called " &
         "primitives appropriate for the tag, and should have called " &
         "both of them (5)");
      F611A00.TC_Output;
   end if;

   if F611A00.TC_Object_Not_Too_Near_Called or
      F611A00.TC_Object_Not_Too_Far_Called or
      (not F611A00.TC_Triangle_Not_Too_Far_Called) then
      -- Note: We don't know if Not_Too_Near is called, as it doesn't have to
      -- be evaluated if the specific Post was evaluated first.
      Report.Failed
        ("Postcondition expressions should only have called " &
         "primitives appropriate for the tag, and should have called " &
         "at least Not_Too_Far (5)");
      F611A00.TC_Output;
   end if;

   Report.Result;

end C611A01;
