

     --===================================================================--


package BA21003_5.BA21003_6 is                                        -- ERROR:
                      -- Unit depends semantically on non-preelaborated parent.

   pragma Preelaborate;


   type DT is new T with record
      A: String (1 .. 3) := "Yes";
   end record;

   procedure Op1 (P: in out DT);

end BA21003_5.BA21003_6;
