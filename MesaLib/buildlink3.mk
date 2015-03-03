# $NetBSD: buildlink3.mk,v 1.12 2015/03/03 21:14:20 tnn2 Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.MesaLib?=	build

BUILDLINK_TREE+=	MesaLib

.if !defined(MESALIB_BUILDLINK3_MK)
MESALIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=10.5.0rc3
BUILDLINK_PKGSRCDIR.MesaLib?=	../../wip/MesaLib

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../lang/clang/buildlink3.mk"
#.include "../../sysutils/libpciaccess/buildlink3.mk"
#.include "../../x11/dri2proto/buildlink3.mk"
#.include "../../x11/glproto/buildlink3.mk"
#.include "../../x11/libXdamage/buildlink3.mk"
#.include "../../x11/libXfixes/buildlink3.mk"
#.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
#.include "../../x11/libxcb/buildlink3.mk"
#.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.endif	# MESALIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-MesaLib
