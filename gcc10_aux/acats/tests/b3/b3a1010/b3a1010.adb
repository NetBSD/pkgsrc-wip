

with System;
package body B3A1010 is

   procedure Test1 (P : access An_Inc) is
      Q : An_Acc_Inc;
      A : System.Address;
   begin
      if P /= null then                                      -- OK.
         null;
      elsif P.all'Size /= 10 then                            -- ERROR:
         null;
      elsif P.all'Alignment /= 1 then                        -- ERROR:
         null;
      end if;
      Q := An_Acc_Inc(P);                                    -- OK.
      Q := P.all'Access;                                     -- ERROR:
      A := P.all'Address;                                    -- ERROR:
   end Test1;

   procedure Test2 (P : access A_Tagged_Inc) is
      Q : An_Acc_Tagged_Inc;
      A : System.Address;
   begin
      if P /= null then                                      -- OK.
         null;
      elsif P.all'Size /= 20 then                            -- ERROR:
         null;
      elsif P.all'Alignment /= 1 then                        -- ERROR:
         null;
      elsif Q.all'Alignment = 4 then                         -- ERROR:
         null;
      end if;
      Q := An_Acc_Tagged_Inc(P);                             -- OK.
      Q := P.all'Access;                                     -- ERROR:
      A := Q.all'Address;                                    -- ERROR:
   end Test2;

   procedure Test3 (Obj : A_Tagged_Inc) is
      Q : An_Acc_Tagged_Inc;
      A : System.Address;
   begin
      if Obj'Size /= 12 then                                 -- ERROR:
         null;
      elsif Obj'Alignment /= 2 then                          -- ERROR:
         null;
      end if;
      Q := Obj'Unchecked_Access;                             -- ERROR:
      A := Q.all'Address;                                    -- ERROR:
   end Test3;

end B3A1010;
