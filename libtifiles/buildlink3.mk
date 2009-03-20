# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:48 jsonn Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libtifiles?=	build

BUILDLINK_TREE+=	libtifiles

BUILDLINK_API_DEPENDS.libtifiles+=	libtifiles>=0.5.6
BUILDLINK_PKGSRCDIR.libtifiles?=	../../wip/libtifiles
.endif # LIBTIFILES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtifiles
