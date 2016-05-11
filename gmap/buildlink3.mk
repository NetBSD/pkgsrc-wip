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
# XXX	BUILDLINK_DEPMETHOD.gmap?=	build

BUILDLINK_TREE+=	gmap

.if !defined(GMAP_BUILDLINK3_MK)
GMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmap+=	gmap>=2014.07.04
BUILDLINK_PKGSRCDIR.gmap?=	../../wip/gmap
.endif	# GMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmap
