# $NetBSD: buildlink3.mk,v 1.3 2013/01/06 14:13:27 ryo-on Exp $

BUILDLINK_TREE+=	irrlicht

.if !defined(IRRLICHT_BUILDLINK3_MK)
IRRLICHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.irrlicht+=	irrlicht>=1.8
BUILDLINK_PKGSRCDIR.irrlicht?=		../../wip/irrlicht

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif	# IRRLICHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-irrlicht
