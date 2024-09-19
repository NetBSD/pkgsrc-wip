# $NetBSD: buildlink3.mk,v 1.2 2015/04/14 11:33:02 thomasklausner Exp $

BUILDLINK_TREE+=	py-dbglog

.if !defined(PY_DBGLOG_BUILDLINK3_MK)
PY_DBGLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-dbglog+=	${PYPKGPREFIX}-dbglog>=1.5.0
BUILDLINK_PKGSRCDIR.py-dbglog?=		../../wip/py-dbglog

.include "../../wip/libdbglog/buildlink3.mk"
.endif	# PY_DBGLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-dbglog
