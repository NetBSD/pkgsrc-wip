
with System;
package body CXD8002_1 is
      Finished : Boolean := False;
      pragma Volatile (Finished);

      type Int is range 0 .. System.Max_Int;
      Rendezvous_Count : Int := 0;
      Overflow : Boolean := False;

      task Background_Passive is
         pragma Priority (System.Priority'First + 1);
         entry Available_Entry;
      end  Background_Passive;

      task body Background_Passive is
      begin
         while not Finished loop
          if Available_Entry'Count > 0 then
            accept Available_Entry do
               Rendezvous_Count := Rendezvous_Count + 1;
               if Rendezvous_Count = Int'Last then
                 Overflow := True;
                 Rendezvous_Count := 0;
               end if;
            end Available_Entry;
          end if;
         end loop;
      end Background_Passive;

      task Background_Active is
        pragma Priority (System.Priority'First + 2);
      end Background_Active;

      task body Background_Active is
      begin
        while not Finished loop
           Background_Passive.Available_Entry;
        end loop;
      end Background_Active;


      procedure Stop is
      begin
        Finished := True;
      end Stop;
end CXD8002_1;
