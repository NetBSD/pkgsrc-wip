# $NetBSD: buildlink3.mk,v 1.1 2004/03/06 15:39:40 mpasternak Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XBASE_BUILDLINK3_MK:=	${XBASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xbase
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxbase}
BUILDLINK_PACKAGES+=	xbase

.if !empty(XBASE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xbase+=	xbase>=2.0.0
BUILDLINK_PKGSRCDIR.xbase?=	../../wip/xbase

.endif	# XBASE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
