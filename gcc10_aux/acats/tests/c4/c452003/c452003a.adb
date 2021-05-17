

with Report;
with Ada.Assertions;
package body C452003A is

   pragma Assertion_Policy (Check);

   Global_Root_Obj : aliased C452003_Root.Root_Type := (Id => 3);

   Global_Child_Obj : aliased C452003_Root.Child.Child_Type :=
                     (Id => 3, Name => "ZZZZ");

   procedure Force_Dispatch_Save (
                 The_Obj : access C452003_Root.Root_Type'Class) is
   begin
      C452003_Root.Save (The_Obj);
   end Force_Dispatch_Save;

   function Force_Dispatch_Is_Present (
           The_Obj : access C452003_Root.Root_Type'Class) return Boolean is
   begin
      return C452003_Root.Is_Present (The_Obj);
   end Force_Dispatch_Is_Present;

   procedure Do_Tests (Nested_Obj : access C452003_Root.Root_Type'Class;
                       Is_Root : in Boolean) is
      An_Obj : access C452003_Root.Root_Type'Class;
   begin
      -- First, try calling Save with the parameter, it should fail the
      -- precondition (Objective 2, failure):
      begin
         Nested_Obj.Save; -- Prefixed call.
         Report.Comment ("Prefixed Save call succeeded with nested object" &
            " - Is_Root=" & Boolean'Image(Is_Root));
      exception
         when Ada.Assertions.Assertion_Error =>
            Report.Comment ("Precondition for prefixed Save call fails as " &
                "expected - Is_Root=" & Boolean'Image(Is_Root));
         when Program_Error =>
            Report.Failed ("Precondition on prefixed Save call did not fail, "&
                "conversion did - Is_Root=" & Boolean'Image(Is_Root));
      end;

      begin
         C452003_Root.Save (Nested_Obj); -- Normal call.
         Report.Failed ("Save call succeeded with nested object - Is_Root=" &
            Boolean'Image(Is_Root));
      exception
         when Ada.Assertions.Assertion_Error =>
            Report.Comment ("Precondition for Save call fails as " &
                "expected - Is_Root=" & Boolean'Image(Is_Root));
         when Program_Error =>
            Report.Failed ("Precondition on Save call did not fail, " &
                "conversion did - Is_Root=" & Boolean'Image(Is_Root));
      end;

      begin
         Force_Dispatch_Save (Nested_Obj); -- Dispatching call on Save.
         Report.Failed ("Dispatching save call succeeded with nested " &
            "object - Is_Root=" & Boolean'Image(Is_Root));
      exception
         when Ada.Assertions.Assertion_Error =>
            Report.Comment ("Precondition for dispatching Save call fails " &
                "as expected - Is_Root=" & Boolean'Image(Is_Root));
         when Program_Error =>
            Report.Failed ("Precondition on dispatching Save call did not " &
                "fail, conversion did - Is_Root=" & Boolean'Image(Is_Root));
      end;

      -- Now, try the appropriate global object (Objective 2, success):
      begin
         if Is_Root then
            Force_Dispatch_Save (Global_Root_Obj'Access);
         else
            Force_Dispatch_Save (Global_Child_Obj'Access);
         end if;
         Report.Comment ("Save call succeeded with global object - Is_Root=" &
            Boolean'Image(Is_Root));
      exception
         when Ada.Assertions.Assertion_Error =>
            Report.Comment ("Precondition for Save call failed for global " &
                "object - Is_Root=" & Boolean'Image(Is_Root));
         when Program_Error =>
            Report.Failed ("Precondition on Save call OK, but conversion " &
                "failed - Is_Root=" & Boolean'Image(Is_Root));
      end;

      -- Check that the usual membership works (Objective 2):
      begin
         if (if Is_Root then
                Force_Dispatch_Is_Present (Global_Root_Obj'Access)
             else
                Force_Dispatch_Is_Present (Global_Child_Obj'Access)) then
            Report.Comment ("Is_Present OK with global object - Is_Root=" &
               Boolean'Image(Is_Root));
         else
            Report.Failed ("Is_Present incorrect answer with global object" &
               " - Is_Root=" & Boolean'Image(Is_Root));
         end if;
      exception
         when Program_Error =>
            Report.Failed ("Is_Present raised Program_Error, conversion " &
                "failed - Is_Root=" & Boolean'Image(Is_Root));
      end;

      begin
         if C452003_Root.Is_Present (Nested_Obj) then
            Report.Failed ("Is_Present incorrect answer with nested object" &
               " - Is_Root=" & Boolean'Image(Is_Root));
         else
            Report.Comment ("Is_Present OK with nested object" &
               " - Is_Root=" & Boolean'Image(Is_Root));
         end if;
      exception
         when Program_Error =>
            Report.Failed ("Is_Present raised Program_Error with nested " &
                "object, conversion failed - Is_Root=" &
                Boolean'Image(Is_Root));
      end;

      begin
         if Force_Dispatch_Is_Present (Nested_Obj) then
            Report.Failed ("Dispatching Is_Present incorrect answer with " &
               "nested object - Is_Root=" & Boolean'Image(Is_Root));
         else
            Report.Comment ("Dispatching Is_Present OK with nested object" &
               " - Is_Root=" & Boolean'Image(Is_Root));
         end if;
      exception
         when Program_Error =>
            Report.Failed ("Dispatching Is_Present raised Program_Error with "&
                "nested object, conversion failed - Is_Root=" &
                Boolean'Image(Is_Root));
      end;

      -- Check that the membership works on a stand-alone object of an
      -- anonymous access type:
      declare
         procedure Check_It (Is_OK : in Boolean; Code : in Character) is
         begin
            if An_Obj not in C452003_Root.Any_Root_Ptr then
               if Is_OK then
                  Report.Failed ("Check_It incorrect answer case " & Code);
               end if;
            else
               if not Is_OK then
                  Report.Failed ("Check_It incorrect answer case " & Code);
               end if;
               C452003_Root.Save (An_Obj); -- Should be OK.
            end if;
         end Check_It;
      begin
         if Is_Root then
            An_Obj := Nested_Obj;
            Check_It (Is_OK => False, Code => 'A');
            An_Obj := Global_Root_Obj'Access;
            Check_It (Is_OK => True, Code => 'B');
         else
            An_Obj := Nested_Obj;
            Check_It (Is_OK => False, Code => 'C');
            An_Obj := Global_Child_Obj'Access;
            Check_It (Is_OK => True, Code => 'D');
         end if;
      exception
         when Ada.Assertions.Assertion_Error =>
            Report.Failed ("Check_It raised Asserion_Error " &
                "- Is_Root=" & Boolean'Image(Is_Root));
         when Program_Error =>
            Report.Failed ("Check_It raisedd Program_Error " &
                "- Is_Root=" & Boolean'Image(Is_Root));
      end;

      -- Call Force_Save with various parameters, to check that the tag check
      -- is made (and conditional on whether the object is null).
      -- (Objectives 3 and 4).
      declare
         R : C452003_Root.Child.TC_Result;
         use all type C452003_Root.Child.TC_Result;
      begin
         begin
            C452003_Root.Child.Force_Save (null, R);
            if R = Is_Null then
               Report.Comment ("Force_Save OK with null");
            else
               Report.Failed ("Force_Save null wrong result - " &
                  C452003_Root.Child.TC_Result'Image (R));
            end if;
         exception
            when Program_Error =>
               Report.Failed ("Unexpected Program_Error from Force_Save " &
                  "with null");
         end;
         begin
            if Is_Root then
               C452003_Root.Child.Force_Save (Global_Root_Obj'Access, R);
               if R = Wrong_Tag then
                  Report.Comment ("Force_Save OK with Global_Root");
               else
                  Report.Failed ("Force_Save Global_Root wrong result - " &
                     C452003_Root.Child.TC_Result'Image (R));
               end if;
            else
               C452003_Root.Child.Force_Save (Global_Child_Obj'Access, R);
               if R = Done then
                  Report.Comment ("Force_Save OK with Global_Child");
               else
                  Report.Failed ("Force_Save Global_Child wrong result - " &
                     C452003_Root.Child.TC_Result'Image (R));
               end if;
            end if;
         exception
            when Program_Error =>
               Report.Failed ("Force_Save raised Program_Error with global " &
                   "object, conversion failed - Is_Root=" &
                   Boolean'Image(Is_Root));
         end;
      end;

      -- Call Force_Op with various parameters, to check that the conversion
      -- check is made (Objective 1).
      declare
         R : C452003_Root.TC_Result;
         use all type C452003_Root.TC_Result;
      begin
         begin
            C452003_Root.Force_Op (null, R);
            if R = Wrong_Kind then
               Report.Comment ("Force_Op OK with null");
            else
               Report.Failed ("Force_Op null wrong result - " &
                  C452003_Root.TC_Result'Image (R));
            end if;
         exception
            when Program_Error =>
               Report.Failed ("Unexpected Program_Error from Force_Op " &
                  "with null");
         end;
         begin
            if Is_Root then
               C452003_Root.Force_Op (Global_Root_Obj'Access, R);
            else
               C452003_Root.Force_Op (Global_Child_Obj'Access, R);
            end if;
            if R = Wrong_Kind then
               Report.Comment ("Force_Op OK with global object" &
                  " - Is_Root=" & Boolean'Image(Is_Root));
            else
               Report.Failed ("Force_Op global object wrong result - " &
                  C452003_Root.TC_Result'Image (R) &
                  " - Is_Root=" & Boolean'Image(Is_Root));
            end if;
         exception
            when Program_Error =>
               Report.Failed ("Force_Save raised Program_Error with global " &
                   "object, conversion failed - Is_Root=" &
                   Boolean'Image(Is_Root));
         end;
      end;
   end Do_Tests;

end C452003A;
