# $NetBSD: buildlink3.mk,v 1.5 2010/01/17 12:03:23 thomasklausner Exp $

BUILDLINK_TREE+=	boinc-lib

.if !defined(BOINC_LIB_BUILDLINK3_MK)
BOINC_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boinc-lib+=	boinc-lib>=1
BUILDLINK_ABI_DEPENDS.boinc-lib?=	boinc-lib>=1nb1
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
