# $NetBSD: buidlink3.mk,v 1.1 2014/09/25 02:52:20 makoto Exp $

BUILDLINK_TREE+=        py-qwt-qt4

.if !defined(PY_QWT_QT4_BUILDLINK3_MK)
PY_QWT_QT4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-qwt-qt4+=   py-qwt-qt4>=5.2.0
BUILDLINK_ABI_DEPENDS.py-qwt-qt4+=   py-qwt-qt4>=5.2.0
BUILDLINK_PKGSRCDIR.py-qwt-qt4?=     ../../wip/py-qwt-qt4
.endif # PY_QWT_QT4_BUILDLINK3_MKx

BUILDLINK_TREE+=        -py-qwt-qt4
