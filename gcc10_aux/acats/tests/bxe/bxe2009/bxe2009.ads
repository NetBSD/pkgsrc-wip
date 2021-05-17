
-----------------------------------------------------------------

with BXE2009_Types;  use BXE2009_Types;
with Ada.Streams;

with BXE2009_SP;                                                     -- OK.
                                 -- OK to depend upon a shared passive package
with Ada.Command_Line;                                               -- ERROR:
                                        -- Cannot depend upon a normal package
package BXE2009 is
  pragma Remote_Call_Interface;

  -----
  -- first, some legal declarations
  -----

  Non_Variable : constant Integer := 19;                             -- OK.


  procedure No_Parameters;                                           -- OK.
  pragma Asynchronous(No_Parameters);                                -- OK.

  procedure Simple (X, Y : in Integer);                              -- OK.
  function "+"(X, Y : Integer) return Float;                         -- OK.
  procedure Has_Private_Parameters (P : Ok_Parameter_Type);          -- OK.
  pragma Asynchronous(Has_Private_Parameters);                       -- OK.

  procedure Has_Ok_Limited (P : Is_Limited_With_Attrs);              -- OK.


  -----
  -- now, some illegal declarations
  -----

  type Integer_Pointer is access Integer;                            -- ERROR:
                -- Not an access to subprogram or access to class wide limited
                -- private type.

  Not_Preelaborable : constant Integer := Non_Static_Function;       -- ERROR:
                                                        -- Not preelaborable.

  A_Visible_Variable : Integer;                                      -- ERROR:
                                                -- Variables are not allowed.

  type Limited_Type is limited private;                              -- ERROR:
                                          -- Limited types are not permitted.

  task type Any_Task_Type;                                           -- ERROR:
                                               -- Task types are not allowed.


  protected type Shared_Counter is                                   -- ERROR:
    procedure Increment;                  -- Protected types are not allowed.
  private
    The_Counter : Integer := 2;
  end Shared_Counter;


  generic                                                            -- ERROR:
                              -- Nested generic declarations are not allowed.
    type Element is private;
  procedure Swap (A, B : in out Element);


  procedure Is_Inlined (T : Integer);                                -- ERROR:
               -- Subprograms to which pragma inline applies are not allowed.
  pragma Inline (Is_Inlined);

  procedure Has_Access_Parameters (T : access Integer);              -- ERROR:
                                      -- Access parameters are not permitted.

  procedure Has_Out_Parameters (P : out Integer);                    -- OK.
  pragma Asynchronous(Has_Out_Parameters);                           -- ERROR:
               -- The parameters for a procedure named in pragma Asynchronous
               -- must be of mode in.

  procedure Has_Limited_Parm (P : in out Is_Limited);                -- ERROR:
               -- The parameter type does not support external streaming
               -- (it is limited and the limited type does not have
               -- available 'read and 'write attributes).

private
  type Limited_Type is new Integer;                         -- OPTIONAL ERROR:
            -- The declaration of Limited_Type should have been flagged as not
            -- allowed in a RCI package.  This declaration may or may not be
            -- flagged as well.
end BXE2009;
