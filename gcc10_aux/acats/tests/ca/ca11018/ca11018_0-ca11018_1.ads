
     --=================================================================--


-- Public generic child package of message display application.  Imagine that 
-- messages of one security level are associated with a type derived from 
-- integer.  For overall system security, messages of a different security
-- level are associated with a different type derived from integer.  By 
-- instantiating this package for each security level, the results of Count 
-- applied to one kind of message cannot inadvertently be compared with the 
-- results applied to a different kind.

generic
   type Msg_Type is new Message_Rec with private; 
                                              -- Derived from parent's type.
   type Count is range <>;

package CA11018_0.CA11018_1 is    

   TC_Function_Called : Boolean := false;

   function Find_Word (Wrd : in Message;
                       Msg : in Msg_Type) return Count;

end CA11018_0.CA11018_1;
