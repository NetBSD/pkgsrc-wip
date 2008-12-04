# $NetBSD: buildlink3.mk,v 1.2 2008/12/04 13:19:07 thomasklausner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AVAHI_BUILDLINK3_MK:=	${AVAHI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	avahi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Navahi}
BUILDLINK_PACKAGES+=	avahi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}avahi

.if ${AVAHI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.avahi+=	avahi>=0.6.23
BUILDLINK_PKGSRCDIR.avahi?=	../../wip/avahi
.endif	# AVAHI_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
