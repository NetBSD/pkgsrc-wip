# $NetBSD: buildlink3.mk,v 1.2 2012/10/14 13:26:57 thomasklausner Exp $

BUILDLINK_TREE+=	tktable

.if !defined(TKTABLE_BUILDLINK3_MK)
TKTABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tktable+=	tktable>=2.10
BUILDLINK_PKGSRCDIR.tktable?=	../../wip/tktable

.include "../../x11/tk/buildlink3.mk"
.endif # TKTABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-tktable
