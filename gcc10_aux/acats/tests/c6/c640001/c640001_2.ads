

     --===================================================================--


-- This unit represents a support package for table-driven processing of
-- data objects. Process_Operand performs a set of operations are performed
-- sequentially on a single operand. Note that parameters are provided to
-- specify which subset of operations in the operations table are to be
-- performed (ordinarily these might be omitted, but the test requires that
-- each operation be called individually for a single operand).

generic
   type Tag is tagged private;
package C640001_2 is

   type Proc_Ptr is access procedure (P: in out Tag);

   type Op_List is private;

   procedure Add_Op (Op   : in     Proc_Ptr;                -- Add operation to
                     List : in out Op_List);                -- to list of ops.

   procedure Process_Operand (Operand  : in out Tag;        -- Execute a subset
                              List     : in     Op_List;    -- of a list of
                              First_Op : in     Positive;   -- operations using
                              Last_Op  : in     Positive);  -- a given operand.

   -- ...Other operations.

private
   type Op_Array is array (1 .. 3) of Proc_Ptr;

   type Op_List is record
      Top : Natural := 0;
      Ops : Op_Array;
   end record;
end C640001_2;
