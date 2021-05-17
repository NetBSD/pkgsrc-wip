

     --==================================================================--


with CC51009_0;

package CC51009_2 is

   generic
      type Element is private;
   package Set_Abstraction is

      type Set is private;

      procedure Add (Elem : Element; To_Set : in out Set);

      function Union (Left, Right : Set) return Set;

      function Intersection (Left, Right : Set) return Set;

      function "=" (Left, Right : Set) return Boolean;

      --  Instantiation with uncompleted private and private formal types

      package The_Set_Signature
        is new CC51009_0.Set_Signature (Element, Set);

   private

      type Set_Range is range 0 .. 20;

      type Element_Array is
        array (Set_Range range 1 .. Set_Range'Last) of Element;

      type Set is record
         Last_Element : Set_Range := 0;
         Elements     : Element_Array;
      end record;

   end Set_Abstraction;

end CC51009_2;
