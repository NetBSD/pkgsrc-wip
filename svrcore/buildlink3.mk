# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/19 16:49:23 udontknow Exp $

BUILDLINK_TREE+=	svrcore

.if !defined(SVRCORE_BUILDLINK3_MK)
SVRCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.svrcore+=	svrcore>=4.0.4
BUILDLINK_PKGSRCDIR.svrcore?=	../../wip/svrcore

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/nspr/buildlink3.mk"
#.include "../../devel/nss/buildlink3.mk"
.endif	# SVRCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-svrcore
