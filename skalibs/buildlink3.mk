# $NetBSD$

BUILDLINK_TREE+=	skalibs

.if !defined(SKALIBS_BUILDLINK3_MK)
SKALIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.skalibs+=		skalibs>=2.3.8.3
BUILDLINK_PKGSRCDIR.skalibs?=		../../wip/skalibs

.endif # SKALIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-skalibs
