# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/10/05 12:43:53 ryo-on Exp $

BUILDLINK_TREE+=	gupnp-dlna

.if !defined(GUPNP_DLNA_BUILDLINK3_MK)
GUPNP_DLNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-dlna+=	gupnp-dlna>=0.4.0
BUILDLINK_PKGSRCDIR.gupnp-dlna?=	../../wip/gupnp-dlna

.include "../../net/gupnp/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
#.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.endif	# GUPNP_DLNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-dlna
