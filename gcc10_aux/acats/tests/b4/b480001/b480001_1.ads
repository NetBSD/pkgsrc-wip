

     --==================================================================--


package B480001_1 is

   type Gender_Kind is (M, F, Unknown);
   subtype Gender_Subtype is Gender_Kind range M .. F;

   type Person (G : Gender_Subtype := F) is record
      C : Integer;
   end record;

   type Direct_Access_Person          is access Person;
   type Single_Indirect_Access_Person is access Direct_Access_Person;

end B480001_1;
