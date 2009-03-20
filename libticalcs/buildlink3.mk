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
# XXX	BUILDLINK_DEPMETHOD.libticalcs?=	build

BUILDLINK_TREE+=	libticalcs

BUILDLINK_API_DEPENDS.libticalcs+=	libticalcs>=4.4.9
BUILDLINK_PKGSRCDIR.libticalcs?=	../../wip/libticalcs
.endif # LIBTICALCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticalcs
