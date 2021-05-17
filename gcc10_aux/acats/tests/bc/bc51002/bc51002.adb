

     --==================================================================--


with BC51002_0;  -- Type definitions.
with BC51002_1;  -- Formal package template.
with BC51002_2;  -- Array formal types.
with BC51002_3;  -- Record formal types (1).
with BC51002_4;  -- Record formal types (2).
with BC51002_5;  -- Tagged formal types.

procedure BC51002 is

   package Arrays is new BC51002_2
     (BC51002_0.Matrix);                                              -- ERROR:
                                                              -- Unconstrained.

   package Records is new BC51002_3
     (BC51002_0.Any_Square);                                          -- ERROR:
                                                              -- Unconstrained.

   generic
      with package Formal_Package is new BC51002_1 (<>);
   package Sig_Packs is

      package Records is new BC51002_4
         (Formal_Package.Squares);                                    -- ERROR:
                                                      -- Unknown discriminants.
   end Sig_Packs;


   package Taggeds is new BC51002_5
     (BC51002_0.Vector_Pair'Class);                                   -- ERROR:
                                                                 -- Class-wide.
begin
   null;
end BC51002;
