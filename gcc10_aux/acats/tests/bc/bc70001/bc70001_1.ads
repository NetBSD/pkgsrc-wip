

     --==================================================================--


with BC70001_0;
generic                                                -- Generic package which
   with package Formal_Package is new BC70001_0 (<>);  -- declares a formal
package BC70001_1 is                                   -- package.
   An_Element : Formal_Package.Element_Type;
end BC70001_1;
