

     --==================================================================--


with FC50A00;

with CC50A01_0;
pragma Elaborate (CC50A01_0);

package CC50A01_2 is new CC50A01_0 (FC50A00.Count_Type,
                                    FC50A00.TC_Default_Count);
