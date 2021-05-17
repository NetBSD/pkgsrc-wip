

     --==================================================================--

with Report;
package body C460004_0 is

   procedure Proc (X : in out Tag_Type) is
   begin
      X.C1 := 25;
   end Proc;

   -----------------------------------------
   procedure Proc (X : in out DTag_Type) is
   begin
      Proc ( Tag_Type(X) );
      X.C2 := "Earth";
   end Proc;

   -----------------------------------------
   procedure Proc (X : in out DDTag_Type) is
   begin
      Proc ( DTag_Type(X) );
      X.C3 := "Orbit";
   end Proc;

   -----------------------------------------
   procedure NewProc (X : in DDTag_Type) is
      Y : DDTag_Type := X;
   begin
      Proc (Y);
   exception
      when others => 
         Report.Failed ("Unexpected exception in NewProc");
   end NewProc;

   -----------------------------------------
   function CWFunc (X : Tag_Type'Class) return Tag_Type'Class is
      Y : Tag_Type'Class := X;
   begin
      Proc (Y);
      return Y;
   end CWFunc;

end C460004_0;
