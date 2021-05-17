
package body C340001_0 is

   function "=" (L, R : in DB_Record) return Boolean is
   -- Key is ignored in determining equality of records
   begin
      return L.Data = R.Data;
   end "=";
   
end C340001_0;
