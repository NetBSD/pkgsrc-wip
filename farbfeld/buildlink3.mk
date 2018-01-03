# $NetBSD$

BUILDLINK_TREE+=	farbfeld

.if !defined(FARBFELD_BUILDLINK3_MK)
FARBFELD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.farbfeld+=	farbfeld>=1
BUILDLINK_PKGSRCDIR.farbfeld?=		../../wip/farbfeld

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# FARBFELD_BUILDLINK3_MK

BUILDLINK_TREE+=	-farbfeld
