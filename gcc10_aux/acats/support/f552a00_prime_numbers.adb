
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;

package body F552A00_Prime_Numbers is

   Disable_History : Boolean := False;
   --  Used to disable call history for calls to Is_Prime that are internal
   --  and not called as a result of loop iteration.

   function First (Object : Prime_Number_Set) return Natural is
   begin
      --  The first prime number is 3, unless the Prime_Number_Set only
      --  goes up to 2 or less, in which case a non-prime number is returned
      --  since the set does not contain a prime number.

      Ada.Strings.Unbounded.Append (Source => TC_Call_History,
                                    New_Item => '1');
      return (if Object.Max_Value >= 3 then 3 else Object.Max_Value);
   end First;

   function Next
     (Object : Prime_Number_Set;
      Value  : Natural)
      return   Natural is
   begin

      --  Disable logging of calls to Is_Prime inside this loop, since these
      --  calls are not directly related to iterator types.
      Disable_History := True;

      for I in Value + 1 .. Object.Max_Value loop
         if Is_Prime (I) then
            Ada.Strings.Unbounded.Append
              (Source   => TC_Call_History,
               New_Item => "N(" & Integer'Image (I) & ')');
            Disable_History := False;
            return I;
         end if;
      end loop;
      Disable_History := False;

      Ada.Strings.Unbounded.Append
        (Source   => TC_Call_History,
         New_Item => "N(" & Integer'Image (Value + 1) & ')');

      return Value + 1;
   end Next;

   function Is_Prime (Value : Natural) return Boolean is
   begin
      for I in 2 .. Integer (Sqrt (Float (Value))) loop
         if Value mod I = 0 then

            --  Not a prime number
            if not Disable_History then
               Ada.Strings.Unbounded.Append
                 (Source   => TC_Call_History,
                  New_Item => "H:F(" & Integer'Image (Value) & ')');
            end if;

            return False;
         end if;
      end loop;

      --  Is a prime number if the value is > 2.
      if not Disable_History then
         Ada.Strings.Unbounded.Append
           (Source   => TC_Call_History,
            New_Item => "H:" &
                        (if Value > 2 then "T(" else "F(") &
                        Integer'Image (Value) &
                        ')');
      end if;

      return (Value > 2);
   end Is_Prime;

   function Iterate
     (Set  : Prime_Number_Set)
      return Prime_Number_Iterator.Forward_Iterator'Class is
   begin
      Ada.Strings.Unbounded.Append (Source => TC_Call_History,
                                    New_Item => 'I');
      return Result : Prime_Number_Set (Set.Max_Value) do
         null;
      end return;
   end Iterate;

end F552A00_Prime_Numbers;
