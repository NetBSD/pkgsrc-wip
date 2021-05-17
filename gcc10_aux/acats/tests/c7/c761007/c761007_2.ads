 
---------------------------------------------------------------- C761007_2
with C761007_1;
package C761007_2 is

  protected type Prot_W_Fin_Obj is
    procedure Set_Effects( Container, Filling: Character );
  private
    The_Data_Under_Test : C761007_1.Container;
    -- finalization for this will occur when the Prot_W_Fin_Obj object
    --  "goes out of existence" for whatever reason.
  end Prot_W_Fin_Obj;

end C761007_2;
