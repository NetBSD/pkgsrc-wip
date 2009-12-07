# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/12/07 14:53:35 jihbed Exp $

BUILDLINK_TREE+=	gupnp-ui

.if !defined(GUPNP_UI_BUILDLINK3_MK)
GUPNP_UI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-ui+=	gupnp-ui>=0.1.1
BUILDLINK_PKGSRCDIR.gupnp-ui?=	../../wip/gupnp-ui


.include "../../net/gupnp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gupnp-ui
