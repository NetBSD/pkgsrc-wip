
----------------------------------------------------------------------------

with BXE4001_Pure;
package BXE4001_Normal is
  
  procedure No_Parameters; 
  pragma Asynchronous(No_Parameters);                              -- ERROR:
                                                   -- not a remote procedure

  type Ptr_1 is access all BXE4001_Pure.Tagged_Type_1'Class;
  pragma Asynchronous (Ptr_1);                                     -- ERROR:
                                   -- not a remote access-to-class-wide type
end BXE4001_Normal;
