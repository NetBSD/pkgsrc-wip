# $NetBSD: buildlink3.mk,v 1.3 2005/06/12 23:51:13 kristerw Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENGLUT_BUILDLINK3_MK:=	${OPENGLUT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	OpenGLUT
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NOpenGLUT}
BUILDLINK_PACKAGES+=	OpenGLUT

.if !empty(OPENGLUT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.OpenGLUT+=	OpenGLUT>=0.6.0
BUILDLINK_PKGSRCDIR.OpenGLUT?=	../../wip/OpenGLUT
.endif	# OPENGLUT_BUILDLINK3_MK

MESA_REQD+=     6.0

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
