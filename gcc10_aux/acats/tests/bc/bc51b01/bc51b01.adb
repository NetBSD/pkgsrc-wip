

-- No body for BC51B01_1;


     --==================================================================--


with FC51B00;    -- Indefinite subtype definitions.
with BC51B01_0;  -- Generic with formal private type.
with BC51B01_1;  -- Generic with formal tagged private type.

procedure BC51B01 is

   package ArrStacks is new BC51B01_0 (FC51B00.Matrix);              -- ERROR:
                                  -- Actual subtype is an unconstrained array.

   generic
      with package Formal_Pack is new FC51B00.Signature (<>);
   package Sig_Packs is
      package UnkTagStacks is new BC51B01_0 (Formal_Pack.Vectors);   -- ERROR:
                                  -- Actual subtype has unknown discriminants.
   end Sig_Packs;

   package UnconRecStacks is new BC51B01_0 (FC51B00.Square);         -- ERROR:
                              -- Actual subtype has undefaulted discriminants.


   package UnconTagStacks is new BC51B01_0 (FC51B00.Square_Pair);    -- ERROR:
                              -- Actual subtype has undefaulted discriminants.

   package UnconTagCnt is new BC51B01_1 (FC51B00.Square_Pair);       -- ERROR:
                              -- Actual subtype has undefaulted discriminants.


   package ClassTagStacks is new BC51B01_0 (FC51B00.Vector'Class);   -- ERROR:
                                              -- Actual subtype is class-wide.

   package ClassTagCnt is new BC51B01_1 (FC51B00.Vector'Class);      -- ERROR:
                                              -- Actual subtype is class-wide.

begin
   null;
end BC51B01;
