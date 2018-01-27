# $NetBSD: buildlink3.mk,v 1.3 2010/06/13 22:47:07 thomasklausner Exp $

BUILDLINK_TREE+=	gupnp-ui

.if !defined(GUPNP_UI_BUILDLINK3_MK)
GUPNP_UI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-ui+=	gupnp-ui>=0.1.1
BUILDLINK_ABI_DEPENDS.gupnp-ui?=	gupnp-ui>=0.1.1nb2
BUILDLINK_PKGSRCDIR.gupnp-ui?=		../../wip/gupnp-ui


.include "../../net/gupnp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gupnp-ui
