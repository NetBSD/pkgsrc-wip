

     --==================================================================--


package C460006_0.C460006_1.C460006_2 is

   type Child_Type is new Parent_Type with record
      C2 : String(1 .. 5) := "-----";
   end record;

   procedure Inner_Proc (X : in out Child_Type);
   procedure Outer_Proc (X : in out Child_Type);

end C460006_0.C460006_1.C460006_2;
