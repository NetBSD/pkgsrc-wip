# $NetBSD: buildlink3.mk,v 1.2 2004/06/09 23:34:18 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GD_NOX11_BUILDLINK3_MK:=	${GD_NOX11_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gd-nox11
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngd-nox11}
BUILDLINK_PACKAGES+=	gd-nox11

.if !empty(GD_NOX11_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gd-nox11+=	gd-nox11>=2.0.25
BUILDLINK_PKGSRCDIR.gd-nox11?=	../../wip/gd-nox11
.endif	# GD_NOX11_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
