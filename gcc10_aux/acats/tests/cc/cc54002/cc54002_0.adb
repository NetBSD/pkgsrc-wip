

     --===================================================================--


package body CC54002_0 is

   procedure Put (List     : in out List_Type;
                  Elem_Ptr : in     Element_Ptr;
                  Location : in     Index) is
   begin
      List.Elements(Location) := Elem_Ptr;
   end Put;


   procedure Get (List     : in out List_Type;
                  Elem_Ptr :    out Element_Ptr;
                  Location : in     Index) is
   begin  -- Artificial: no provision for getting "empty" element.
      Elem_Ptr := List.Elements(Location);
   end Get;

end CC54002_0;
