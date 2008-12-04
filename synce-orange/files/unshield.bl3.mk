# $NetBSD: unshield.bl3.mk,v 1.1.1.1 2008/12/04 23:08:21 shattered Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.unshield?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
UNSHIELD_BUILDLINK3_MK:=	${UNSHIELD_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	unshield
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nunshield}
BUILDLINK_PACKAGES+=	unshield
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}unshield

.if ${UNSHIELD_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.unshield+=	unshield>=0.5
BUILDLINK_PKGSRCDIR.unshield?=	../../archivers/unshield
.endif	# UNSHIELD_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
