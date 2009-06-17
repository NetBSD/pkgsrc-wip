# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/06/17 23:39:46 jihbed Exp $

BUILDLINK_TREE+=	py-fs

.if !defined(PY_FS_BUILDLINK3_MK)
PY_FS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-fs+=	py-fs>=0.1.0
BUILDLINK_PKGSRCDIR.py-fs?=	../../wip/py-fs
.endif	# PY_FS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-fs
