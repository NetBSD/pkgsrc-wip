
     --==================================================================--

with C330001_0;
pragma Elaborate(C330001_0); -- Insure that the functions can be called.
private
package C330001_0.C330001_1 is  

   PrivateChild_Obj    : Tag_W_Disc := (D => 4, C1 => "ACVC");

   PrivateChild_Obj_01 : Indefinite_W_Inherit_Disc_1 
     := Indefinite_W_Inherit_Disc_1'(PrivateChild_Obj with S => 15);

   -- Since full view of Indefinite_W_Inherit_Disc_2 is indefinite in 
   -- the parent package, Indefinite_W_Inherit_Disc_2 needs an initialization
   -- expression.

   PrivateChild_Obj_02 : Indefinite_W_Inherit_Disc_2 := Indef_Func_2 (19);

   -- Since full view of FullViewDefinite_Unknown_Disc is definite in the 
   -- parent package, no initialization expression needed for 
   -- PrivateChild_Obj_03.

   PrivateChild_Obj_03 : FullViewDefinite_Unknown_Disc;

   PrivateChild_Obj_04 : Indefinite_No_Disc          := (12, 15);

end C330001_0.C330001_1;
