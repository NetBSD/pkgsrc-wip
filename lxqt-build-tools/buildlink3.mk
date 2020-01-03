# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.17.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.lxqt-build-tools?=	build

BUILDLINK_TREE+=	lxqt-build-tools

.if !defined(LXQT_BUILD_TOOLS_BUILDLINK3_MK)
LXQT_BUILD_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lxqt-build-tools+=	lxqt-build-tools>=0.6.0
BUILDLINK_PKGSRCDIR.lxqt-build-tools?=	../../wip/lxqt-build-tools

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LXQT_BUILD_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-lxqt-build-tools
