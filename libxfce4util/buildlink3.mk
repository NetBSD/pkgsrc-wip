# $NetBSD: buildlink3.mk,v 1.5 2007/01/23 08:00:34 marttikuparinen Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFCE4UTIL_BUILDLINK3_MK:=	${LIBXFCE4UTIL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libxfce4util
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxfce4util}
BUILDLINK_PACKAGES+=	libxfce4util
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxfce4util

.if ${LIBXFCE4UTIL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libxfce4util+=	libxfce4util>=4.4.0
BUILDLINK_PKGSRCDIR.libxfce4util?=	../../wip/libxfce4util
.endif	# LIBXFCE4UTIL_BUILDLINK3_MK

.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
