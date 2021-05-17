                                                    
     --==================================================================--

procedure B720001_8 is                                                -- OK.
               -- Non library packages may have bodies even if not required.
  package Non_Library_Sub_Pack8 is                 
    I : Integer;                                  
    F : Float;                                   
  end Non_Library_Sub_Pack8;

  package body Non_Library_Sub_Pack8 is
  begin
    I := 3;
    F := 4.0;
  end Non_Library_Sub_Pack8;
begin
  null;
end B720001_8;
