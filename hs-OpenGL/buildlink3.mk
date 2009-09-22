# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/22 14:09:27 phonohawk Exp $

BUILDLINK_TREE+=	hs-OpenGL

.if !defined(HS_OPENGL_BUILDLINK3_MK)
HS_OPENGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-OpenGL+=	hs-OpenGL>=2.4.0.1
BUILDLINK_PKGSRCDIR.hs-OpenGL?=	../../wip/hs-OpenGL

.include "../../wip/hs-GLURaw/buildlink3.mk"
.include "../../wip/hs-ObjectName/buildlink3.mk"
.include "../../wip/hs-OpenGLRaw/buildlink3.mk"
.include "../../wip/hs-StateVar/buildlink3.mk"
.include "../../wip/hs-Tensor/buildlink3.mk"
.endif	# HS_OPENGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-OpenGL
