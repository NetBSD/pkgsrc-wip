 -- parent.child

     --=================================================================--

 
package body CA11019_0.CA11019_1 is    
          -- parent.child

   procedure Sequence (Ptr : Data_Ptr) is
   begin
      Ptr.Seq := Next_Avail_Seq_No;
      Next_Avail_Seq_No := Next_Avail_Seq_No + 1;
   end Sequence;

   ---------------------------------------------------------

   procedure Add (Datum : Data_Type; To : in out Data_Collection) is
      Ptr : Data_Ptr;
   begin
      if To.First = null then
         -- assign new record with data value to 
         -- to.next <- null;
         To.First := new Data_Elem'(Next  => null,
                                    Value => Datum,
                                    Seq   => 1);
         Sequence (To.First);
         To.Last := To.First;
      else
         -- chase to end of list
         Ptr := To.First;
         while Ptr.Next /= null loop
            Ptr := Ptr.Next;
         end loop;
         -- and add element there
         Ptr.Next := new Data_Elem'(Next  => null,
                                    Value => Datum,
                                    Seq   => 1);
         Sequence (Ptr.Next);
         To.Last := Ptr.Next;
      end if;

   end Add;

   ---------------------------------------------------------

   function  Op  (Data : Data_Collection) return Data_Type is
      -- for simplicity, just return the maximum of the data set
      Max : Data_Type := Data_Elem( Data.First.all ).Value; 
                              -- assuming non-empty collection
      Ptr : Data_Ptr  := Data.First;

   begin
      -- no error checking
      while Ptr.Next /= null loop
         if Data_Elem( Ptr.Next.all ).Value > Max then
            Max := Data_Elem( Ptr.Next.all ).Value;
         end if;
         Ptr := Ptr.Next;
      end loop;
      return Max;
   end Op;

end CA11019_0.CA11019_1;
