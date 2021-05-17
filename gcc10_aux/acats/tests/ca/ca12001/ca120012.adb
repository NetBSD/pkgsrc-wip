
---------------

with Report;      use Report;
with CA12001_Win; use CA12001_Win;
with Ada.Exceptions;
procedure CA120012 is
    Top_Win    : Window_Type;
    Child1_Win : aliased Window_Type;
    Child2_Win : Window_Type;
    GrandChild1_Win : aliased Window_Type;
    GrandChild2A_Win : aliased Window_Type;
    GrandChild2B_Win : aliased Window_Type;
    Not_Used_Win : Window_Type;

    procedure TC_Check (Window : Window_Type'Class;
                        Expected_Id : Window_Id_Type;
                        Expected_Width : Window_Size;
                        Expected_Height : Window_Size;
                        Check_Name : String) is
    begin
       if Id (Window) /= Expected_Id then
          Failed ("Wrong Id for " & Check_Name & "; saw: " & Id (Window) &
          "; expected: " & Expected_Id);
       end if;
       if Width (Window) /= Ident_Int (Expected_Width) then
          Failed ("Wrong Id for " & Check_Name & "; saw:" &
             Window_Size'Image (Width (Window)) & "; expected:" &
             Window_Size'Image (Expected_Width));
       end if;
       if Height (Window) /= Ident_Int (Expected_Height) then
          Failed ("Wrong Id for " & Check_Name & "; saw:" &
             Window_Size'Image (Height (Window)) & "; expected:" &
             Window_Size'Image (Expected_Height));
       end if;
    end TC_Check;

begin
    Test ("CA120012","Check that a limited private with clause for a " &
                     "private child of a package P can be given on the " &
                     "declaration of P");

    -- Create the windows:
    Create (Top_Win, Id => 'F', Width => 120, Height => 80);
    Create (Child1_Win, Parent => Top_Win, Id => 'J', Width => 80, Height => 50);
    Create (Child2_Win, Parent => Top_Win, Id => 'W', Width => 80, Height => 25);
    Create (GrandChild1_Win, Parent => Child1_Win, Id => 'R', Width => 40, Height => 10);
    Create (GrandChild2A_Win, Parent => Child2_Win, Id => 'D', Width => 40, Height => 15);
    Create (GrandChild2B_Win, Parent => Child2_Win, Id => 'S', Width => 35, Height => 12);

    -- Test the attributes of the windows:
    if Id (Top_Win) /= 'F' then
       Failed ("Wrong Id for Top_Win: " & Id (Top_Win));
    end if;
    if Width (Child1_Win) /= Ident_Int (80) then
       Failed ("Wrong Width for Child 1: " &
          Window_Size'Image (Width (Child1_Win)));
    end if;
    if Height (Child2_Win) /= Ident_Int (25) then
       Failed ("Wrong Height for Child 2: " &
          Window_Size'Image (Height (Child2_Win)));
    end if;

    -- Check all of the windows:
    TC_Check (Top_Win, Expected_Id => 'F',
	      Expected_Width => 120, Expected_Height => 80,
              Check_Name => "Top window");
    TC_Check (Child1_Win, Expected_Id => 'J',
              Expected_Width => 80, Expected_Height => 50,
              Check_Name => "Child 1");
    TC_Check (Child2_Win, Expected_Id => 'W',
              Expected_Width => 80, Expected_Height => 25,
              Check_Name => "Child 2");
    TC_Check (GrandChild1_Win, Expected_Id => 'R',
              Expected_Width => 40, Expected_Height => 10,
              Check_Name => "Grandchild 1");
    TC_Check (GrandChild2A_Win, Expected_Id => 'D',
              Expected_Width => 40, Expected_Height => 15,
              Check_Name => "Grandchild 2A");
    TC_Check (GrandChild2B_Win, Expected_Id => 'S',
              Expected_Width => 35, Expected_Height => 12,
              Check_Name => "Grandchild 2B");


    if Parent (Top_Win) /= null then
       Failed ("Top window has parent");
    end if;
    if Parent (GrandChild1_Win) /= Child1_Win'Unchecked_Access then
       if Parent (GrandChild1_Win) = null then
           Failed ("Grandchild has no parent");
       else
           Failed ("Grandchild has wrong parent " &
              Id (Parent (GrandChild1_Win).all));
       end if;
    end if;
    if Child (Child1_Win) /= GrandChild1_Win'Unchecked_Access then
       if Child (Child1_Win) = null then
           Failed ("Child 1 has no child");
       else
           Failed ("Child 1 has wrong child " & Id (Child (Child1_Win).all));
       end if;
    end if;
    if Sibling (GrandChild2A_Win) /= null and then
       Sibling (GrandChild2A_Win) /= GrandChild2B_Win'Unchecked_Access then
       Failed ("Grandchild 2A has wrong sibling " &
          Id (Sibling (GrandChild2A_Win).all));
    end if;
    if Sibling (GrandChild2A_Win) = null and then
       Sibling (GrandChild2B_Win) = null then
       Failed ("Neither grandchild 2 has a sibling");
    end if;
    if Width (Child (Top_Win).all) /= Ident_Int (80) then
       -- Both children have the same width:
       Failed ("Wrong Width for child of Top_Win: " &
          Window_Size'Image (Width (Child (Top_Win).all)));
    end if;
    Resize (Child (Child1_Win).all, Width => 20, Height => 30);
    TC_Check (GrandChild1_Win, Expected_Id => 'R',
              Expected_Width => 20, Expected_Height => 30,
              Check_Name => "Resize window");

    -- Try a few error cases:
    begin
       if Width (Not_Used_Win) = Ident_Int (10) then
          Comment ("Unusual");
       end if;
       Failed ("Use of Width on unused window not detected");
    exception
       when Not_Valid_Error => null; -- Expected.
    end;
    begin
       if Child (Not_Used_Win) = null then
          Comment ("Unusual");
       end if;
       Failed ("Use of Child on unused window not detected");
    exception
       when Not_Valid_Error => null; -- Expected.
    end;
    begin
       Create (Grandchild1_Win, Parent => Child1_Win, Id => 'R',
               Width => 40, Height => 10);
       Failed ("Creating already created window not detected");
    exception
       when Not_Valid_Error => null; -- Expected.
    end;

    -- Destroy windows:
    Destroy (GrandChild1_Win);
    Destroy (GrandChild2A_Win);
    Destroy (GrandChild2B_Win);
    Destroy (Child2_Win);
    Destroy (Child1_Win);
    Destroy (Top_Win);

    Result;
exception
    when Oops:others =>
        Failed ("Unexpected exception: " & Ada.Exceptions.Exception_Name (Oops));
        Comment ("Exception Info: " & Ada.Exceptions.Exception_Information (Oops));
end CA120012;

