

     --==================================================================--


-- User first sets up support for mail messages by instantiating the
-- generic mail package for the root message type. An operation "Send" is
-- declared for the mail message type in the instance.
--
-- with CC30001_0;  -- Root message type.
-- with CC30001_1;  -- Generic "mail" package.
-- package Mail_Messages is new CC30001_1 (CC30001_0.Msg_Type);


     --==================================================================--


-- Next, the user sets up support for system messages by instantiating the
-- generic mail package with the system message type. An operation "Send"
-- is declared for the "system" mail message type in the instance. This
-- operation overrides the "Send" operation inherited from the system
-- message type actual (a situation the user may not have intended).

with CC30001_1;  -- Generic "mail" package.
with CC30001_2;  -- System message type and operations.
pragma Elaborate (CC30001_1);
package CC30001_3 is new CC30001_1 (CC30001_2.Sys_Message);
