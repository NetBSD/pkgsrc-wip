# $NetBSD: buildlink3.mk,v 1.2 2015/09/06 14:31:49 slitvinov Exp $

BUILDLINK_TREE+=	gts

.if !defined(GTS_BUILDLINK3_MK)
GTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gts+=	gts>=0.7.6
BUILDLINK_PKGSRCDIR.gts?=	../../wip/gts-snapshot

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.endif	# GTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gts
