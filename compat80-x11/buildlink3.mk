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
# XXX	BUILDLINK_DEPMETHOD.compat80-x11-i386?=	build

BUILDLINK_TREE+=	compat80-x11-i386

.if !defined(COMPAT80_X11_I386_BUILDLINK3_MK)
COMPAT80_X11_I386_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat80-x11-i386+=	compat80-x11-i386>=8.0
BUILDLINK_PKGSRCDIR.compat80-x11-i386?=		../../wip/compat80-x11
BUILDLINK_LIBDIRS.compat80-x11-i386=		emul/netbsd32/lib
.endif	# COMPAT80_X11_I386_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat80-x11-i386
