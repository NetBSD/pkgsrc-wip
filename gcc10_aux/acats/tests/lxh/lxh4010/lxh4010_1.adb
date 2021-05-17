
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body LXH4010_1 is

  I : aliased Integer := 4200;

  OKP : Int_P := I'Access;                                        -- OK

 procedure Proc is
  begin
    if OKP = null then
      OKP := new Integer;
    end if;
  end Proc;

  OKPP : Proc_P := Proc'Access;                                   -- OK

begin

  IP:= I'Access;                                                  -- OK

end LXH4010_1;
