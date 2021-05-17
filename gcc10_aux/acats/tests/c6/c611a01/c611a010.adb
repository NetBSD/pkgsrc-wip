
with Ada.Numerics.Elementary_Functions;
with Report;

package body C611A010 is

   function Local_Distance (O : in Object) return Float is
     (Ada.Numerics.Elementary_Functions.Sqrt
        (O.X_Coord ** 2 + O.Y_Coord ** 2));

   function Distance (O : in Object) return Float is
   begin
      if not F611A00.TC_Log_Object_Distance_Pre_Class_Called then
         Report.Failed
          ("Distance's Pre'Class should have been called before" &
           " the subprogram body");
         F611A00.TC_Output;
      end if;

      if not F611A00.TC_Log_Object_Distance_Specific_Pre_Called then
         Report.Failed
          ("Distance's specific precondition should have been" &
           "called before the subprogram body");
         F611A00.TC_Output;
      end if;

      F611A00.TC_Object_Distance_Called := True;

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
   function Not_Too_Far (O : in Object) return Boolean is
   begin
      F611A00.TC_Object_Not_Too_Far_Called := True;

      return Local_Distance (O) <= 10.0;
   end Not_Too_Far;

   function Not_Too_Near (O : in Object) return Boolean is
   begin
      F611A00.TC_Object_Not_Too_Near_Called := True;

      return Local_Distance (O) >= 1.0;
   end Not_Too_Near;

end C611A010;
