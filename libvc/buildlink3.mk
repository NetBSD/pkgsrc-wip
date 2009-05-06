# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:10:21 cheusov Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libvc?=	build

BUILDLINK_TREE+=	libvc

.if !defined(LIBVC_BUILDLINK3_MK)
LIBVC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvc+=	libvc>=003
BUILDLINK_PKGSRCDIR.libvc?=	../../wip/libvc
.endif # LIBVC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvc
