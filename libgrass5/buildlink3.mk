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
# XXX	BUILDLINK_DEPMETHOD.libgrass5?=	build

BUILDLINK_TREE+=	libgrass5

BUILDLINK_API_DEPENDS.libgrass5+=	libgrass5>=1.0.0
BUILDLINK_PKGSRCDIR.libgrass5?=	../../wip/libgrass5
.endif # LIBGRASS5_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgrass5
