

     --===================================================================--


with FA21A00;

with BA21A02_0;
package BA21A02_1 is new BA21A02_0 (Form_Priv   => FA21A00.My_Int,
                                    Form_PriExt => FA21A00.Tag,
                                    Int_Actual  => FA21A00.My_Int,
                                    FObj        => FA21A00.Three,
                                    Int_Type    => FA21A00.My_Int,
                                    IObj        => FA21A00.Three,
                                    Add         => FA21A00."+");      -- OK.
pragma Preelaborate (BA21A02_1);
