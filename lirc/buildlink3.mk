# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:49 jsonn Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.lirc?=	build

BUILDLINK_TREE+=	lirc

BUILDLINK_API_DEPENDS.lirc+=	lirc>=0.8.0
BUILDLINK_PKGSRCDIR.lirc?=	../../wip/lirc
.endif # LIRC_BUILDLINK3_MK

BUILDLINK_TREE+=	-lirc
