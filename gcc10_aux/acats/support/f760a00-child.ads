

with TCTouch, Report;
package F760A00.Child is

    type Lim_Ext is new Lim_Tagged with record
       G : Natural;
       TC2 : TC_Copy_Check; -- Always default initialize.
    end record;

    procedure Check_Init (Object : in Lim_Ext; Message : in String);

    procedure Check_Fin_Lim_Ext (Message : in String);

    procedure Use_It (Object : in out Lim_Ext'Class);
       -- Ensure that Object is not removed by optimization
       -- as a dead variable.

end F760A00.Child;
