 -- parent

    --=================================================================--

-- This generic package provides parameterized code that has been
-- written once and will be used three times to implement the services
-- of the parent package.

private
generic   
   type Data_Type is range <>;

package CA11019_0.CA11019_1 is    
     -- parent.child

   type Data_Elem is new Data_Record with
     record
        Value : Data_Type;
     end record;

   Next_Avail_Seq_No : Sequence_Number := 1;

   procedure Sequence (Ptr : Data_Ptr);
    -- the child must be private for this procedure to know details of
    -- the implementation of data collections

   procedure Add (Datum : Data_Type; To : in out Data_Collection);

   function  Op  (Data : Data_Collection) return Data_Type;
    -- op models a complicated operation that whose code can be
    -- used for various data types


end CA11019_0.CA11019_1;
