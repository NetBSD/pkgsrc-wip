# $NetBSD: buildlink3.mk,v 1.1 2014/11/29 19:31:38 nros Exp $

BUILDLINK_TREE+=	gflags

.if !defined(GFLAGS_BUILDLINK3_MK)
GFLAGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gflags+=	gflags>=2.1.2
BUILDLINK_PKGSRCDIR.gflags?=	../../jb-wip/gflags
.endif	# GFLAGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gflags
