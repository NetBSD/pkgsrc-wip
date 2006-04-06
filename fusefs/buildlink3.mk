# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:29 jeremy-c-reed Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.9.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.fusefs?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FUSEFS_BUILDLINK3_MK:=	${FUSEFS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fusefs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfusefs}
BUILDLINK_PACKAGES+=	fusefs

.if !empty(FUSEFS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.fusefs+=	fusefs>=2.5.2
BUILDLINK_PKGSRCDIR.fusefs?=	../../wip/fusefs
.endif	# FUSEFS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
