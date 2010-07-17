# $NetBSD: buildlink3.mk,v 1.1 2010/07/17 00:49:41 jihbed Exp $

BUILDLINK_TREE+=	py26-gevent

.if !defined(PY26_GEVENT_BUILDLINK3_MK)
PY26_GEVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-gevent+=	py26-gevent>=0.13.0
BUILDLINK_PKGSRCDIR.py26-gevent?=	../../wip/py-gevent

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.endif	# PY26_GEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-gevent
