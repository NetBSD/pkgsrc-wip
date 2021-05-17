

     --==================================================================--


package BC70001_4 is                                   -- Non-generic package
   type Element_Type is record                         -- similar in structure
      Component : String (1 .. 6);                     -- to an instantiation
   end record;                                         -- of the template
                                                       -- package for a record
   Object : Element_Type;                              -- type.
end BC70001_4;
