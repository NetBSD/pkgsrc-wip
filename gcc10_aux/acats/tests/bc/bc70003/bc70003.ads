

     --==================================================================--


with BC70003_0;  -- Generic package.
with BC70003_1;  -- Non-generic package.
with BC70003_2;  -- Generic subprogram.
with BC70003_3;  -- Instance of generic package.

generic                                              
   with package Valid_Declaration   is new BC70003_0 (<>);            -- OK.


   with package Package_Not_Generic is new BC70003_1 (<>);            -- ERROR:
                                          -- Template is not a generic package.

   with package Generic_Not_Package is new BC70003_2 (<>);            -- ERROR:
                                          -- Template is not a generic package.

   with package Formal_Package      is new Valid_Declaration (<>);    -- ERROR:
                                          -- Template is not a generic package.

   with package Instance            is new BC70003_3 (<>);            -- ERROR:
                                          -- Template is not a generic package.

package BC70003 is
   An_Element : Valid_Declaration.Element_Type;
end BC70003;
