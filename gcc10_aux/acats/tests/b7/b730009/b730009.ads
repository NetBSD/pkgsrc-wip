
with B730009A;
package B730009 is
   type Priv01 is new B730009A.S_IFace with private;  -- POSSIBLE ERROR: [Set1]

   type Priv02 is new B730009A.T_IFace with private;  -- POSSIBLE ERROR: [Set2]

   type Priv03 is new B730009A.P_IFace with private;  -- POSSIBLE ERROR: [Set3]

   type Priv10 is limited new B730009A.L_IFace with private;

   type Priv11 is limited new B730009A.L_IFace with private;

   type Priv12 is limited new B730009A.L_IFace with private;

   type Priv20 is tagged limited private;

   type Priv21 is tagged limited private;

   type Priv30 is synchronized new B730009A.S_IFace with private;

   type Priv31 is synchronized new B730009A.T_IFace with private;

   type Priv32 is synchronized new B730009A.P_IFace with private;

   type Priv40 is synchronized new B730009A.L_IFace with private;

   type Priv41 is synchronized new B730009A.L_IFace with private;

   type Priv42 is synchronized new B730009A.L_IFace with private;

   type Priv43 is synchronized new B730009A.L_IFace with private;

private
   -- The partial view Priv01 is not synchronized.
   task type Priv01 is new B730009A.S_IFace with      -- POSSIBLE ERROR: [Set1]
   end Priv01;

   -- The partial view Priv02 is not synchronized.
   task type Priv02 is new B730009A.T_IFace with      -- POSSIBLE ERROR: [Set2]
   end Priv02;

   -- The partial view Priv03 is not synchronized.
   protected type Priv03 is new B730009A.P_IFace with -- POSSIBLE ERROR: [Set3]
   private
      Foo : Natural;
   end Priv03;

   -- The partial view Priv10 is not synchronized.
   task type Priv10 is new B730009A.L_IFace with      -- ERROR:
   end Priv10;

   -- The partial view Priv11 is not synchronized.
   protected type Priv11 is new B730009A.L_IFace with -- ERROR:
   private
      Foo : Natural;
   end Priv11;

   type Priv12 is limited new B730009A.Type_Implementing_L_IFace
      with null record;                               -- OK.

   -- The partial view Priv20 is not synchronized.
   task type Priv20 is                                -- ERROR:
   end Priv20;

   -- The partial view Priv21 is not synchronized.
   protected type Priv21 is                           -- ERROR:
   private
      Foo : Natural;
   end Priv21;

   task type Priv30 is new B730009A.S_IFace with      -- OK.
   end Priv30;

   task type Priv31 is new B730009A.T_IFace with      -- OK.
   end Priv31;

   protected type Priv32 is new B730009A.P_IFace with -- OK.
   private
      Foo : Natural;
   end Priv32;

   task type Priv40 is new B730009A.L_IFace with      -- OK.
   end Priv40;

   protected type Priv41 is new B730009A.L_IFace with -- OK.
   private
      Foo : Natural;
   end Priv41;

   -- The completion is not synchronized.
   type Priv42 is limited new B730009A.L_IFace
      with null record;                               -- ERROR:

   -- The completion is not synchronized.
   type Priv43 is new B730009A.Type_Implementing_L_IFace
      with null record;                               -- ERROR:

end B730009;
