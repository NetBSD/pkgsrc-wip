# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/11/11 15:10:06 poppnk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBBTCTL_BUILDLINK3_MK:=	${LIBBTCTL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libbtctl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibbtctl}
BUILDLINK_PACKAGES+=	libbtctl

.if !empty(LIBBTCTL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libbtctl+=	libbtctl>=0.4.1
BUILDLINK_PKGSRCDIR.libbtctl?=	../../wip/libbtctl
.endif	# LIBBTCTL_BUILDLINK3_MK

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
