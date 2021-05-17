
-----------------------------------------------------------
package body B830001_20 is
   procedure Proc (X : NFormal_Tagged; Y : FormalA) is
      I : Integer;
   begin
      I := I + 8;
   end Proc;

   --------------------------------------------------------
   procedure Proc (X : NFormal_Tagged; Y : FormalB) is
      I : Integer;
   begin
      I := I + 9;
   end Proc;

end B830001_20;
