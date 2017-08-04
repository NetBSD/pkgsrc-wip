# $NetBSD$

BUILDLINK_TREE+=       OpenIPMI

.if !defined(OPENIPMI_BUILDLINK3_MK)
OPENIPMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.OpenIPMI+=       OpenIPMI>=2.0.24
BUILDLINK_PKGSRCDIR.OpenIPMI?= ../../devel/OpenIPMI

.include "../../devel/popt/buildlink3.mk"
.endif # OPENIPMI_BUILDLINK3_MK

BUILDLINK_TREE+=       -OpenIPMI
