
package C611A010.Child is

   pragma Assertion_Policy (Check);

   type Triangle is new Object with private;

   overriding
   function  Distance              (T       : in      Triangle) return Float
    with Pre        => F611A00.TC_Log_Triangle_Distance_Specific_Pre_Called
                       and then Y_Coord (T) <= 5.0,
         Post       => F611A00.TC_Log_Triangle_Distance_Specific_Post_Called
                       and then Not_Too_Far (T);

   function  Area                  (T        : in     Triangle) return Float
    with Post'Class => Area_Is_Positive (Area'Result);

   function  Make_Triangle         (A, B, C  : in     Float)    return
    Triangle;

   procedure Get_Sides             (T        : in     Triangle;
                                    A, B, C  :    out Float);

   overriding
   function  X_Coord               (T        : in     Triangle) return Float;

   overriding
   function  Y_Coord               (T        : in     Triangle) return Float;

   -- Postcondition functions
   function Not_Too_Far            (T        : in     Triangle) return Boolean;

   function Not_Too_Near           (T        : in     Triangle) return Boolean;

   function Area_Is_Positive       (Area     : in     Float)    return Boolean;

private

   type Triangle is new Object with record
      A, B, C : Float;
   end record;

end C611A010.Child;
