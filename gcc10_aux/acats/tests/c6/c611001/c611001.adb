
with Report;
with Ada.Assertions;
with Ada.Exceptions;
with C611001_0.C611001_1;
procedure C611001 is

   pragma Assertion_Policy (Check);

   type My_Int is range 1 .. 1000;
   generic package Stack_Interfaces renames C611001_0;
   package Int_Stack is new Stack_Interfaces(My_Int);
   package Int_BStack is new Int_Stack.C611001_1;
   use Int_BStack;
   S : Bounded_Stack := Create (3);
   X : My_Int;
begin
   Report.Test ("C611001", "Pre and Post conditions");
   Report.Comment ("Push three times");
   Push (S, 11);
   Push (S, 22);
   Push (S, 33);

   Report.Comment ("Verify that Count is three");
   if Count (S) /= 3 then
       Report.Failed ("Count should be 3, is actually" &
         Natural'Image (Count (S)));
   end if;

   Report.Comment ("Pop and verify we get a 33");
   X := Pop (S);
   if X /= 33 then
       Report.Failed ("Expected 33 on Pop, found" &
         My_Int'Image (X));
   end if;

   Report.Comment ("Pop and verify we get a 22");
   X := Pop (S);
   if X /= 22 then
       Report.Failed ("Expected 22 on Pop, found" &
         My_Int'Image (X));
   end if;

   Report.Comment ("Verify that Count is now one");
   if Count (S) /= 1 then
       Report.Failed ("Count should be 1, is actually" &
         Natural'Image (Count (S)));
   end if;

   Report.Comment
     ("Try to push three items, with the last overflowing the stack");

   begin
      Push (S, 222);
      Push (S, 333);
   exception
      when E : others =>
          Report.Failed ("Unexpected exception raised: " &
            Ada.Exceptions.Exception_Name (E));
   end;

   begin
      Push (S, 444);
   exception
      when E : Ada.Assertions.Assertion_Error =>
          Report.Comment ("Assertion_Error raised");
          Report.Comment ("Exception message is: """ &
            Ada.Exceptions.Exception_Message (E) & '"');
          Report.Comment ("Verify that count is 3");
          pragma Assert (Count (S) = 3);

          Report.Comment ("Pop the stack and verify we get 333");
          X := Pop (S);
          pragma Assert (X = 333);

      when E : others =>
          Report.Failed ("Wrong exception raised: " &
            Ada.Exceptions.Exception_Name (E));
   end;
   Report.Result;
end C611001;
