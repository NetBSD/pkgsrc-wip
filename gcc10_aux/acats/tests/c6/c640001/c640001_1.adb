

     --===================================================================--


package body C640001_1 is

   procedure Clear (T : in out C640001_0.Table) is
   begin
      for I in C640001_0.Row_Type'Range loop   -- This version of Clear sets
         T.Row2(I) := True;                    -- the elements of Row2 only
      end loop;                                -- to True.
   end Clear;

end C640001_1;
