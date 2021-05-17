
with Report;

package body F611A00 is

   procedure TC_Clear is
   begin
      TC_Object_Distance_Called                 := False;
      TC_Object_Distance_Is_Positive_Called     := False;
      TC_Object_Not_Too_Far_Called              := False;
      TC_Object_Not_Too_Near_Called             := False;
      TC_Object_Distance_Post_Class_Called      := False;
      TC_Object_Distance_Pre_Class_Called       := False;
      TC_Object_Distance_Specific_Post_Called   := False;
      TC_Object_Distance_Specific_Pre_Called    := False;
      TC_Object_X_Coord_Called                  := False;
      TC_Object_Y_Coord_Called                  := False;
      TC_Point_Distance_Post_Class_Called       := False;
      TC_Point_Distance_Pre_Class_Called        := False;
      TC_Triangle_Distance_Called               := False;
      TC_Triangle_Distance_Is_Positive_Called   := False;
      TC_Triangle_Not_Too_Far_Called            := False;
      TC_Triangle_Not_Too_Near_Called           := False;
      TC_Triangle_Distance_Post_Class_Called    := False;
      TC_Triangle_Distance_Pre_Class_Called     := False;
      TC_Triangle_Distance_Specific_Post_Called := False;
      TC_Triangle_Distance_Specific_Pre_Called  := False;
      TC_Triangle_X_Coord_Called                := False;
      TC_Triangle_Y_Coord_Called                := False;
   end TC_Clear;

   function TC_Log_Object_Distance_Pre_Class_Called return Boolean is
   begin
      TC_Object_Distance_Pre_Class_Called := True;

      return True;
   end TC_Log_Object_Distance_Pre_Class_Called;

   function TC_Log_Object_Distance_Post_Class_Called return Boolean is
   begin
      -- Note that the Post'Class is called for children too
      if not (TC_Object_Distance_Called or TC_Triangle_Distance_Called) then
         Report.Failed
          ("Failure 13.1, Post'Class should only have been called after the" &
           " subprogram body");
         TC_Output;
      end if;

      TC_Object_Distance_Post_Class_Called := True;

      return True;
   end TC_Log_Object_Distance_Post_Class_Called;

   function TC_Log_Object_Distance_Specific_Pre_Called return Boolean is
   begin
      TC_Object_Distance_Specific_Pre_Called := True;

      return True;
   end TC_Log_Object_Distance_Specific_Pre_Called;

   function TC_Log_Object_Distance_Specific_Post_Called return Boolean is
   begin
      if not TC_Object_Distance_Called then
         Report.Failed
          ("Failure 14.1, specific postcondition should only have been" &
           " called after the subprogram body");
         TC_Output;
      end if;

      TC_Object_Distance_Specific_Post_Called := True;

      return True;
   end TC_Log_Object_Distance_Specific_Post_Called;

   function TC_Log_Object_X_Coord_Specific_Pre_Called return Boolean is
   begin
      TC_Object_X_Coord_Specific_Pre_Called := True;

      return True;
   end TC_Log_Object_X_Coord_Specific_Pre_Called;

   function TC_Log_Object_X_Coord_Specific_Post_Called return Boolean is
   begin
      TC_Object_X_Coord_Specific_Post_Called := True;

      return True;
   end TC_Log_Object_X_Coord_Specific_Post_Called;

   function TC_Log_Object_Y_Coord_Specific_Pre_Called return Boolean is
   begin
      TC_Object_Y_Coord_Specific_Pre_Called := True;

      return True;
   end TC_Log_Object_Y_Coord_Specific_Pre_Called;

   function TC_Log_Object_Y_Coord_Specific_Post_Called return Boolean is
   begin
      TC_Object_Y_Coord_Specific_Post_Called := True;

      return True;
   end TC_Log_Object_Y_Coord_Specific_Post_Called;

   function TC_Log_Point_Distance_Pre_Class_Called return Boolean is
   begin
      TC_Point_Distance_Pre_Class_Called := True;

      return True;
   end TC_Log_Point_Distance_Pre_Class_Called;

   function TC_Log_Point_Distance_Post_Class_Called return Boolean is
   begin
      -- Note that the Post'Class is called for children too
      if not (TC_Object_Distance_Called or TC_Triangle_Distance_Called) then
         Report.Failed
          ("Failure 13.1, Post'Class should only have been called after the" &
           " subprogram body");
         TC_Output;
      end if;

      TC_Point_Distance_Post_Class_Called := True;

      return True;
   end TC_Log_Point_Distance_Post_Class_Called;

   function TC_Log_Triangle_Distance_Pre_Class_Called return Boolean is
   begin
      TC_Triangle_Distance_Pre_Class_Called := True;

      return True;
   end TC_Log_Triangle_Distance_Pre_Class_Called;

   function TC_Log_Triangle_Distance_Post_Class_Called return Boolean is
   begin
      if not TC_Triangle_Distance_Called then
         raise TC_Order_Error; -- Postcondition before body.
      end if;

      TC_Triangle_Distance_Post_Class_Called := True;

      return True;
   end TC_Log_Triangle_Distance_Post_Class_Called;

   function TC_Log_Triangle_Distance_Specific_Pre_Called return Boolean is
   begin
      TC_Triangle_Distance_Specific_Pre_Called := True;

      return True;
   end TC_Log_Triangle_Distance_Specific_Pre_Called;

   function TC_Log_Triangle_Distance_Specific_Post_Called return Boolean is
   begin
      if not TC_Triangle_Distance_Called then
         raise TC_Order_Error; -- Postcondition before body.
      end if;

      TC_Triangle_Distance_Specific_Post_Called := True;

      return True;
   end TC_Log_Triangle_Distance_Specific_Post_Called;

   procedure TC_Output is
   begin
      Report.Comment
       ("Object_Distance_Called is " &
        Boolean'Image (TC_Object_Distance_Called));

      Report.Comment
       ("Object_Distance_Is_Positive_Called is " &
        Boolean'Image (TC_Object_Distance_Is_Positive_Called));

      Report.Comment
       ("Object_Not_Too_Far_Called is " &
        Boolean'Image (TC_Object_Not_Too_Far_Called));

      Report.Comment
       ("Object_Not_Too_Near_Called is " &
        Boolean'Image (TC_Object_Not_Too_Near_Called));

      Report.Comment
       ("Object_Distance_Pre_Class_Called is " &
        Boolean'Image (TC_Object_Distance_Pre_Class_Called));

      Report.Comment
       ("Object_Distance_Post_Class_Called is " &
        Boolean'Image (TC_Object_Distance_Post_Class_Called));

      Report.Comment
       ("Object_Distance_Specific_Pre_Called is " &
        Boolean'Image (TC_Object_Distance_Specific_Pre_Called));

      Report.Comment
       ("Object_Distance_Specific_Post_Called is " &
        Boolean'Image (TC_Object_Distance_Specific_Post_Called));

      Report.Comment
       ("Object_X_Coord_Called is " &
        Boolean'Image (TC_Object_X_Coord_Called));

      Report.Comment
       ("Object_Y_Coord_Called is " &
        Boolean'Image (TC_Object_Y_Coord_Called));

      Report.Comment
       ("Point_Distance_Pre_Class_Called is " &
        Boolean'Image (TC_Point_Distance_Pre_Class_Called));

      Report.Comment
       ("Point_Distance_Post_Class_Called is " &
        Boolean'Image (TC_Point_Distance_Post_Class_Called));

      Report.Comment
       ("Triangle_Distance_Called is " &
        Boolean'Image (TC_Triangle_Distance_Called));

      Report.Comment
       ("Triangle_Distance_Is_Positive_Called is " &
        Boolean'Image (TC_Triangle_Distance_Is_Positive_Called));

      Report.Comment
       ("Triangle_Not_Too_Far_Called is " &
        Boolean'Image (TC_Triangle_Not_Too_Far_Called));

      Report.Comment
       ("Triangle_Not_Too_Near_Called is " &
        Boolean'Image (TC_Triangle_Not_Too_Near_Called));

      Report.Comment
       ("Triangle_Distance_Pre_Class_Called is " &
        Boolean'Image (TC_Triangle_Distance_Pre_Class_Called));

      Report.Comment
       ("Triangle_Distance_Post_Class_Called is " &
        Boolean'Image (TC_Triangle_Distance_Post_Class_Called));

      Report.Comment
       ("Triangle_Distance_Specific_Pre_Called is " &
        Boolean'Image (TC_Triangle_Distance_Specific_Pre_Called));

      Report.Comment
       ("Triangle_Distance_Specific_Post_Called is " &
        Boolean'Image (TC_Triangle_Distance_Specific_Post_Called));

      Report.Comment
       ("Triangle_X_Coord_Called is " &
        Boolean'Image (TC_Triangle_X_Coord_Called));

      Report.Comment
       ("Triangle_Y_Coord_Called is " &
        Boolean'Image (TC_Triangle_Y_Coord_Called));

      Report.Comment ("");
   end TC_Output;

end F611A00;
