
with Ada.Numerics.Elementary_Functions;
with F611A00;
with Report;

package body C611A010.Child is

   function Local_Distance (T : in Triangle) return Float is
     (Ada.Numerics.Elementary_Functions.Sqrt
        (T.X_Coord ** 2 + T.Y_Coord ** 2));

   function Distance (T : in Triangle) return Float is
   begin
      if not (F611A00.TC_Log_Object_Distance_Pre_Class_Called or
              F611A00.TC_Log_Triangle_Distance_Pre_Class_Called) then
         Report.Failed
          ("Distance's class-wide precondition (inherited from Object) " &
           "should have been called before the subprogram body");
         F611A00.TC_Output;
      end if;

      if not F611A00.TC_Log_Triangle_Distance_Specific_Pre_Called then
         Report.Failed
          ("Distance's specific precondition should have been" &
           "called before the subprogram body");
         F611A00.TC_Output;
      end if;

      F611A00.TC_Triangle_Distance_Called := True;

      return Local_Distance (T);
   end Distance;

   -- Using Heron's formula
   function Area (T : in Triangle) return Float is
      S : constant Float := (T.A + T.B + T.C) / 2.0;
   begin
      return Ada.Numerics.Elementary_Functions.Sqrt
        ((S - T.A) * (S - T.B) * (S - T.C));
   end Area;

   function Make_Triangle (A, B, C : in Float) return Triangle is
      (A       => A,
       B       => B,
       C       => C,
       X_Coord => 0.0,
       Y_Coord => 0.0);

   procedure Get_Sides (T       : in      Triangle;
                        A, B, C :     out Float) is
   begin
       A := T.A;
       B := T.B;
       C := T.C;
   end Get_Sides;

   function X_Coord (T : in Triangle) return Float is
   begin
      F611A00.TC_Triangle_X_Coord_Called := True;

      return T.X_Coord;
   end X_Coord;

   function Y_Coord (T : in Triangle) return Float is
   begin
      F611A00.TC_Triangle_Y_Coord_Called := True;

      return T.Y_Coord;
   end Y_Coord;

   -- Postcondition functions
   function Not_Too_Far (T : in Triangle) return Boolean is
   begin
      F611A00.TC_Triangle_Not_Too_Far_Called := True;

      return Local_Distance (T) <= 10.0;
   end Not_Too_Far;

   function Not_Too_Near (T : in Triangle) return Boolean is
   begin
      F611A00.TC_Triangle_Not_Too_Near_Called := True;

      return Local_Distance (T) >= 1.0;
   end Not_Too_Near;

   function Area_Is_Positive (Area : in Float) return Boolean is
     (Area >= 0.0);

end C611A010.Child;
