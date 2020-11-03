# $NetBSD$

BUILDLINK_TREE+=	openipmi

.if !defined(OPENIPMI_BUILDLINK3_MK)
OPENIPMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openipmi+=	openipmi>=2.0.29
BUILDLINK_PKGSRCDIR.openipmi?=		../../sysutils/openipmi

.include "../../devel/popt/buildlink3.mk"
.endif # OPENIPMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openipmi
