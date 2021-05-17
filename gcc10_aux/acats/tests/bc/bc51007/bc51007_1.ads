
-- No body for BC51007_0.


     --==================================================================--


with BC51007_0;  -- Type definitions.
generic
   type Message is new BC51007_0.Msg_Type;                -- Formal derived
package BC51007_1 is                                      -- record type.

   Object : Message;  

   type New_Message is new Message(18);

end BC51007_1;
