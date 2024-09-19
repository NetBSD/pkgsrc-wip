# $NetBSD: buildlink3.mk,v 1.2 2015/04/14 11:33:02 thomasklausner Exp $

BUILDLINK_TREE+=	py-errorhandler

.if !defined(PY_ERRORHANDLER_BUILDLINK3_MK)
PY_ERRORHANDLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-errorhandler+=	${PYPKGPREFIX}-errorhandler>=1.1.1
BUILDLINK_PKGSRCDIR.py-errorhandler?=	../../wip/py-errorhandler
.endif	# PY_ERRORHANDLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-errorhandler
