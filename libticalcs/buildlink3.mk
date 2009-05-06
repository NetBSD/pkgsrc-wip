# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:26:23 cheusov Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libticalcs?=	build

BUILDLINK_TREE+=	libticalcs

.if !defined(LIBTICALCS_BUILDLINK3_MK)
LIBTICALCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libticalcs+=	libticalcs>=4.4.9
BUILDLINK_PKGSRCDIR.libticalcs?=	../../wip/libticalcs
.endif # LIBTICALCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticalcs
