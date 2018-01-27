# $NetBSD$

BUILDLINK_TREE+=	pbcopper

.if !defined(PBCOPPER_BUILDLINK3_MK)
PBCOPPER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.pbcopper?=	build

BUILDLINK_API_DEPENDS.pbcopper+=	pbcopper>=2016.09.13
BUILDLINK_PKGSRCDIR.pbcopper?=		../../wip/pbcopper

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/boost-libs/buildlink3.mk"
.endif	# PBCOPPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-pbcopper
