

package CC30003_Root is
   type Object is abstract tagged
      record
         X_Coord : Float;
         Y_Coord : Float;
      end record;

   function Area (Obj : Object) return Float is abstract;

   function Distance (Obj : Object) return Float;

end CC30003_Root;
