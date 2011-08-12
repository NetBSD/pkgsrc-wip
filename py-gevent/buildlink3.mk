# $NetBSD: buildlink3.mk,v 1.2 2011/08/12 12:58:59 asau Exp $

BUILDLINK_TREE+=	py-gevent

.if !defined(PY26_GEVENT_BUILDLINK3_MK)
PY26_GEVENT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gevent+=	${PYPKGPREFIX}-gevent>=0.13.0
BUILDLINK_PKGSRCDIR.py-gevent?=		../../wip/py-gevent

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.endif	# PY26_GEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gevent
