
package body C452005_B is

   use type C452005_A.Kind_Type;

   use type C452005_A.Nonlim_Data_Type;

   function "=" (Left, Right : Lim_List) return Boolean is
   begin
      for I in Left'Range loop
         if Left(I).Kind  /= Right(I).Kind or else
            Left(I).Value /= Right(I).Value then
            return False;
         elsif Left(I).Kind = C452005_A.Data_End then
            return True; -- Don't look at the rest of the array.
         -- else continue comparing.
         end if;
      end loop;
      return True;
   end "=";

   function "=" (Left, Right : Nonlim_List) return Boolean is
   begin
      for I in Left'Range loop
         if Left(I) /= Right(I) then
            return False;
         elsif Left(I).Kind = C452005_A.Data_End then
            return True; -- Don't look at the rest of the array.
         -- else continue comparing.
         end if;
      end loop;
      return True;
   end "=";

   procedure Append (Obj : in out Nonlim_List;
                     Val : in C452005_A.Nonlim_Data_Type) is
   begin
      for I in Obj'Range loop
         if Obj(I).Kind = C452005_A.Data_End then
            Obj(I) := Val;
            if I /= Obj'Last then
               Obj(I+1) := (Kind => C452005_A.Data_End, Value => <>);
            -- else last element of list.
            end if;
         -- else not the end, keep looking.
         end if;
      end loop;
   end Append;

end C452005_B;
