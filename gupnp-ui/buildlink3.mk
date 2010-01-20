# $NetBSD: buildlink3.mk,v 1.2 2010/01/20 14:04:59 thomasklausner Exp $

BUILDLINK_TREE+=	gupnp-ui

.if !defined(GUPNP_UI_BUILDLINK3_MK)
GUPNP_UI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-ui+=	gupnp-ui>=0.1.1
BUILDLINK_ABI_DEPENDS.gupnp-ui?=	gupnp-ui>=0.1.1nb1
BUILDLINK_PKGSRCDIR.gupnp-ui?=	../../wip/gupnp-ui


.include "../../net/gupnp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gupnp-ui
