# $NetBSD: buildlink3.mk,v 1.1 2013/12/13 00:46:40 noud4 Exp $

BUILDLINK_TREE+=	uthash

.if !defined(UTHASH_BUILDLINK3_MK)
UTHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uthash+=	uthash>=1.9.4
BUILDLINK_PKGSRCDIR.uthash?=	../../wip/uthash

.endif # UTHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-uthash
