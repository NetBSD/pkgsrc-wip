

     --==================================================================--


package body CC70003_0 is

   -- The implementations of the operations below are purely artificial; the
   -- validity of their implementations in the context of the abstraction is
   -- irrelevant to the feature being tested.

   function View_Element (I : List_Size; L : List_Type) return Element_Type is
   begin
      return L(I).all;
   end View_Element;


   procedure Write_Element (I : in     List_Size;
                            L : in out List_Type;
                            E : in     Element_Type) is
   begin
      L(I) := new Element_Type'(E);
   end Write_Element;

end CC70003_0;
