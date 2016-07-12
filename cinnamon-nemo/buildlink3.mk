# $NetBSD$

BUILDLINK_TREE+=	cinnamon-nemo

.if !defined(CINNAMON_NEMO_BUILDLINK3_MK)
CINNAMON_NEMO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cinnamon-nemo+=	cinnamon-nemo>=3.0.6
BUILDLINK_PKGSRCDIR.cinnamon-nemo?=	../../wip/cinnamon-nemo

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/cinnamon-desktop/buildlink3.mk"
.endif	# CINNAMON_NEMO_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-nemo
