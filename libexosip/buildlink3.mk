# $NetBSD: buildlink3.mk,v 1.5 2013/07/14 19:04:59 othyro Exp $

BUILDLINK_TREE+=	libexosip2

.if !defined(LIBEXOSIP2_BUILDLINK3_MK)
LIBEXOSIP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libexosip2+=	libeXosip2>=3.5.0
BUILDLINK_PKGSRCDIR.libexosip2?=	../../wip/libexosip

pkgbase := libexosip2
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libexosip2:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../net/libcares/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBEXOSIP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libexosip2
