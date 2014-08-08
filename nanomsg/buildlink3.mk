# $NetBSD: buildlink3.mk,v 1.1 2014/08/08 11:56:44 chybz Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.nanomsg?=	build

BUILDLINK_TREE+=	nanomsg

.if !defined(NANOMSG_BUILDLINK3_MK)
NANOMSG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nanomsg+=	nanomsg>=0.4beta
BUILDLINK_PKGSRCDIR.nanomsg?=	../../devel/nanomsg
.endif	# NANOMSG_BUILDLINK3_MK

BUILDLINK_TREE+=	-nanomsg
