
----------------------------------------------------------------- CC40001_1

with Ada.Calendar;
package CC40001_0.CC40001_1 is

  type Object_In_Time(ID: Character) is
    new Simple_Object(ID) with
      record
        Birth : Ada.Calendar.Time;
        Activity : Ada.Calendar.Time;
      end record;

  procedure User_Operation( COB: in out Object_In_Time;
                           Name: String );

  procedure Initialize( COB: in out Object_In_Time );
  procedure Adjust    ( COB: in out Object_In_Time );
  procedure Finalize  ( COB: in out Object_In_Time );

end CC40001_0.CC40001_1;
