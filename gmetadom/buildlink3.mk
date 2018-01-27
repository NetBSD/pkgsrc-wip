# $NetBSD: buildlink3.mk,v 1.1 2014/12/26 15:39:45 nros Exp $
#

BUILDLINK_TREE+=	gmetadom

.if !defined(GMETADOM_BUILDLINK3_MK)
GMETADOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmetadom+=	gmetadom>=0.2.6
BUILDLINK_PKGSRCDIR.gmetadom?=		../../wip/gmetadom

.include "../../textproc/gdome2/buildlink3.mk"
.endif	# GMETADOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmetadom
