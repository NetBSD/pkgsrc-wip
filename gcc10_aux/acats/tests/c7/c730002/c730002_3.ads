
     --==================================================================--

with C730002_0; use C730002_0;
with C730002_2; use C730002_2;
generic
  type T is new C730002_2.Diesel_Series with private;
package C730002_3 is

   type Time_Of_Operation_Type is range 0..100_000;

   type Electric_Series is new T with private;

   procedure Routine_Maintenance (E  : in out Electric_Series;
                                  SR : in     Specialist_ID := Curly);

   -- Other electric specific operations... (not required in this test).

private

   type Electric_Series is new T with record
      Mean_Time_Between_Repair : Time_Of_Operation_Type := 0;
   end record; 

end C730002_3;
