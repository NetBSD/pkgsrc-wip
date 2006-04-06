# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:14 jeremy-c-reed Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.confuse?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CONFUSE_BUILDLINK3_MK:=	${CONFUSE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	confuse
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nconfuse}
BUILDLINK_PACKAGES+=	confuse

.if !empty(CONFUSE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.confuse+=	confuse>=2.5
BUILDLINK_PKGSRCDIR.confuse?=	../../wip/confuse
.endif	# CONFUSE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
