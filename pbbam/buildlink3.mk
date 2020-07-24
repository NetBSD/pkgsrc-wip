# $NetBSD$

BUILDLINK_TREE+=	pbbam

.if !defined(PBBAM_BUILDLINK3_MK)
PBBAM_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.pbbam?=	build

BUILDLINK_API_DEPENDS.pbbam+=	pbbam>=2016.09.13
BUILDLINK_PKGSRCDIR.pbbam?=	../../wip/pbbam

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../biology/htslib/buildlink3.mk"
#.include "../../security/openssl/buildlink3.mk"
.endif	# PBBAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-pbbam
