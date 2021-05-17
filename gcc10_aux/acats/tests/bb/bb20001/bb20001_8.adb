
     --==================================================================--

with BB20001_1;
with BB20001_2;
with BB20001_7;

procedure BB20001_8 is                                   

   type Enum is (On, Off);

   package IPck1  is new BB20001_1 (Enum);

   package IPck2  is new BB20001_2 (IPck1);  

   package IPck8  is new BB20001_7 (IPck2);  

begin
   null;

exception
   when IPck8.RN_FPck7.RN_FPck2.RN_Common_Exception_1 => null;        -- OK.

   when IPck8.Exception_7                             => null;        -- OK.

   when IPck8.RN_FPck7.Exception_2                    => null;        -- OK.

   when IPck8.RN_FPck7.RN_FP_Exception_2              => null;        -- OK.

end BB20001_8;
