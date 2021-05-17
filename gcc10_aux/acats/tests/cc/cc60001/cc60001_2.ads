
generic
   type Switch is tagged limited private;
   with procedure Flip   (It : in out Switch) is abstract <>;
   with function Is_On   (It : Switch) return Boolean is abstract <>;
package CC60001_2 is -- Switch operations.

   procedure Force_On (It : in out Switch'Class);

   procedure Force_Off (It : in out Switch'Class);

end CC60001_2;
