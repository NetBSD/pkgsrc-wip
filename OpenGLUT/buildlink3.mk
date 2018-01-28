# $NetBSD: buildlink3.mk,v 1.6 2009/05/06 10:47:32 cheusov Exp $

BUILDLINK_TREE+=	OpenGLUT

.if !defined(OPENGLUT_BUILDLINK3_MK)
OPENGLUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.OpenGLUT+=	OpenGLUT>=0.6.0
BUILDLINK_PKGSRCDIR.OpenGLUT?=		../../wip/OpenGLUT

MESA_REQD+=	6.0

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.endif # OPENGLUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-OpenGLUT
