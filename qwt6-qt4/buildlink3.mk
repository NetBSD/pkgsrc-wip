# $NetBSD: buildlink3.mk,v 1.20 2023/11/12 13:24:29 wiz Exp $

BUILDLINK_TREE+=	qwt6-qt4

.if !defined(QWT6_QT4_BUILDLINK3_MK)
QWT6_QT4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt6-qt4+=	qwt6-qt4>=6.0.1
BUILDLINK_ABI_DEPENDS.qwt6-qt4+=	qwt6-qt4>=6.0.1
BUILDLINK_PKGSRCDIR.qwt6-qt4?=		../../wip/qwt6-qt4

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QWT6_QT4_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt6-qt4
