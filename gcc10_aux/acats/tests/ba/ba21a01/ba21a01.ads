                                  -- Pragma does not apply to this instance.


     --===================================================================--


with FA21A00;

with BA21A01_0;
with BA21A01_1;
with BA21A01_2;
with BA21A01_3;
with BA21A01_4;
with BA21A01_5;
with BA21A01_6;
with BA21A01_7;
with BA21A01_8;
with BA21A01_9;
with BA21A01_10;
package BA21A01 is

   pragma Preelaborate (BA21A01);


   package CallNonstaticFunction is new BA21A01_0;                    -- ERROR:
                                             -- Call to nonstatic function (a).

   package NonstaticObjectAsPrimary is new BA21A01_2
     (FA21A00.Ten);                                                   -- ERROR:
                                       -- Primary that is a name of an object
                                       -- which is not a static expression (c).

   package PrivateExtensionComponent is new BA21A01_6
     (FA21A00.Idx, FA21A00.PriExtComp);                               -- ERROR:
                   -- Default-initialized component of a private extension (d).

   package ControlAggregate is new BA21A01_7;                         -- ERROR:
             -- Extension aggregate with ancestor denoting controlled type (e).

   package CallInComponentDefault is new BA21A01_8;                   -- ERROR:
                                        -- Call to nonstatic function (in
                                        -- component's default expression) (d).

   package FormPriObject1 is new BA21A01_9
     (FA21A00.Priv);                                                  -- ERROR:
                  -- Default-initialized object of a (formal) private type (d).

   package FormPriObject2 is new BA21A01_9
     (FA21A00.Pri_Ext);                                               -- ERROR:
                           -- Default-initialized object of a private extension
                           -- (passed through a formal private type) (d).

private

   package CallFormalFunction is new BA21A01_1
     (FA21A00.My_Int, FA21A00.Func);                                  -- ERROR:
                                    -- Call to nonstatic (formal) function (b).

   package ProtectedObjectWithEntry is new BA21A01_3;                 -- ERROR:
                                                -- Object of a protected type
                                                -- with entry declarations (d).

   package ControlledObject is new BA21A01_4;                         -- ERROR:
                        -- Default-initialized object of a controlled type (d).

   package PrivateObject is new BA21A01_5;                            -- ERROR:
                           -- Default-initialized object of a private type (d).

   package FormPriExtObject is new BA21A01_10
     (FA21A00.Pri_Ext);                                               -- ERROR:
             -- Default-initialized object of a (formal) private extension (d).

end BA21A01;
