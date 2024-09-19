# $NetBSD: buildlink3.mk,v 1.2 2015/04/14 11:33:02 thomasklausner Exp $

BUILDLINK_TREE+=	py-teng

.if !defined(PY_TENG_BUILDLINK3_MK)
PY_TENG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-teng+=	${PYPKGPREFIX}-teng>=2.0.0
BUILDLINK_PKGSRCDIR.py-teng?=	../../wip/py-teng

.include "../../wip/teng/buildlink3.mk"
.endif	# PY_TENG_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-teng
