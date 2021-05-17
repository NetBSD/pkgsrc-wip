
with C940017_A;
package C940017_B is

   Empty_Error, Full_Error : exception;

   protected type Single_w_Exceptions is new C940017_A.Queue_Interface with
      overriding
      procedure Enqueue (Item : in Integer);
      overriding
      procedure Dequeue (Item : out Integer);
      overriding
      function Item_Count return Natural;
   private
      In_Use : Boolean := False;
      Stored_Item : Integer;
   end Single_w_Exceptions;

   type Item_Array is array (1..4) of Integer;

   protected type Quad_w_Blocking is new C940017_A.Queue_Interface with
      overriding
      entry Enqueue (Item : in Integer);
      overriding
      entry Dequeue (Item : out Integer);
      overriding
      function Item_Count return Natural;
   private
      Count : Natural := 0;
      Stored : Item_Array;
   end Quad_w_Blocking;

end C940017_B;
