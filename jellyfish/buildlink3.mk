# $NetBSD: buildlink3.mk,v 1.1 2015/01/28 16:36:28 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.jellyfish?=	build

BUILDLINK_TREE+=	jellyfish

.if !defined(JELLYFISH_BUILDLINK3_MK)
JELLYFISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jellyfish+=	jellyfish>=1.1.11
BUILDLINK_PKGSRCDIR.jellyfish?=	../../wip/jellyfish
.endif	# JELLYFISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-jellyfish
