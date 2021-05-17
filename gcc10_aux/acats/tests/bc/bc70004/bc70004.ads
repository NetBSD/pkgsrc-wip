

     --==================================================================--


with BC70004_0;  -- Generic package.
with BC70004_1;  -- Non-generic package.
with BC70004_2;  -- Generic subprogram.
with BC70004_3;  -- Instance of generic package.

generic                                              
   with package Valid_Declaration   is new BC70004_0 (<>);            -- OK.


   with package Package_Not_Generic is new BC70004_1 (<>);            -- ERROR:
                                          -- Template is not a generic package.

   with package Generic_Not_Package is new BC70004_2 (<>);            -- ERROR:
                                          -- Template is not a generic package.

   with package Formal_Package      is new Valid_Declaration (<>);    -- ERROR:
                                          -- Template is not a generic package.

   with package Instance            is new BC70004_3 (<>);            -- ERROR:
                                          -- Template is not a generic package.

procedure BC70004;
