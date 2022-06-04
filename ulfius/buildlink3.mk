# $NetBSD$

BUILDLINK_TREE+=	ulfius

.if !defined(ULFIUS_BUILDLINK3_MK)
ULFIUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ulfius+=	ulfius>=2.7.10
BUILDLINK_PKGSRCDIR.ulfius?=	../../wip/ulfius

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../wip/yder/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.endif	# ULFIUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ulfius
