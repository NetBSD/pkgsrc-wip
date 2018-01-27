# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-OpenGL

.if !defined(HS_OPENGL_BUILDLINK3_MK)
HS_OPENGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-OpenGL+=	hs-OpenGL>=2.4.0
BUILDLINK_ABI_DEPENDS.hs-OpenGL+=	hs-OpenGL>=2.4.0.1
BUILDLINK_PKGSRCDIR.hs-OpenGL?=		../../wip/hs-OpenGL

.include "../../wip/hs-GLURaw/buildlink3.mk"
.include "../../wip/hs-ObjectName/buildlink3.mk"
.include "../../wip/hs-OpenGLRaw/buildlink3.mk"
.include "../../wip/hs-StateVar/buildlink3.mk"
.include "../../wip/hs-Tensor/buildlink3.mk"
.endif	# HS_OPENGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-OpenGL
