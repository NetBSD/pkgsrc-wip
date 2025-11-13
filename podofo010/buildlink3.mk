# $NetBSD: buildlink3.mk,v 1.15 2025/08/30 22:46:11 wiz Exp $

BUILDLINK_TREE+=	podofo

.if !defined(PODOFO_BUILDLINK3_MK)
PODOFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.podofo+=	podofo>=0.10.5<1.0
BUILDLINK_PKGSRCDIR.podofo?=	../../wip/podofo010

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# PODOFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-podofo
