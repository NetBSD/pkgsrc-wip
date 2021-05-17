
     --==================================================================--

package body CC51010_1 is

   procedure Add (Elem : Integer; To_Set : in out Set) is
      Found : Boolean := False;
   begin
      for E in To_Set.Integers'first .. To_Set.Last_Integer loop
         if To_Set.Integers (E) = Elem then
            Found := True;
            exit;
         end if;
      end loop;

      if not Found then
         To_Set.Last_Integer := To_Set.Last_Integer + 1;
         To_Set.Integers (To_Set.Last_Integer) := Elem;
      end if;
   end Add;

   function Union (Left, Right : Set) return Set is
      Result : Set := Left;
      Found  : Boolean;

   begin
      for ER in Right.Integers'first .. Right.Last_Integer loop
         Found := False;

         for EL in Left.Integers'first .. Left.Last_Integer loop
            if Left.Integers (EL) = Right.Integers (ER) then
               Found := True;

               exit;
            end if;
         end loop;

         if not Found then
            Result.Last_Integer := Result.Last_Integer + 1;
            Result.Integers (Result.Last_Integer) := Right.Integers (ER);
         end if;
      end loop;

      return Result;
   end Union;

   function Intersection (Left, Right : Set) return Set is
      Result : Set;
   begin
      for ER in Right.Integers'first .. Right.Last_Integer loop
         for EL in Left.Integers'first .. Left.Last_Integer loop
            if Left.Integers (EL) = Right.Integers (ER) then
               Result.Last_Integer := Result.Last_Integer + 1;
               Result.Integers (Result.Last_Integer) := Right.Integers (ER);

               exit;
            end if;
         end loop;
      end loop;

      return Result;
   end Intersection;

   function "=" (Left, Right : Set) return Boolean is
   begin
      if Left.Last_Integer /= Right.Last_Integer then
         return False;
      end if;

      for ER in Right.Integers'first .. Right.Last_Integer loop
         declare
            Found_Integer : Boolean := False;
         begin
            for EL in Left.Integers'first .. Left.Last_Integer loop
               if Left.Integers (EL) = Right.Integers (ER) then
                  Found_Integer := True;
                  exit;
               end if;
            end loop;

            if not Found_Integer then
               return False;
            end if;
         end;
      end loop;

      return True;
   end "=";

end CC51010_1;
