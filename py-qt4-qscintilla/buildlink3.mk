# $NetBSD: buildlink3.mk,v 1.3 2010/06/13 22:47:14 thomasklausner Exp $

BUILDLINK_TREE+=	py26-qt4-qscintilla

.if !defined(PY26_QT4_QSCINTILLA_BUILDLINK3_MK)
PY26_QT4_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-qt4-qscintilla+=	${PYPKGPREFIX}-qt4-qscintilla>=2.4.3nb1
BUILDLINK_ABI_DEPENDS.py26-qt4-qscintilla?=	${PYPKGPREFIX}-qt4-qscintilla>=2.4.3nb3
BUILDLINK_PKGSRCDIR.py26-qt4-qscintilla?=	../../wip/py-qt4-qscintilla

.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../wip/qt4-qscintilla/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# PY26_QT4_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-qt4-qscintilla
