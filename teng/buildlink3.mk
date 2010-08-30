# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/08/30 19:21:32 ondratu Exp $

BUILDLINK_TREE+=	teng

.if !defined(TENG_BUILDLINK3_MK)
TENG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.teng+=	teng>=2.1.0
BUILDLINK_PKGSRCDIR.teng?=	../../wip/teng
.endif	# TENG_BUILDLINK3_MK

BUILDLINK_TREE+=	-teng
