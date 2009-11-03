# $NetBSD: buildlink3.mk,v 1.3 2009/11/03 00:19:28 schnoebe Exp $

BUILDLINK_TREE+=	poco

.if !defined(POCO_BUILDLINK3_MK)
POCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco+=	poco>=1.3.5
BUILDLINK_PKGSRCDIR.poco?=	../../wip/poco

.include "../../security/openssl/buildlink3.mk"
.endif # POCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco
