# $NetBSD: buildlink3.mk,v 1.3 2012/09/24 01:08:57 bubuchka Exp $

BUILDLINK_TREE+=	leveldb

.if !defined(LEVELDB_BUILDLINK3_MK)
LEVELDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.leveldb+=	leveldb>=1.5
BUILDLINK_PKGSRCDIR.leveldb?=	../../wip/leveldb
.endif	# LEVELDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-leveldb
