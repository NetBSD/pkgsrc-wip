


with B611015A;
package B611015 is

   procedure P01 (P : in out B611015A.Priv)
      with Post => B611015A.Is_OK(P'Old);                      -- OK. {35;2}

   procedure P02 (P : in out B611015A.Lim_Priv)
      with Post => B611015A.Is_OK(P'Old);                      -- ERROR: {35;2}

   procedure P03 (P : in out B611015A.PTag)
      with Post => P'Old.Is_OK;                                -- OK. {20;1}

   procedure P04 (P : in out B611015A.LTag)
      with Post => P'Old.Is_OK;                                -- ERROR: {20;1}

   procedure P05 (P : in out B611015A.Prot)
      with Post => P'Old.Is_OK;                                -- ERROR: {20;1}

   procedure P06 (T : in out B611015A.Tsk)
      with Post => T'Old'Terminated;                           -- ERROR: {20;1}

   procedure P07 (P : in out B611015A.Rec)
      with Post => P'Old.C = P.C;                              -- OK. {20;7}

   procedure P08 (P : in out B611015A.Lim_Rec)
      with Post => P'Old.N = P.N;                              -- ERROR: {20;7}

   procedure P09 (P : in out B611015A.Lim_Rec)
      with Post => P.N'Old = P.N;                              -- OK. {20;7}

   procedure P10 (P : in out B611015A.LR_Rec)
      with Post => P'Old.N = P.N;                              -- ERROR: {20;7}

   procedure P11 (P : in out B611015A.LR_Rec)
      with Post => P.N'Old = P.N;                              -- OK. {20;7}

   procedure P12 (P : in out B611015A.LP_Rec)
      with Post => P'Old.C = P.C;                              -- ERROR: {20;7}

   procedure P13 (P : in out B611015A.LP_Rec)
      with Post => P.C'Old = P.C;                              -- OK. {20;7}

   procedure P14 (P : in out B611015A.LP_Arr)
      with Post => B611015A.Is_OK(P'Old(1));                   -- ERROR: {35;4}

   procedure P15 (P : in out B611015A.LP_Arr)
      with Post => B611015A.Is_OK(P(2)'Old);                   -- ERROR: {35;1}

   type ATag is tagged record
      P : Positive;
   end record;

   procedure P16 (P : in out ATag)
      with Post'Class => P'Old.P = P.P;                        -- OK. {20;7}

   type BTag is tagged limited record
      I : Integer;
   end record;

   procedure P17 (P : in out BTag)
      with Post'Class => P'Old.I = P.I;                        -- ERROR: {20;7}

   procedure P18 (P : in out BTag)
      with Post'Class => P.I'Old = P.I;                        -- OK. {20;7}

   type Intf is interface;

   function Is_OK (P : Intf) return Boolean is abstract;

   procedure P19 (P : in out Intf) is abstract
      with Post'Class => Is_OK (P'Old);                        -- OK. {33;2}

   procedure P20 (P : in out Intf'Class)
      with Post => Is_OK (P'Old);                              -- OK. {27;2}

   type LIntf is limited interface;

   function Is_OK (P : LIntf) return Boolean is abstract;

   procedure P21 (P : in out LIntf) is abstract
      with Post'Class => Is_OK (P'Old);                        -- ERROR: {33;2}

   procedure P22 (P : in out LIntf'Class)
      with Post => Is_OK (P'Old);                              -- ERROR: {27;2}

end B611015;


