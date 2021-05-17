

     --===================================================================--


package body C640001_0 is

   function Is_True (A : in Row_Type) return Boolean is
   begin
      for I in A'Range loop
         if A(I) /= True then                  -- Return true if all elements
            return False;                      -- of A are True.
         end if;
      end loop;
      return True;
   end Is_True;


   function Is_False (A : in Row_Type) return Boolean is
   begin
      return A = Row_Type'(others => False);   -- Return true if all elements
   end Is_False;                               -- of A are False.


   procedure Clear (A : in out Table) is
   begin
      for I in Row_Type'Range loop             -- This version of Clear sets
         A.Row1(I) := False;                   -- the elements of Row1 only
      end loop;                                -- to False.
   end Clear;


   procedure Reset (A : in out Table) is
   begin
      Clear (Table'Class(A));                  -- Redispatch to appropriate
      -- ... Other "reset" activities.         -- version of Clear.
   end Reset;


   procedure Clear (A : in out Table2) is
   begin
      for I in Row_Type'Range loop             -- This version of Clear sets
         A.Row1(I) := True;                    -- the elements of Row1 only
      end loop;                                -- to True.
   end Clear;


end C640001_0;
