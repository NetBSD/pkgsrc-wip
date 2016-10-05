# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.flite?=	build

BUILDLINK_TREE+=	flite

.if !defined(FLITE_BUILDLINK3_MK)
FLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flite+=	flite>=2.0.0
BUILDLINK_PKGSRCDIR.flite?=	../../audio/flite
.endif	# FLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-flite
