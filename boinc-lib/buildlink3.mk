# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	boinc-lib

BUILDLINK_API_DEPENDS.boinc-lib+=	boinc-lib>=1
BUILDLINK_PKGSRCDIR.boinc-lib?=	../../wip/boinc-lib

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../www/curl/buildlink3.mk"
#.include "../../security/openssl/buildlink3.mk"
.endif # BOINC_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-boinc-lib
