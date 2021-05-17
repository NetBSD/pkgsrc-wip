
--==================================================================--

with C730003_0; use C730003_0;
package C730003_1 is

   subtype Graphic_Representation is String (1 .. 2);

   type Graphic_Card is new Disp_Card with record
      View : Graphic_Representation;                                    -- (B)
                                          -- "Duplicate" component field name.
   end record;

end C730003_1;
