# $NetBSD: buildlink3.mk,v 1.1 2006/11/29 04:12:25 kcf Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.12.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.xspd?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XSPD_BUILDLINK3_MK:=	${XSPD_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xspd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxspd}
BUILDLINK_PACKAGES+=	xspd

.if ${XSPD_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xspd+=	xspd>=6.3.1
BUILDLINK_PKGSRCDIR.xspd?=	../../www/xspd
.endif	# XSPD_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
