# $NetBSD$

BUILDLINK_TREE+=	heatshrink

.if !defined(HEATSHRINK_BUILDLINK3_MK)
HEATSHRINK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.heatshrink+=	heatshrink>=0.4.0
BUILDLINK_PKGSRCDIR.heatshrink?=	../../wip/heatshrink
BUILDLINK_FILES.heatshrink+=		bin/heatshrink
.endif	# HEATSHRINK_BUILDLINK3_MK

BUILDLINK_TREE+=	-heatshrink
