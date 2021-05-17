

package C390012_Geometry.Ghosts is

   type Ghost is abstract new Object with private;
      -- This is not a real shape.

   function Size_Param (G : in Ghost) return Float;

   procedure Register;

private

   type Ghost is abstract new Object with null record;

end C390012_Geometry.Ghosts;
