# $NetBSD$

BUILDLINK_TREE+=	libxml++3

.if !defined(LIBXML++3_BUILDLINK3_MK)
LIBXML++3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxml++3+=	libxml++3>=3.0.1
BUILDLINK_PKGSRCDIR.libxml++3?=		../../wip/libxml++3

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/glibmm/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBXML++3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxml++3
