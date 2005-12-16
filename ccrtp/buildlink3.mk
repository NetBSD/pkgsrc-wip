# $NetBSD: buildlink3.mk,v 1.1 2005/12/16 18:49:36 poppnk Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.ccrtp?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CCRTP_BUILDLINK3_MK:=	${CCRTP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ccrtp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nccrtp}
BUILDLINK_PACKAGES+=	ccrtp

.if !empty(CCRTP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ccrtp+=	ccrtp>=1.3.5
BUILDLINK_PKGSRCDIR.ccrtp?=	../../wip/ccrtp
.endif	# CCRTP_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../wip/commoncpp2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
