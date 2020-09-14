# $NetBSD: buildlink3.mk,v 1.1 2011/01/04 15:42:46 silasdb Exp $

BUILDLINK_TREE+=	soqt

.if !defined(SOQT_BUILDLINK3_MK)
SOQT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.soqt+=	soqt>=1.4.1
BUILDLINK_PKGSRCDIR.soqt?=	../../wip/soqt

.include "../../graphics/Coin/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# SOQT_BUILDLINK3_MK

BUILDLINK_TREE+=	-soqt
