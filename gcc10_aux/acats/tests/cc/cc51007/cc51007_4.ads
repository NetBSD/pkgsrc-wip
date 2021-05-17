

     --===================================================================--


with CC51007_1;

with CC51007_3;
pragma Elaborate (CC51007_3);

package CC51007_4 is new CC51007_3 (CC51007_1.Low_Alert, CC51007_1.Low);
