
---------------

with CA12001_Win.Impl;
with Ada.Unchecked_Deallocation;
package body CA12001_Win is
    -- A simple windowing package.

    procedure Free is new Ada.Unchecked_Deallocation (CA12001_Win.Impl.Low_Win_Type,
          Low_Win_Access);

    procedure Create (Window : in out Window_Type;
                      Id     : in Window_Id_Type;
                      Width  : in Window_Size;
                      Height : in Window_Size) is
       -- Create a new top-level window with the specified characteristics.
       -- Raises Not_Valid_Error if the Window has already been created.
    begin
       if Window.Is_Created then
           raise Not_Valid_Error;
       end if;
       Window.Parent := null;
       Window.Child := null;
       Window.Next_Sibling := null;
       Window.Is_Created := True;
       Window.Id := Id;
       Window.Win_Obj := new CA12001_Win.Impl.Low_Win_Type;
       CA12001_Win.Impl.Open (Window.Win_Obj.all);
       CA12001_Win.Impl.Set_Size (Window.Win_Obj.all, Width, Height);
    end Create;

    procedure Create (Window : in out Window_Type;
                      Parent : in out Window_Type'Class;
                      Id     : in Window_Id_Type;
                      Width  : in Window_Size;
                      Height : in Window_Size) is
       -- Create a new child window with the specified characteristics.
       -- Raises Not_Valid_Error if the Window has already been created.
    begin
       if Window.Is_Created then
           raise Not_Valid_Error;
       end if;
       if not Parent.Is_Created then
           raise Not_Valid_Error;
       end if;
       Window.Is_Created := True;
       Window.Parent := Parent'Unchecked_Access;
       Window.Child := null;
       if Parent.Child = null then
          Parent.Child := Window'Unchecked_Access;
          Window.Next_Sibling := null;
       else
          Window.Next_Sibling := Parent.Child;
          Parent.Child := Window'Unchecked_Access;
       end if;
       Window.Id := Id;
       Window.Win_Obj := new CA12001_Win.Impl.Low_Win_Type;
       CA12001_Win.Impl.Open (Window.Win_Obj.all);
       CA12001_Win.Impl.Set_Size (Window.Win_Obj.all, Width, Height);
    end Create;

    procedure Destroy (Window : in out Window_Type) is
       -- Destroy a window.
       -- Raises Not_Valid_Error if the Window has not been created, or
       -- if Window has any children that have not been destroyed.
    begin
       if not Window.Is_Created then
           raise Not_Valid_Error;
       elsif Window.Child /= null then
           raise Not_Valid_Error;
       end if;
       CA12001_Win.Impl.Close (Window.Win_Obj.all);
       Free (Window.Win_Obj);
       if Window.Parent /= null then
          -- Remove the window from the parent's list:
          if Window.Parent.Child = Window'Unchecked_Access then
             Window.Parent.Child := Window.Next_Sibling;
          else
             declare
                Cursor : Any_Window_Access_Type := Window.Parent.Child;
             begin
                loop
                    if Cursor.Next_Sibling = Window'Unchecked_Access then
                       Cursor.Next_Sibling := Window.Next_Sibling;
                       exit;
                    end if;
                    Cursor := Cursor.Next_Sibling;
                end loop;
             end;
          end if;
       end if;
       Window.Is_Created := False;
    end Destroy;

    function Id (Window : in Window_Type) return Window_Id_Type is
       -- Returns the Id of a window.
       -- Raises Not_Valid_Error if the Window has not been created.
    begin
       if not Window.Is_Created then
           raise Not_Valid_Error;
       end if;
       return Window.Id;
    end Id;

    function Height (Window : in Window_Type) return Window_Size is
       -- Returns the Height of a window.
       -- Raises Not_Valid_Error if the Window has not been created.
       Temp_Width, Temp_Height : Window_Size;
    begin
       if not Window.Is_Created then
           raise Not_Valid_Error;
       end if;
       CA12001_Win.Impl.Get_Size (Window.Win_Obj.all,
                                  Width => Temp_Width,
                                  Height => Temp_Height);
       return Temp_Height;
    end Height;

    function Width (Window : in Window_Type) return Window_Size is
       -- Returns the Width of a window.
       -- Raises Not_Valid_Error if the Window has not been created.
       Temp_Width, Temp_Height : Window_Size;
    begin
       if not Window.Is_Created then
           raise Not_Valid_Error;
       end if;
       CA12001_Win.Impl.Get_Size (Window.Win_Obj.all,
                                  Width => Temp_Width,
                                  Height => Temp_Height);
       return Temp_Width;
    end Width;

    procedure Resize (Window : in Window_Type;
                      Width  : in Window_Size;
                      Height : in Window_Size) is
       -- Change the size of a window.
       -- Raises Not_Valid_Error if the Window has not been created.
    begin
       if not Window.Is_Created then
           raise Not_Valid_Error;
       end if;
       CA12001_Win.Impl.Set_Size (Window.Win_Obj.all,
                                  Width => Width,
                                  Height => Height);
    end Resize;

    function Parent (Window : in Window_Type) return Any_Window_Access_Type is
       -- Returns an access to the parent of this window. Returns null if
       -- this is a top-level window.
       -- Raises Not_Valid_Error if the Window has not been created.
    begin
       if not Window.Is_Created then
           raise Not_Valid_Error;
       end if;
       return Window.Parent;
    end Parent;

    function Child (Window : in Window_Type) return Any_Window_Access_Type is
       -- Returns an access to a child of this window. Returns null if
       -- this window has no children.
       -- Raises Not_Valid_Error if the Window has not been created.
    begin
       if not Window.Is_Created then
           raise Not_Valid_Error;
       end if;
       return Window.Child;
    end Child;

    function Sibling (Window : in Window_Type) return Any_Window_Access_Type is
       -- Returns an access to a sibling of this window. Returns null if
       -- this window has no siblings.
       -- Raises Not_Valid_Error if the Window has not been created.
    begin
       if not Window.Is_Created then
           raise Not_Valid_Error;
       end if;
       return Window.Next_Sibling;
    end Sibling;

end CA12001_Win;
