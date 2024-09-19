# $NetBSD: buildlink3.mk,v 1.1 2015/09/06 14:35:45 slitvinov Exp $

BUILDLINK_TREE+=	gerris

.if !defined(GERRIS_BUILDLINK3_MK)
GERRIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gerris+=	gerris>=0.9.2.131206
BUILDLINK_PKGSRCDIR.gerris?=	../../wip/gerris-snapshot

.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../wip/gts-snapshot/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# GERRIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gerris
