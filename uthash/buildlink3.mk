# $NetBSD: buildlink3.mk,v 1.2 2014/02/12 09:29:55 thomasklausner Exp $

BUILDLINK_TREE+=	uthash

.if !defined(UTHASH_BUILDLINK3_MK)
UTHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uthash+=	uthash>=1.9.8
BUILDLINK_PKGSRCDIR.uthash?=	../../wip/uthash
BUILDLINK_DEPMETHOD.uthash?=	build
.endif	# UTHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-uthash
