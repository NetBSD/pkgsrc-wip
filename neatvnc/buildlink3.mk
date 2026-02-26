# $NetBSD$

BUILDLINK_TREE+=	neatvnc

.if !defined(NEATVNC_BUILDLINK3_MK)
NEATVNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.neatvnc+=	neatvnc>=0.9.5
BUILDLINK_PKGSRCDIR.neatvnc?=	../../wip/neatvnc

.include "../../wip/aml/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.endif	# NEATVNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-neatvnc
