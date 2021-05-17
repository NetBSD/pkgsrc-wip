
with Ada.Numerics.Elementary_Functions;
with F611A00;
with Report;

package body C611A030.Child is

   function Local_Distance (T : in Triangle) return Float is
     (Ada.Numerics.Elementary_Functions.Sqrt
        (T.X_Coord ** 2 + T.Y_Coord ** 2));

   function Distance (T : in Triangle) return Float is
   begin
      if not (F611A00.TC_Object_Distance_Pre_Class_Called or
              F611A00.TC_Triangle_Distance_Pre_Class_Called) then
         Report.Failed
          ("Distance's class-wide precondition (comprising an " &
           "'or' of both Object's Pre'Class and Triangle's Pre'Class) " &
           "should have been called before the subprogram body");
         -- Note that we only have to have called one or the other
         -- precondition, as if one is True, the other doesn't need to be
         -- evaluated. (And we don't necessarily evaluate all of them for a
         -- dispatching call.)
         F611A00.TC_Output;
      end if;

      F611A00.TC_Triangle_Distance_Called := True;

      if F611A00.TC_Object_Distance_Post_Class_Called or
         F611A00.TC_Triangle_Distance_Post_Class_Called then
         Report.Failed
          ("Some part of Distance's class-wide postcondition was " &
           "was called before the subprogram body completed");
         -- Note that we only have to have called one or the other
         -- precondition, as if one is True, the other doesn't need to be
         -- evaluated. (And we don't necessarily evaluate all of them for a
         -- dispatching call.)
         F611A00.TC_Output;
      end if;
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

   -- function X_Coord_S inherited

   function Y_Coord (T : in Triangle) return Float is
   begin
      F611A00.TC_Triangle_Y_Coord_Called := True;

      return T.Y_Coord;
   end Y_Coord;

   -- Postcondition functions
   function Distance_Is_Positive (T : in Triangle) return Boolean is
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

      return Local_Distance (T) >= 1.0;
   end Not_Too_Near;

   function Area_Is_Positive (Area : in Float) return Boolean is
     (Area >= 0.0);

end C611A030.Child;
