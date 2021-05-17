

package body F760A00.Child is

    procedure Check_Init (Object : in Lim_Ext; Message : in String) is
    begin
       TCTouch.Validate ("III", Message);
    end Check_Init;

    procedure Check_Fin_Lim_Ext (Message : in String) is
    begin
       TCTouch.Validate ("FFF", Message);
    end Check_Fin_Lim_Ext;

    procedure Use_It (Object : in out Lim_Ext'Class) is
       -- Ensure that Object is not removed by optimization
       -- as a dead variable.
    begin
       Use_It (Lim_Tagged (Object));
       Use_It (Object.TC2);
    end Use_It;

end F760A00.Child;
