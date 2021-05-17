

     --==================================================================--


with CC51002_0;  -- Root message type and operations.
generic          -- Message class function.
   type Msg_Block is new CC51002_0.Msg_Type with private;
function CC51002_1 (M : in Msg_Block) return Boolean;
