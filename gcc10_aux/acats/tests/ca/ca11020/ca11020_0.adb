
     --==================================================================--

with CA11020_0.CA11020_1;    -- Public generic child package.

package body CA11020_0 is

   ----------------------------------------------------
   -- Parent's body depends on public generic child. --
   ----------------------------------------------------

   -- Instantiate the public child.

   package MS is new CA11020_1;  

   function Bag_Image (B : Bag) return string is

      Buffer : String (1 .. 10_000);
      Last   : Integer := 0;

      -----------------------------------------------------

      -- Will be called by the iterator.

      procedure Append_Image (E : in Element) is  
         Im : constant String := Image (E);

      begin  -- Append_Image
         if Last /= 0 then        -- Insert a comma.
            Last := Last + 1;
            Buffer (Last) := ',';
         end if;

         Buffer (Last + 1 .. Last + Im'Length) := Im;
         Last := Last + Im'Length;

      end Append_Image;

      -----------------------------------------------------

      -- Instantiate procedure Iterate as a child of instance MS.

      procedure Append_All is new MS.Iterate (Use_Element => Append_Image);

   begin  -- Bag_Image

      Append_All (B);

      return Buffer (1 .. Last);

   end Bag_Image;

           -----------------------------------------------------

   procedure Add (E : in Element; To_The_Bag : in out Bag) is

      -- Not a real bag addition.

      Index : Bag := To_The_Bag;

   begin
      -- ... Error-checking code omitted for brevity.
    
      if Index = null then
         To_The_Bag := new Node_Type' (The_Element => E,
                                       Next        => null);
      else
         -- Goto the end of the list.

         while Index.Next /= null loop
            Index := Index.Next;
         end loop;

         -- Add element to the end of the list.

         Index.Next := new Node_Type' (The_Element => E,
                                       Next        => null);
      end if;

   end Add;

end CA11020_0;
