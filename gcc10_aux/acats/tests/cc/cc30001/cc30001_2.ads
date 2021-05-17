

     --==================================================================--


with CC30001_0;       -- Root message type.
package CC30001_2 is  -- System message type and operations.

   type Signal_Type is (Note, Warning, Error);

   type Sys_Message is new CC30001_0.Msg_Type with record   -- Derived from
      Signal : Signal_Type := Warning;                      -- root type.
   end record;

   procedure Send (Item : in out Sys_Message); -- For this test, this version
                                               -- of Send should never be
   -- ... Other operations.                    -- called (it will have been
                                               -- overridden).
end CC30001_2;
