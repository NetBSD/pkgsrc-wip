# $NetBSD: buildlink3.mk,v 1.3 2018/01/30 07:22:17 adam Exp $

BUILDLINK_TREE+=	yaml-cpp

.if !defined(YAML_CPP_BUILDLINK3_MK)
YAML_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yaml-cpp+=	yaml-cpp>=0.3.0
BUILDLINK_PKGSRCDIR.yaml-cpp?=		../../wip/yaml-cpp03

.endif	# YAML_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-yaml-cpp
