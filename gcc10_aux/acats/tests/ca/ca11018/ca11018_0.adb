
     --=================================================================--

with CA11018_0.CA11018_1;   -- Public generic child.

pragma Elaborate (CA11018_0.CA11018_1);
package body CA11018_0 is

   ----------------------------------------------------
   -- Parent's body depends on public generic child. --
   ----------------------------------------------------

   -- Instantiate the public child for the secret message.

   package Designated_Pkg is new CA11018_0.CA11018_1 
     (Msg_Type => Designated_Msg, Count => Designated_Num);

   -- Instantiate the public child for the top secret message.

   package Particularly_Designated_Pkg is new CA11018_0.CA11018_1 
     (Particularly_Designated_Msg, Particularly_Designated_Num);

   -- End instantiations. -----------------------------

   
   function TC_Designated_Success return Boolean is
   -- Check to see if the function in the public generic child is called.

   begin
      return Designated_Pkg.TC_Function_Called;
   end TC_Designated_Success;
   --------------------------------------------------------------
   function TC_Particularly_Designated_Success return Boolean is
   -- Check to see if the function in the public generic child is called.

   begin
      return Particularly_Designated_Pkg.TC_Function_Called;
   end TC_Particularly_Designated_Success;
   --------------------------------------------------------------
   -- Calls functions from public child to search for a key word.  
   -- If the word appears more than once in each message, 
   -- highlight all of them.

   procedure Highlight_Designated (The_Word       : in     Message;
                                   In_The_Message : in out Designated_Msg) is

   -- Not a real highlight procedure.  Real application can use graphic
   -- device to highlight all occurrences of words.

   begin
      --------------------------------------------------------------
      -- Parent's body uses function from instantiation of public --
      -- generic child.                                           --
      --------------------------------------------------------------

      if Designated_Pkg.Find_Word          -- Child's operation.   
        (The_Word, In_The_Message) > 0 then

          -- Highlight all occurrences in lavender.

          TC_Designated_Not_Zero := true;       
      end if;

   end Highlight_Designated;
   --------------------------------------------------------------
   procedure Highlight_Particularly_Designated 
     (The_Word       : in     Message;
      In_The_Message : in out Particularly_Designated_Msg) is

   -- Not a real highlight procedure.  Real application can use graphic
   -- device to highlight all occurrences of words.

   begin
      --------------------------------------------------------------
      -- Parent's body uses function from instantiation of public --
      -- generic child.                                           --
      --------------------------------------------------------------

      if Particularly_Designated_Pkg.Find_Word     -- Child's operation.   
        (The_Word, In_The_Message) > 0 then

          -- Highlight all occurrences in chartreuse.
          -- Do other more secret stuff.

          TC_Particularly_Designated_Not_Zero := true;       
      end if;

   end Highlight_Particularly_Designated;

end CA11018_0;
