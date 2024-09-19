# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/06 10:53:44 grasmi Exp $

BUILDLINK_TREE+=	libnfo

.if !defined(LIBNFO_BUILDLINK3_MK)
LIBNFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnfo+=	libnfo>=1.0.0
BUILDLINK_PKGSRCDIR.libnfo?=	../../wip/libnfo

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBNFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnfo
