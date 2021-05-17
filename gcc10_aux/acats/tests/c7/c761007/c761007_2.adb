 
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body C761007_2 is

  protected body Prot_W_Fin_Obj is
    procedure Set_Effects( Container, Filling: Character ) is
    begin
      The_Data_Under_Test.Effect := Container;           -- A, etc.
      The_Data_Under_Test.Content.Effect := Filling;     -- B, etc.
    end Set_Effects;
  end Prot_W_Fin_Obj;

end C761007_2;
