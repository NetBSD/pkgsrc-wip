# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/08/08 19:09:31 jihbed Exp $

BUILDLINK_TREE+=	mmdb

.if !defined(MMDB_BUILDLINK3_MK)
MMDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mmdb+=	mmdb>=1.21
BUILDLINK_PKGSRCDIR.mmdb?=	../../wip/mmdb
.endif	# MMDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-mmdb
