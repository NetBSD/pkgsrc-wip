
with C390012_Manager;
package body C390012_Geometry.Ghosts is

   function Size_Param (G : in Ghost) return Float is
   begin
      return 0.0;
   end Size_Param;

   procedure Register is
   begin
      C390012_Manager.Register (Ghost'Tag, 'G'); -- Register the Ghost type.
        -- We do this manually so the we don't have too many types to
        -- track successfully.
   end Register;

end C390012_Geometry.Ghosts;
