# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/27 16:40:14 outpaddling Exp $

BUILDLINK_TREE+=	metis

.if !defined(METIS_BUILDLINK3_MK)
METIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.metis+=	metis>=4.0
BUILDLINK_PKGSRCDIR.metis?=	../../math/metis
.endif	# METIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-metis
