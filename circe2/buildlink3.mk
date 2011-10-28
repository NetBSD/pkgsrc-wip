# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/28 17:51:07 jihbed Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.circe2?=	build

BUILDLINK_TREE+=	circe2

.if !defined(CIRCE2_BUILDLINK3_MK)
CIRCE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.circe2+=	circe2>=2.0.5
BUILDLINK_PKGSRCDIR.circe2?=	../../category/circe2

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../lang/ocaml/buildlink3.mk"
.endif	# CIRCE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-circe2
