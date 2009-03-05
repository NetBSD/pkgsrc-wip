# $NetBSD: Makefile,v 1.10 2009/03/05 11:03:16 hfath Exp $

DISTNAME=		stunnel-3.26
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		stunnel-[4-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q} \
			--with-cert-dir=${SSLCERTS:Q} \
			--with-pem-dir=${SSLCERTS:Q} \
			--with-tcp-wrappers

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
