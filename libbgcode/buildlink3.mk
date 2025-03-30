# $NetBSD$

BUILDLINK_TREE+=	libbgcode

.if !defined(LIBBGCODE_BUILDLINK3_MK)
LIBBGCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbgcode+=	libbgcode>=20231123
BUILDLINK_PKGSRCDIR.libbgcode?=		../../wip/libbgcode
BUILDLINK_FILES.libbgcode+=		bin/bgcode

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/heatshrink/buildlink3.mk"
.endif	# LIBBGCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbgcode
