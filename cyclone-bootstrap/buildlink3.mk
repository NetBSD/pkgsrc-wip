# $NetBSD$

BUILDLINK_TREE+=	cyclone-bootstrap

.if !defined(CYCLONE_BOOTSTRAP_BUILDLINK3_MK)
CYCLONE_BOOTSTRAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cyclone-bootstrap+=	cyclone-bootstrap>=0.36.0
BUILDLINK_PKGSRCDIR.cyclone-bootstrap?=		../../wip/cyclone-bootstrap

# cyclone links programs against libck and libtommath
.include "../../devel/concurrencykit/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.endif	# CYCLONE_BOOTSTRAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-cyclone-bootstrap
