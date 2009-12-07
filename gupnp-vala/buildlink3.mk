# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/12/07 15:08:38 jihbed Exp $

BUILDLINK_TREE+=	gupnp-vala

.if !defined(GUPNP_VALA_BUILDLINK3_MK)
GUPNP_VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-vala+=	gupnp-vala>=0.5.4
BUILDLINK_PKGSRCDIR.gupnp-vala?=	../../wip/gupnp-vala


.include "../../lang/vala/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../net/gupnp-av/buildlink3.mk"
.include "../../net/gssdp/buildlink3.mk"
.include "../../wip/gupnp-ui/buildlink3.mk"
.endif	# GUPNP_VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-vala
