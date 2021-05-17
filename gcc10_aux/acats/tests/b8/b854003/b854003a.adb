
package body B854003A is
   procedure Munge_1 (Val : in out Integer) is
   begin
      null;
   end Munge_1;

   procedure Munge_2 (Val : in out Natural) is
   begin
      null;
   end Munge_2;

   procedure Munge_3 (Val : in out Dyn_Positive) is
   begin
      null;
   end Munge_3;

   procedure Munge_4 (Val : in Integer) is
   begin
      null;
   end Munge_4;

   procedure Munge_5 (Val : in out New_Positive) is
   begin
      null;
   end Munge_5;

   procedure Munge_6 (Val : in out Positive; Foo : in Boolean := True) is
   begin
      null;
   end Munge_6;

   function Double_1 (Val : in Integer) return Integer is
   begin
      return Val * 2;
   end Double_1;

   function Double_2 (Val : in Integer) return Natural is
   begin
      return Val * 2;
   end Double_2;

   function Double_3 (Val : in Integer) return Dyn_Positive is
   begin
      return Val * 2;
   end Double_3;

   function Count (Obj : in T) return Natural is
   begin
      return 0;
   end Count;

   procedure Sink (Obj : in T) is
   begin
      null;
   end Sink;

end B854003A;
