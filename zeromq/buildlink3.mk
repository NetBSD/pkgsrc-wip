# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/04/04 14:00:46 obache Exp $
#

BUILDLINK_TREE+=	zeromq

.if !defined(ZEROMQ_BUILDLINK3_MK)
ZEROMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zeromq+=	zeromq>=2.0.11
BUILDLINK_PKGSRCDIR.zeromq?=	../../wip/zeromq
.endif	# ZEROMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-zeromq
