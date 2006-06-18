# $NetBSD: buildlink3.mk,v 1.1.1.2 2006/06/18 16:46:05 rumko Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BOINC_CLIENT_BUILDLINK3_MK:=	${BOINC_CLIENT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	boinc-client
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nboinc-client}
BUILDLINK_PACKAGES+=	boinc-client

.if ${BOINC_CLIENT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.boinc-client+=	boinc-client>=1
BUILDLINK_PKGSRCDIR.boinc-client?=	../../wip/boinc-client
.endif	# BOINC_CLIENT_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../www/curl/buildlink3.mk"
#.include "../../security/openssl/buildlink3.mk"
#.include "../../net/boinc-lib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
