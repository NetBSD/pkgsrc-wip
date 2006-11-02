# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/02 11:23:02 jsonn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXCOMPOSITE_BUILDLINK3_MK:=	${LIBXCOMPOSITE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXcomposite
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXcomposite}
BUILDLINK_PACKAGES+=	libXcomposite
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXcomposite

.if ${LIBXCOMPOSITE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXcomposite+=	libXcomposite>=0.3.1
BUILDLINK_PKGSRCDIR.libXcomposite?=	../../wip/libXcomposite
.endif	# LIBXCOMPOSITE_BUILDLINK3_MK

.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXfixes/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
