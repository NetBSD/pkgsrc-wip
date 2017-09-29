# $NetBSD$

BUILDLINK_TREE+=	gl2ps

.if !defined(GL2PS_BUILDLINK3_MK)
GL2PS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gl2ps+=	gl2ps>=1.4.0
BUILDLINK_PKGSRCDIR.gl2ps?=	../../wip/gl2ps

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.endif	# GL2PS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gl2ps
