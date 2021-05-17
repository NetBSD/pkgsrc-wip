

     --==================================================================--


with BC51007_0;  -- Type definitions.
generic
   type Message is new BC51007_0.Ext_Msg with private;    -- Formal derived
package BC51007_2 is                                      -- tagged type.

   subtype New_Message is Message;

end BC51007_2;
