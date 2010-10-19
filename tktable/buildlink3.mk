# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/10/19 22:38:59 othyro Exp $

BUILDLINK_TREE+=	tktable

.if !defined(TKTABLE_BUILDLINK3_MK)
TKTABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tktable+=	tktable>=2.10
BUILDLINK_PKGSRCDIR.tktable?=	../../wip/tktable

.include "../../wip/tk85/buildlink3.mk"
.endif # TKTABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-tktable
