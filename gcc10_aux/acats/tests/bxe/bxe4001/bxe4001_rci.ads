
----------------------------------------------------------------------------

with BXE4001_Pure;
package BXE4001_RCI is
  pragma Remote_Call_Interface;
   
  procedure No_Parameters; 
  pragma Asynchronous(No_Parameters);                              -- OK.

  type No_Parm_Ptr is access procedure;
  pragma Asynchronous (No_Parm_Ptr);                               -- OK.

  type In_Parm_Ptr is access procedure (X : in Integer);          
  pragma Asynchronous (In_Parm_Ptr);                               -- OK. 

  procedure Has_Out_Parameters (P : out Integer); 
  pragma Asynchronous(Has_Out_Parameters);                         -- ERROR:
              -- The parameters for a procedure named in pragma Asynchronous
              -- must be of mode in.
  
  type Out_Parm_Ptr is access procedure (P : out Integer); 
  pragma Asynchronous(Out_Parm_Ptr);                               -- ERROR:
              -- The parameters for a procedure named in pragma Asynchronous
              -- must be of mode in.
  
  procedure Has_In_Out_Parameter  (N : in     Integer;
                                   P : in out Integer;               
                                   Q : in     Integer);
  pragma Asynchronous (Has_In_Out_Parameter);                      -- ERROR:
              -- The parameters for a procedure named in pragma Asynchronous
              -- must be of mode in.

  type InOut_Parm_Ptr is access
     procedure (N : in     Integer;
                P : in out Integer;               
                Q : in     Integer);
  pragma Asynchronous (InOut_Parm_Ptr);                            -- ERROR:
              -- The parameters for a procedure named in pragma Asynchronous
              -- must be of mode in.

  function Simple_Function (X : Integer) return Integer;
  pragma Asynchronous (Simple_Function);                           -- ERROR:
                         -- functions cannot be named in pragma Asynchronous
         
  type Func_Ptr is access function (X : Integer) return Integer;
  pragma Asynchronous (Func_Ptr);                                  -- ERROR:
                         -- functions cannot be named in pragma Asynchronous
         
end BXE4001_RCI;
