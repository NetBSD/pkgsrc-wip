# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/03/09 13:12:33 mpasternak Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XMMS_BUILDLINK3_MK:=	${XMMS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xmms
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxmms}
BUILDLINK_PACKAGES+=	xmms

.if !empty(XMMS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xmms+=	xmms>=1.2.10
BUILDLINK_PKGSRCDIR.xmms?=	../../wip/xmms-wip

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.endif	# XMMS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
