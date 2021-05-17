
package body FD72A00 is

    function Address_To_Hex( Adder: System.Address ) return String is
      S : String(1..64)
       := "uninitializedDEFuninitializedDEFuninitializedDEFuninitializedDEF";
      DeBlank : Positive := S'First;
    begin
      Num_IO.Put( S, Number( System.Storage_Elements.To_Integer( Adder ) ),
                  Base => 16 );
      while S(DeBlank) = ' ' loop
        DeBlank := DeBlank +1;
      end loop;
      return S(DeBlank..S'Last);
    end Address_To_Hex;

    function Hex_To_Address( Hex: access String ) return System.Address is
      The_Number : Number;
      Tail       : Natural;
    begin
      Num_IO.Get( Hex.all, The_Number, Tail );
      return System.Storage_Elements.To_Address(
                      System.Storage_Elements.Integer_Address( The_Number ) );
    end Hex_To_Address;

end FD72A00;
