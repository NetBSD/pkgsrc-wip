

     --==================================================================--


package C460006_0.C460006_1 is

   type Parent_Type is new Root_Type with record
      C1 : Integer := 0;
   end record;

   procedure Inner_Proc (X : in out Parent_Type);
   procedure Outer_Proc (X : in out Parent_Type);

end C460006_0.C460006_1;
