
     --==================================================================--

package body B720001_2 is                                             -- ERROR:
                                        -- Package body completion not allowed.
  package body Generic_Non_Library_Sub_Pack2 is            
  begin                                                   
    F1 := 1.0;                                           
  end Generic_Non_Library_Sub_Pack2;
begin
  I := 3;
end B720001_2;
