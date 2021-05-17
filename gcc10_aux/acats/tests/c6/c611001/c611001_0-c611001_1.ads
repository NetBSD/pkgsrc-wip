
generic
package C611001_0.C611001_1 is

   pragma Assertion_Policy (Check);

   package Bounded renames C611001_1;

   type Bounded_Stack(<>) is new Stack with private;

   function Create(Size: Natural) return Bounded_Stack
      with Post => Bounded.Size(Create'Result) = Size
                        and Count(Create'Result) = 0;

   function Size(S : Bounded_Stack) return Natural;

   function Count(S : Bounded_Stack) return Natural
      with Post => (Count'Result <= Size(S));

   function Is_Empty (S : Bounded_Stack) return Boolean
      is (Count(S) = 0);

   function Is_Full (S : Bounded_Stack) return Boolean
      is (Count(S) = Size(S));

   procedure Push (S : in out Bounded_Stack; I : in Item)
      with Pre => Count(S) < Size(S),
           Post => Count(S) = Count(S)'Old + 1;

   function Pop(S : in out Bounded_Stack) return Item
      with Pre => Count(S) > 0,
           Post => Count(S) = Count(S)'Old - 1;

private

   type Item_Array is array (Positive range <>) of Item;
   type Bounded_Stack(Size : Natural) is new Stack with record
      Count : Natural := 0;
      Items : Item_Array (1 .. Size);
   end record;

   function Size(S : Bounded_Stack) return Natural is (S.Size);

   function Count(S : Bounded_Stack) return Natural is (S.Count);

end C611001_0.C611001_1;
