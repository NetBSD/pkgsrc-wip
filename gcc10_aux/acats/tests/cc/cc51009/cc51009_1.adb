

     --==================================================================--


package body CC51009_1 is

   package body Set_Processing is

      procedure Test
        (Set_1 : in out Set_Type;
         Set_2 : Set_Type;
         Set_3 : Set_Type;
         Elt   : Element)
      is
      begin
         Set_1 := Intersection (Set_1, Set_2);

         Set_1 := Union (Set_1, Set_3);

         Add (Elt, Set_1);
      end Test;

   end Set_Processing;

end CC51009_1;
