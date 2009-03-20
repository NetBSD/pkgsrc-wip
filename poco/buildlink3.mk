# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	poco

.if !defined(POCO_BUILDLINK3_MK)
POCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco+=	poco>=1.3.3p1
BUILDLINK_PKGSRCDIR.poco?=	../../wip/poco

.include "../../security/openssl/buildlink3.mk"
.endif # POCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco
