# $NetBSD: buildlink3.mk,v 1.1 2015/02/19 21:21:12 jihbed Exp $

BUILDLINK_TREE+=	cinnamon-control-center

.if !defined(CINNAMON_CONTROL_CENTER_BUILDLINK3_MK)
CINNAMON_CONTROL_CENTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cinnamon-control-center+=	cinnamon-control-center>=2.2.0
BUILDLINK_PKGSRCDIR.cinnamon-control-center?=	../../wip/cinnamon-control-center

.include "../../devel/glib2/buildlink3.mk"
.endif	# CINNAMON_CONTROL_CENTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-control-center
