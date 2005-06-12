# $NetBSD: buildlink3.mk,v 1.2 2005/06/12 23:51:16 kristerw Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DIRECTFB_BUILDLINK3_MK:=	${DIRECTFB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	DirectFB
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NDirectFB}
BUILDLINK_PACKAGES+=	DirectFB

.if !empty(DIRECTFB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.DirectFB+=	DirectFB>=0.9.17
BUILDLINK_PKGSRCDIR.DirectFB?=	../../wip/directfb
.endif	# DIRECTFB_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
