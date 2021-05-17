

     --==================================================================--


with B480001_0;
with B480001_1;

procedure B480001 is
begin

   declare
      Index_Constraint : B480001_0.Single_Indirect_Access_Array;
   begin
      Index_Constraint := new B480001_0.Direct_Access_Array(1 .. 10); -- ERROR:
                             -- Explicit constraint illegal for access subtype.
   end;


   declare
      use B480001_1;  -- To make enumeration value visible.
      Discrim_Constraint : B480001_1.Single_Indirect_Access_Person;
   begin
      Discrim_Constraint := new B480001_1.Direct_Access_Person(F);    -- ERROR:
                             -- Explicit constraint illegal for access subtype.
   end;


   declare
      use B480001_1;  -- To make enumeration value visible.

      Discrim_Constraint : B480001_1.Single_Indirect_Access_Person :=
                           new B480001_1.Direct_Access_Person(M);     -- ERROR:
                             -- Explicit constraint illegal for access subtype.

      procedure Proc (InParm : in B480001_0.Single_Indirect_Access_Array) is
      begin
         null;
      end Proc;

   begin
      Proc (InParm => new B480001_0.Direct_Access_Array(3..5));       -- ERROR:
                             -- Explicit constraint illegal for access subtype.
   end;

end B480001;
