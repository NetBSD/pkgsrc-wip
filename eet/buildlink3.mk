# $NetBSD: buildlink3.mk,v 1.7 2012/12/30 19:27:17 roelants Exp $

BUILDLINK_TREE+=	eet

.if !defined(EET_BUILDLINK3_MK)
EET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eet+=	eet>=1.7.0
BUILDLINK_PKGSRCDIR.eet?=	../../wip/eet

.include "../../wip/eina/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # EET_BUILDLINK3_MK

BUILDLINK_TREE+=	-eet
