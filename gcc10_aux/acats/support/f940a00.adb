 -- Interlock_Foundation

--===================================--

package body F940A00 is
          -- Interlock_Foundation

  protected body Interlock_Type is

    entry Post when true is
    begin
      Int_Count := Int_Count + 1;
    end Post;

    entry Consume when Int_Count > 0 is
    begin
      Int_Count := Int_Count - 1;
    end Consume;

  end Interlock_Type;


  protected body Counter is

    procedure Increment is
      begin
        Count := Count + 1;
      end Increment;

    procedure Decrement is
      begin
        Count := Count - 1;
      end Decrement;

    function Number return Integer is 
      begin
        return Count;
      end Number;

  end Counter;

end F940A00;
 -- Interlock_Foundation
