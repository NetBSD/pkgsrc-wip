
with Ada.Numerics.Elementary_Functions;
with Report;

package body C611A030 is

   function Local_Distance (O : in Object) return Float is
      -- Simulate a bug in the distance routine that fails the postcondition:
      (if O.Y_Coord = -0.25 then -1.0
       else Ada.Numerics.Elementary_Functions.Sqrt
                  (O.X_Coord ** 2 + O.Y_Coord ** 2));

   function Distance (O : in Object) return Float is
   begin
      if not F611A00.TC_Object_Distance_Pre_Class_Called then
         Report.Failed
          ("Distance's Pre'Class should have been called before" &
           " the subprogram body");
         F611A00.TC_Output;
      end if;

      F611A00.TC_Object_Distance_Called := True;

      if F611A00.TC_Object_Distance_Post_Class_Called then
         Report.Failed
          ("Distance's class-wide postcondition was " &
           "was called before the subprogram body completed");
         -- Note that we only have to have called one or the other
         -- precondition, as if one is True, the other doesn't need to be
         -- evaluated. (And we don't necessarily evaluate all of them for a
         -- dispatching call.)
         F611A00.TC_Output;
      end if;

      return Local_Distance (O);
   end Distance;

   procedure Move (O : in out Object'Class;
                   X : in     Float;
                   Y : in     Float) is
   begin
      O.X_Coord := X;
      O.Y_Coord := Y;
   end Move;

   function X_Coord (O : in Object) return Float is
   begin
      F611A00.TC_Object_X_Coord_Called := True;

      return O.X_Coord;
   end X_Coord;

   function Y_Coord (O : in Object) return Float is
   begin
      F611A00.TC_Object_Y_Coord_Called := True;

      return O.Y_Coord;
   end Y_Coord;

   -- Postcondition functions
   function Distance_Is_Positive (O : in Object) return Boolean is
   begin
      F611A00.TC_Object_Distance_Is_Positive_Called := True;

      return Local_Distance (O) >= 0.0;
   end Distance_Is_Positive;

   function Not_Too_Far (O : in Object) return Boolean is
   begin
      F611A00.TC_Object_Not_Too_Far_Called := True;

      return Local_Distance (O) <= 10.0;
   end Not_Too_Far;

   function Not_Too_Near (O : in Object) return Boolean is
   begin
      F611A00.TC_Object_Not_Too_Near_Called := True;

      return Local_Distance (O) <= 10.0;
   end Not_Too_Near;

end C611A030;
