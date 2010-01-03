# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/01/03 15:11:39 pallegra Exp $

BUILDLINK_TREE+=	glu

.if !defined(GLU_BUILDLINK3_MK)
GLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glu+=	glu>=7.7
BUILDLINK_PKGSRCDIR.glu?=	../../wip/glu

.include "../../wip/gl/buildlink3.mk"
.endif	# GLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-glu
