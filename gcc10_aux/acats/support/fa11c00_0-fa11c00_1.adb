
     --=================================================================--

package body FA11C00_0.FA11C00_1 is    -- Package body Animal.Mammal

   function Image (M : Mammal) return String is
   begin
      return ("Mammal Species:  " & M.Common_Name);
   end Image;

end FA11C00_0.FA11C00_1;               -- Package body Animal.Mammal
