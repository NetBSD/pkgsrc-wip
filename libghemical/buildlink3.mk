# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/06/03 13:14:55 jihbed Exp $

BUILDLINK_TREE+=	libghemical

.if !defined(LIBGHEMICAL_BUILDLINK3_MK)
LIBGHEMICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libghemical+=	libghemical>=2.99.1
BUILDLINK_PKGSRCDIR.libghemical?=	../../wip/libghemical

.include "../../graphics/glut/buildlink3.mk"
.endif	# LIBGHEMICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libghemical
