# $NetBSD: buildlink3.mk,v 1.1 2015/04/30 22:16:52 jonthn Exp $

BUILDLINK_TREE+=	jemalloc

.if !defined(JEMALLOC_BUILDLINK3_MK)
JEMALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jemalloc+=	jemalloc>=4.0.0
BUILDLINK_PKGSRCDIR.jemalloc?=	../../wip/jemalloc
.endif	# JEMALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jemalloc
