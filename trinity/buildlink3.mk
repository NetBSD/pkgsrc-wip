# $NetBSD: buildlink3.mk,v 1.1 2015/01/28 16:44:31 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.trinity?=	build

BUILDLINK_TREE+=	trinity

.if !defined(TRINITY_BUILDLINK3_MK)
TRINITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.trinity+=	trinity>=2014.04.13
BUILDLINK_PKGSRCDIR.trinity?=	../../wip/trinity
.endif	# TRINITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-trinity
