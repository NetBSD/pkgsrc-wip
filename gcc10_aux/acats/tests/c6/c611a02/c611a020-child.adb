
with Ada.Numerics.Elementary_Functions;
with F611A00;
with Report;

package body C611A020.Child is

   function Local_Distance (T : in Triangle) return Float is
     (Ada.Numerics.Elementary_Functions.Sqrt
        (T.X_Coord ** 2 + T.Y_Coord ** 2));

   function Distance (T : in Triangle) return Float is
   begin
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

   -- function X_Coord   inherited

   -- function Y_Coord   inherited

   -- Postcondition functions
   function Distance_Is_Positive   (T : in Triangle) return Boolean is
   begin
      F611A00.TC_Triangle_Distance_Is_Positive_Called := True;

      return Local_Distance (T) >= 0.0;
   end Distance_Is_Positive;

   function Not_Too_Far (T : in Triangle) return Boolean is
   begin
      F611A00.TC_Triangle_Not_Too_Far_Called := True;

      return Local_Distance (T) <= 10.0;
   end Not_Too_Far;

   function Not_Too_Near (T : in Triangle) return Boolean is
   begin
      F611A00.TC_Triangle_Not_Too_Near_Called := True;

      return Local_Distance (T) >= 2.0;
   end Not_Too_Near;

end C611A020.Child;
