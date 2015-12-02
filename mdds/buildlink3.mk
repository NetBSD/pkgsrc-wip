# $NetBSD$
BUILDLINK_TREE+=	mdds

.if !defined(MDDS_BUILDLINK3_MK)
MDDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mdds+=	mdds>=1.0.0
BUILDLINK_PKGSRCDIR.mdds?=	../../wip/mdds

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/boost-headers/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"
.endif	# MDDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds
