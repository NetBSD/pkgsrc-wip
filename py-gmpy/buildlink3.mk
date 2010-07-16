# $NetBSD: buildlink3.mk,v 1.1 2010/07/16 22:13:23 jihbed Exp $

BUILDLINK_TREE+=	py26-gmpy

.if !defined(PY26_GMPY_BUILDLINK3_MK)
PY26_GMPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-gmpy+=	py26-gmpy>=1.12
BUILDLINK_PKGSRCDIR.py26-gmpy?=	../../wip/py-gmpy

.include "../../devel/gmp/buildlink3.mk"
.endif	# PY26_GMPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-gmpy
