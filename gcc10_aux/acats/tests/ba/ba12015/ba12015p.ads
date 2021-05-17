
--  ---------------------------------------------------------------------------

package BA12015p is
   type T_Data is new Integer;
private
   Datum : T_Data := 999;
   type T_Hidden is access T_Data;
end BA12015p;
