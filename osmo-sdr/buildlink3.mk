# $NetBSD: buildlink3.mk,v 1.1 2014/10/03 06:45:35 makoto Exp $

BUILDLINK_TREE+=	osmo-sdr

.if !defined(OSMO_SDR_BUILDLINK3_MK)
OSMO_SDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.osmo-sdr+=	osmo-sdr>=0.1
BUILDLINK_ABI_DEPENDS.osmo-sdr+=	osmo-sdr>=0.1
BUILDLINK_PKGSRCDIR.osmo-sdr?=		../../wip/osmo-sdr
.endif # OSMO_SDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-osmo-sdr
