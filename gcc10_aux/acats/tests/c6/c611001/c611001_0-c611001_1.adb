
package body C611001_0.C611001_1 is

   pragma Assertion_Policy (Check);

   function Create(Size: Natural) return Bounded_Stack is
   begin
      return Result : Bounded_Stack (Size => Size);
   end Create;

   procedure Push (S : in out Bounded_Stack; I : in Item) is
   begin
      pragma Assert (not Is_Full (S));
      S.Count := S.Count + 1;
      S.Items (S.Count) := I;
   end Push;

   function Pop(S : in out Bounded_Stack) return Item is
   begin
      pragma Assert (not Is_Empty (S));
      S.Count := S.Count - 1;
      return S.Items (S.Count + 1);
   end Pop;

end C611001_0.C611001_1;
