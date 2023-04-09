# $NetBSD: buildlink3.mk,v 1.37 2022/06/28 11:34:08 wiz Exp $

BUILDLINK_TREE+=	gnuradio-monolithic

.if !defined(GNURADIO_MONOLITHIC_BUILDLINK3_MK)
GNURADIO_MONOLITHIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-monolithic+=	gnuradio-core>=3.10.2
BUILDLINK_ABI_DEPENDS.gnuradio-monolithic?=	gnuradio-core>=3.10.2.0nb1
BUILDLINK_PKGSRCDIR.gnuradio-monolithic?=	../../wip/gnuradio-monolithic

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.endif # GNURADIO_MONOLITHIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-monolithic
