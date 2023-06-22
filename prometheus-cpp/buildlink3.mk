# $NetBSD$

BUILDLINK_TREE+=	prometheus-cpp

.if !defined(PROMETHEUS_CPP_BUILDLINK3_MK)
PROMETHEUS_CPP_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.prometheus-cpp?=	build

BUILDLINK_API_DEPENDS.prometheus-cpp+=	prometheus-cpp>=1.1.0
BUILDLINK_PKGSRCDIR.prometheus-cpp?=	../../wip/prometheus-cpp

.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# PROMETHEUS_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-prometheus-cpp
