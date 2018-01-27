# $NetBSD$

BUILDLINK_TREE+=	lumberjack

.if !defined(LUMBERJACK_BUILDLINK3_MK)
LUMBERJACK_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.lumberjack=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.lumberjack?=	build

BUILDLINK_API_DEPENDS.lumberjack+=	lumberjack>=2.0
BUILDLINK_PKGSRCDIR.lumberjack?=	../../wip/lumberjack
.endif	# LUMBERJACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-lumberjack
