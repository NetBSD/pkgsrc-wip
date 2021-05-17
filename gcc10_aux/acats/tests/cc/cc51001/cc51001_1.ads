

-- No body for CC51001_0.


     --==================================================================--


with CC51001_0;       -- Root type for message class.
package CC51001_1 is  -- Extensions to message class.

   subtype Source_Length is Natural range 0 .. 10;

   type From_Msg_Type (SLen : Source_Length) is            -- Direct derivative
     new CC51001_0.Msg_Type with record                    -- of root type
      From : String (1 .. SLen);                           -- (indefinite).
   end record;

   subtype Dest_Length is Natural range 0 .. 10;



   type To_From_Msg_Type (DLen : Dest_Length) is           -- Indirect
     new From_Msg_Type (SLen => 10) with record            -- derivative of
      To : String (1 .. DLen);                             -- root type
   end record;                                             -- (indefinite).

end CC51001_1;
