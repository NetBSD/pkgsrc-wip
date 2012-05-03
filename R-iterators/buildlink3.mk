# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/03 22:36:54 bubuchka Exp $

BUILDLINK_TREE+=	Riterators

.if !defined(RITERATORS_BUILDLINK3_MK)
RITERATORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Riterators+=	R-iterators>=1.0.6
BUILDLINK_ABI_DEPENDS.Riterators+=	R-iterators>=1.0.6
BUILDLINK_PKGSRCDIR.Riterators?=	../../wip/R-iterators
.endif # RITERATORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-Riterators
