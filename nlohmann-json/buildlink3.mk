# $NetBSD$

BUILDLINK_TREE+=	nlohmann-json

.if !defined(NLOHMANN_JSON_BUILDLINK3_MK)
NLOHMANN_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nlohmann-json+=	nlohmann-json>=3.7.0
BUILDLINK_DEPMETHOD.nlohmann-json?=	build
BUILDLINK_PKGSRCDIR.nlohmann-json?=	../../wip/nlohmann-json
.endif	# NLOHMANN_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-nlohmann-json
