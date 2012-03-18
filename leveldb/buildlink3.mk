# $NetBSD: buildlink3.mk,v 1.1 2012/03/18 20:57:50 bubuchka Exp $

BUILDLINK_TREE+=	leveldb

.if !defined(LEVELDB_BUILDLINK3_MK)
LEVELDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.leveldb+=	leveldb-[0-9]*
BUILDLINK_PKGSRCDIR.leveldb?=	../../wip/leveldb
.endif	# LEVELDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-leveldb
