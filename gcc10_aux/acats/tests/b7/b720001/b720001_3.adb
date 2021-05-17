
     --==================================================================--

package body B720001_3 is                                             -- ERROR:
                                        -- Package body completion not allowed.
  I2 : Integer;                                         
  F2 : Float;                                          
                                                      
  package body Non_Library_Sub_Pack3 is
  begin
    I1 := 4;
  end Non_Library_Sub_Pack3;
end B720001_3;      
