
with Report;
with CC60001_1; use CC60001_1;
with CC60001_2;
with TcTouch;
procedure CC60001 is

begin

   Report.Test ("CC60001",
                 "Check that calls on formal abstract subprograms dispatch " &
                 "as expected");

   -- Try various objects descended from Toggle:
   declare
      My_Auto_Dim : Auto_Dimmer := Create; ------------------------------ 3
      My_Duo : Duo := Create;              ------------------------------ 4
      My_Toggle : Toggle := Create;        ------------------------------ 1
      My_Class : Toggle'Class := TC_CW_TI ('2'); ------------------------ W

      package Inst is new CC60001_2 (Toggle); -- Subprograms are found via <>

   begin
      if not Is_On (My_Auto_Dim) then ----------------------------------- B
         Report.Failed ("Wrong initial state (1A)");
      end if;
      if Is_On (My_Duo) then -------------------------------------------- S
         Report.Failed ("Wrong initial state (1B)");
      end if;
      if not Is_On (My_Toggle) then ------------------------------------- B
         Report.Failed ("Wrong initial state (1C)");
      end if;
      if Is_On (My_Class) then ------------------------------------------ S
         Report.Failed ("Wrong initial state (1D)");
      end if;

      TcTouch.Validate (Expected => "341WBSBS",
                        Message => "Wrong routines initially called (1E)");

      Inst.Force_On (My_Auto_Dim); -------------------------------------- B

      Inst.Force_Off (My_Toggle); -------------------------------------- BA

      Inst.Force_On (My_Duo); ------------------------------------------ SA

      Inst.Force_Off (My_Class); ---------------------------------------- S

      if not Is_On (My_Auto_Dim) then ----------------------------------- B
         Report.Failed ("Wrong state (1F)");
      end if;
      if not Is_On (My_Duo) then ---------------------------------------- S
         Report.Failed ("Wrong state (1G)");
      end if;
      if Is_On (My_Toggle) then ----------------------------------------- B
         Report.Failed ("Wrong state (1H)");
      end if;
      if Is_On (My_Class) then ------------------------------------------ S
         Report.Failed ("Wrong state (1I)");
      end if;

      TcTouch.Validate (Expected => "BBASASBSBS",
                        Message => "Wrong routines called (1J)");

      Flip_2 (My_Duo); -------------------------------------------------- R

      Inst.Force_On (My_Duo); ------------------------------------------ SA

      if not Is_On (My_Duo) then ---------------------------------------- S
         Report.Failed ("Wrong state (1K)");
      end if;

      if not Auto (My_Auto_Dim) then ------------------------------------ J
         Report.Failed ("Wrong state (1L)");
      end if;

      Inst.Force_Off (My_Auto_Dim); ----------------------------------- BKB
         -- Changes Auto, but doesn't turn it off.

      if Auto (My_Auto_Dim) then ---------------------------------------- J
         Report.Failed ("Wrong state (1M)");
      end if;

      if not Is_On (My_Auto_Dim) then ----------------------------------- B
         Report.Failed ("Wrong state (1N)");
      end if;

      TcTouch.Validate (Expected => "RSASJBKBJB",
                        Message => "Wrong routines called (1O)");

   end;


   -- Try a type unrelated to Toggle:
   declare
      package Inner is
         type Clicker is tagged record
            Is_Set : Boolean;
         end record;

         function Create return Clicker;
         procedure Invert  (It : in out Clicker);
         function Set    (It : Clicker) return Boolean;
      end Inner;
      use Inner;

      package Inst2 is new CC60001_2 (Clicker, Flip => Invert, Is_On => Set);

      package body Inner is
         function Create return Clicker is
         begin
            TCTouch.Touch ('9');  ---------------------------------------- 9
            return Clicker'( Is_Set => True);
         end Create;

         procedure Invert  (It : in out Clicker) is
         begin
            TCTouch.Touch ('a');  ---------------------------------------- a
            It.Is_Set := not It.Is_Set;
         end Invert;

         function Set    (It : Clicker) return Boolean is
         begin
            TCTouch.Touch ('b');  ---------------------------------------- b
            return It.Is_Set;
         end Set;

      end Inner;

      My_Clicker : Clicker := Create; ------------------------------------ 9

   begin
      Inst2.Force_Off (My_Clicker); ------------------------------------- ba

      Inst2.Force_Off (My_Clicker); -------------------------------------- b

      if My_Clicker.Is_Set then
         Report.Failed ("Wrong state (2A)");
      end if;

      Inst2.Force_On (My_Clicker); -------------------------------------- ba

      if not My_Clicker.Is_Set then
         Report.Failed ("Wrong state (2B)");
      end if;

      TcTouch.Validate (Expected => "9babba",
                        Message => "Wrong routines called (2C)");


   end;

   Report.Result;

end CC60001;
