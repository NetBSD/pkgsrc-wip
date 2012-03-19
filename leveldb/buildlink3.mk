# $NetBSD: buildlink3.mk,v 1.2 2012/03/19 00:24:20 bubuchka Exp $

BUILDLINK_TREE+=	leveldb

.if !defined(LEVELDB_BUILDLINK3_MK)
LEVELDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.leveldb+=	leveldb>=1.2
BUILDLINK_PKGSRCDIR.leveldb?=	../../wip/leveldb
.endif	# LEVELDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-leveldb
