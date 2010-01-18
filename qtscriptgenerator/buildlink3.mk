# $NetBSD: buildlink3.mk,v 1.3 2010/01/18 09:38:31 thomasklausner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.15.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.qtscriptgenerator?=	build

BUILDLINK_TREE+=	qtscriptgenerator

.if !defined(QTSCRIPTGENERATOR_BUILDLINK3_MK)
QTSCRIPTGENERATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtscriptgenerator+=	qtscriptgenerator>=0.1.0
BUILDLINK_ABI_DEPENDS.qtscriptgenerator?=	qtscriptgenerator>=0.1.0nb2
BUILDLINK_PKGSRCDIR.qtscriptgenerator?=	../../wip/qtscriptgenerator

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../multimedia/phonon/buildlink3.mk"
#.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
#.include "../../x11/qt4-tools/buildlink3.mk"
.endif	# QTSCRIPTGENERATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtscriptgenerator
