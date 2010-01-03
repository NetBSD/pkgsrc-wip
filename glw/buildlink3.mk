# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/01/03 14:38:27 pallegra Exp $

BUILDLINK_TREE+=	glw

.if !defined(GLW_BUILDLINK3_MK)
GLW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glw+=	glw>=7.7
BUILDLINK_PKGSRCDIR.glw?=	../../wip/glw

.include "../../wip/gl/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif	# GLW_BUILDLINK3_MK

BUILDLINK_TREE+=	-glw
