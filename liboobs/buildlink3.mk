# $NetBSD: buildlink3.mk,v 1.1 2015/01/03 07:10:32 obache Exp $

BUILDLINK_TREE+=	liboobs

.if !defined(LIBOOBS_BUILDLINK3_MK)
LIBOOBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboobs+=	liboobs>=2.32.0
BUILDLINK_PKGSRCDIR.liboobs?=	../../wip/liboobs
.endif # LIBOOBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboobs
