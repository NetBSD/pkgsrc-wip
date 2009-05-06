# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:25:37 cheusov Exp $
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

.if !defined(LIBTIFILES_BUILDLINK3_MK)
LIBTIFILES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtifiles+=	libtifiles>=0.5.6
BUILDLINK_PKGSRCDIR.libtifiles?=	../../wip/libtifiles
.endif # LIBTIFILES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtifiles
