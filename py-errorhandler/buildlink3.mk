# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/08/31 18:57:49 helgoman Exp $

BUILDLINK_TREE+=	py26-errorhandler

.if !defined(PY26_ERRORHANDLER_BUILDLINK3_MK)
PY26_ERRORHANDLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-errorhandler+=	py26-errorhandler>=1.1.1
BUILDLINK_PKGSRCDIR.py26-errorhandler?=	../../wip/py-errorhandler
.endif	# PY26_ERRORHANDLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-errorhandler
