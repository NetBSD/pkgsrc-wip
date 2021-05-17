

     --==================================================================--

procedure B810001_3 is

   My_Error : exception;

begin
   null;

exception

   when My_Error : My_Error =>                                        -- ERROR:
                                       -- Type mismatch: Homograph of My_Error.
      null;

end B810001_3;
