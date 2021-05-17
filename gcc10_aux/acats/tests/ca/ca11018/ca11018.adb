
     --=================================================================--

with Report;

with CA11018_0.CA11018_2;   -- Public generic child package, copy words
                            -- to the message.
                            -- Implicit with parent package (CA11018_0).

procedure CA11018 is

   package Message_Pkg renames CA11018_0;

begin

   Report.Test ("CA11018", "Check that body of the parent package can " &
                "depend on one of its own public generic children");

-- Highlight the word "Alert" from the secret message.
 
       Designated_Subtest:
       declare
          The_Message : Message_Pkg.Designated_Msg;  -- Parent's private type.

          -- Instantiate the public child to copy words to the secret message.

          package Copy_Designated_Pkg is new CA11018_0.CA11018_2 
            (Message_Pkg.Designated_Msg);

       begin
          Copy_Designated_Pkg.Copy ("Alert Level 1 : Alert The Guard", 
                                To_The_Message => The_Message);

          Message_Pkg.Highlight_Designated ("Alert", The_Message);

          if not Message_Pkg.TC_Designated_Not_Zero and 
            Message_Pkg.TC_Designated_Success then
               Report.Failed ("Alert should have been highlighted");
          end if;

       end Designated_Subtest;

-- Highlight the word "Push The Alarm" from the top secret message.

       Particularly_Designated_Subtest:
       declare
          The_Message : Message_Pkg.Particularly_Designated_Msg ;  
                                         -- Parent's private type.

          -- Instantiate the public child to copy words to the top secret
          -- message.

          package Copy_Particularly_Designated_Pkg is new 
            CA11018_0.CA11018_2 (Message_Pkg.Particularly_Designated_Msg);

       begin
          Copy_Particularly_Designated_Pkg.Copy 
            ("Alert Level 10 : Alert The Guard and Push The Alarm", 
             The_Message);

          Message_Pkg.Highlight_Particularly_Designated 
            ("Push The Alarm", The_Message);

          if not Message_Pkg.TC_Particularly_Designated_Not_Zero and 
            Message_Pkg.TC_Particularly_Designated_Success then
               Report.Failed ("Key words should have been highlighted");
          end if;

       end Particularly_Designated_Subtest;

   Report.Result;

end CA11018;
