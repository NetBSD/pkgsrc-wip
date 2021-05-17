
--  ---------------------------------------------------------------------------

private package BA12015X.P is
   type Low_Level_Data is new Integer;
private
   Max_Value : constant Low_Level_Data := 999;
   type T_Hidden is access Low_Level_Data;
end BA12015X.P;
