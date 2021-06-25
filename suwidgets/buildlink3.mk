# $NetBSD$

BUILDLINK_TREE+=	SuWidgets

.if !defined(SUWIDGETS_BUILDLINK3_MK)
SUWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SuWidgets+=	SuWidgets>=0.1.0
BUILDLINK_PKGSRCDIR.SuWidgets?=		../../wip/suwidgets

.include "../../wip/sigutils/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SUWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-SuWidgets
