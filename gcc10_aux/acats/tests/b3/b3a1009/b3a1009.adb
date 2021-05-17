

with System;
package body B3A1009 is

   procedure Test1 (P : access B3A1009_A.An_Array) is
      I : Integer;
   begin
      I := P.all(1);                                       -- ERROR:
      I := P.all'Size;                                     -- ERROR:
      I := P(5);                                           -- ERROR:
      I := P(1..5)(I);                                     -- ERROR:
      I := P.all'Size;                                     -- ERROR:
      I := P.all'Alignment;                                -- ERROR:
   end Test1;

   procedure Test2 (P : access B3A1009_A.A_Rec) is
      Q : Acc_A_Rec;
   begin
      loop
         exit when P /= null;                              -- OK.
         exit when P.all'Size /= 10;                       -- ERROR:
         exit when O1.all'Alignment /= 1;                  -- ERROR:
         exit when O1.all.C /= 'G';                        -- ERROR:
         exit when P.C /= 'B';                             -- ERROR:
      end loop;
      Q := Acc_A_Rec(P);                                   -- OK.
      Q := P.all'Access;                                   -- ERROR:
   end Test2;

   procedure Test3 (P : access B3A1009_A.A_Rec_w_Disc) is
   begin
      loop
         exit when P /= O2;                                -- OK.
         exit when P.all'Size /= 5;                        -- ERROR:
         exit when P.all.D;                                -- ERROR:
         exit when P.D;                                    -- ERROR:
         exit when O2.all'Alignment /= 2;                  -- ERROR:
         exit when P.all.N /= 5;                           -- ERROR:
         exit when O2.N /= 7;                              -- ERROR:
      end loop;
   end Test3;

   procedure Test4 (P : access B3A1009_A.A_Tagged_w_Disc) is
      A : System.Address;
   begin
      loop
         exit when P.all'Size /= 12;                       -- ERROR:
         exit when P.all.D;                                -- ERROR:
         exit when P.D;                                    -- ERROR:
         exit when O3.all'Alignment /= 2;                  -- ERROR:
         exit when P.all.F /= 2.5;                         -- ERROR:
         exit when O3.F /= 2.25;                           -- ERROR:
      end loop;
      A := P'Address;                                      -- OK.
      A := P.all'Address;                                  -- ERROR:
   end Test4;

   procedure Test5 (P : access B3A1009_A.An_Interf'Class) is
   begin
      loop
         exit when P /= null;                              -- OK.
         exit when P.all'Size /= 12;                       -- ERROR:
         exit when O4.all'Alignment /= 2;                  -- ERROR:
      end loop;
   end Test5;


   procedure Test10 (Obj : B3A1009_A.A_Tagged) is
   begin
      loop
         exit when Obj'Size /= 52;                         -- ERROR:
         exit when Obj'Alignment = 4;                      -- ERROR:
         exit when Obj.D;                                  -- ERROR:
         exit when Obj.W /= 'W';                           -- ERROR:
      end loop;
   end Test10;

   procedure Test11 (Obj : B3A1009_A.A_Tagged_w_Disc) is
      A : System.Address;
   begin
      loop
         exit when Obj'Size /= 52;                         -- ERROR:
         exit when Obj.D;                                  -- ERROR:
         exit when Obj.F /= 5.5;                           -- ERROR:
      end loop;
      A := Obj'Address;                                    -- ERROR:
   end Test11;

   procedure Test12 (Obj : B3A1009_A.A_Priv_Tagged_w_Disc) is
   begin
      loop
         exit when Obj'Size /= 12;                         -- ERROR:
         exit when Obj.D;                                  -- ERROR:
      end loop;
      if O3 /= null then
         Test12 (Obj);                                     -- OK.
         O3 := Obj'Unchecked_Access;                       -- ERROR:
      end if;
   end Test12;

   procedure Test13 (Obj : B3A1009_A.An_Interf'Class) is
   begin
      loop
         exit when Obj'Size /= 12;                         -- ERROR:
         exit when Obj'Alignment /= 2;                     -- ERROR:
      end loop;
      if O4 /= null then
         Test13 (Obj);                                     -- OK.
         O4 := Obj'Unchecked_Access;                       -- ERROR:
      end if;
   end Test13;

end B3A1009;
