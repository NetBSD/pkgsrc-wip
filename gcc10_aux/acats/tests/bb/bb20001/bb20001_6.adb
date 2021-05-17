
     --==================================================================--

with BB20001_1;
with BB20001_5;

procedure BB20001_6 is                                   

   type Enum_Type is (One, Two, Three);

   package IPck   is new BB20001_1 (Enum_Type);

   package IPck6  is new BB20001_5 (IPck);  

begin
   null;

exception
   when IPck6.RN_FPck5.RN_Common_Exception_1 => null;                 -- OK.

   when IPck6.RN_FPck5.FP_Exception_1        => null;                 -- OK.

end BB20001_6;
