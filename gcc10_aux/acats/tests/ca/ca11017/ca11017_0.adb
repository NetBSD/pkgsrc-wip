
     --=================================================================--

--  After child is added to the subsystem, a maintainer decides
--  to take advantage of the new functionality and rewrites the
--  parent's body.

with CA11017_0.CA11017_1;

package body CA11017_0 is

   -- Calls functions from public child for a quick comparison of the
   -- input strings.  If their lengths are the same, do the replacement.

   procedure Replace (In_The_String   : in out String_Rec;
                      At_The_Position : in     positive;
                      With_The_String : in     String_Rec) is
      End_Position : natural := At_The_Position +
                                With_The_String.The_Length - 1;

   begin
      if not CA11017_0.CA11017_1.Equal_Length  -- Public child's operation.
        (With_The_String, In_The_String) then
           raise CA11017_0.CA11017_1.Position_Error;                 
                                               -- Public child's exception.
      else 
         In_The_String.The_Content (At_The_Position .. End_Position) :=
           With_The_String.The_Content (1 .. With_The_String.The_Length);
      end if;

   end Replace;

end CA11017_0;
