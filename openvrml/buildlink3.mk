# $NetBSD: buildlink3.mk,v 1.1 2004/07/27 22:17:50 thomasklausner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENVRML_BUILDLINK3_MK:=	${OPENVRML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openvrml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenvrml}
BUILDLINK_PACKAGES+=	openvrml

.if !empty(OPENVRML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.openvrml+=	openvrml>=0.14.3
BUILDLINK_PKGSRCDIR.openvrml?=	../../wip/openvrml
.endif	# OPENVRML_BUILDLINK3_MK

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
