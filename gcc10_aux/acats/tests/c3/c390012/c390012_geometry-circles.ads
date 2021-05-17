
package C390012_Geometry.Circles is

   type Circle is new Object with private;

   -- Concrete versions of abstract routines:
   function Make_Object (P : not null access Params) return Circle;
      -- For a Circle, the size is the radius of the circle.
   function Area (C : in Circle) return Float;
   function Name (C : in Circle) return String;
   function Size_Param (C : in Circle) return Float;

private

   type Circle is new Object with
      record
         Radius : Float;
      end record;

end C390012_Geometry.Circles;
