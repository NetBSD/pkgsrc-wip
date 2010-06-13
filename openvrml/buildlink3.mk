# $NetBSD: buildlink3.mk,v 1.7 2010/06/13 22:47:12 thomasklausner Exp $

BUILDLINK_TREE+=	openvrml

.if !defined(OPENVRML_BUILDLINK3_MK)
OPENVRML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openvrml+=	openvrml>=0.14.3
BUILDLINK_ABI_DEPENDS.openvrml?=	openvrml>=0.14.3nb2
BUILDLINK_PKGSRCDIR.openvrml?=	../../wip/openvrml

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.endif # OPENVRML_BUILDLINK3_MK

BUILDLINK_TREE+=	-openvrml
