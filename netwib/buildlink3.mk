# $NetBSD: buildlink3.mk,v 1.4 2008/03/17 00:14:46 tnn2 Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NETWIB_BUILDLINK3_MK:=	${NETWIB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	netwib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnetwib}
BUILDLINK_PACKAGES+=	netwib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}netwib

.if ${NETWIB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.netwib+=	netwib>=5.35.0
BUILDLINK_PKGSRCDIR.netwib?=	../../wip/netwib
.endif	# NETWIB_BUILDLINK3_MK

.include "../../devel/libnet10/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
