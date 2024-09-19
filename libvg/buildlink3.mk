# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:47:32 cheusov Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.7.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libvg?=	build

BUILDLINK_TREE+=	libvg

.if !defined(LIBVG_BUILDLINK3_MK)
LIBVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvg+=	libvg>=0.2.0
BUILDLINK_PKGSRCDIR.libvg?=	../../wip/libvg
.endif # LIBVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvg
