# $NetBSD: buildlink3.mk,v 1.1 2004/05/12 12:39:45 thomasklausner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBUUID_BUILDLINK3_MK:=	${LIBUUID_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libuuid
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibuuid}
BUILDLINK_PACKAGES+=	libuuid

.if !empty(LIBUUID_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libuuid+=	libuuid>=1.35
BUILDLINK_PKGSRCDIR.libuuid?=	../../wip/libuuid
.endif	# LIBUUID_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
