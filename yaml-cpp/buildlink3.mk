# $NetBSD: buildlink3.mk,v 1.1 2013/08/19 19:30:55 airhead Exp $

BUILDLINK_TREE+=	yaml-cpp

.if !defined(YAML_CPP_BUILDLINK3_MK)
YAML_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yaml-cpp+=	yaml-cpp>=0.5.1
BUILDLINK_ABI_DEPENDS.yaml-cpp+=	yaml-cpp>=0.5.1
BUILDLINK_PKGSRCDIR.yaml-cpp?=	../../wip/yaml-cpp
.endif	# LIBYAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-yaml-cpp
