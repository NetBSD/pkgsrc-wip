# $NetBSD: buildlink3.mk,v 1.1 2012/09/15 23:45:17 jihbed Exp $

BUILDLINK_TREE+=	libpsurface

.if !defined(LIBPSURFACE_BUILDLINK3_MK)
LIBPSURFACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpsurface+=	libpsurface>=1.3.1
BUILDLINK_PKGSRCDIR.libpsurface?=	../../wip/libpsurface
.endif	# LIBPSURFACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpsurface
