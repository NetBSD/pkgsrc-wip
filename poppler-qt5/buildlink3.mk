# $NetBSD: buildlink3.mk,v 1.1 2014/01/04 18:52:27 nros Exp $

BUILDLINK_TREE+=	poppler-qt5

.if !defined(POPPLER_QT5_BUILDLINK3_MK)
POPPLER_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-qt5+=	poppler-qt5>=0.24.4
BUILDLINK_ABI_DEPENDS.poppler-qt5+=	poppler-qt5>=0.24.4
BUILDLINK_PKGSRCDIR.poppler-qt5?=	../../wip/poppler-qt5

.include "../../print/poppler/buildlink3.mk"
.endif # POPPLER_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-qt5
