# $NetBSD: Makefile,v 1.1.1.1 2003/10/26 14:26:22 hfath Exp $

DISTNAME=		stunnel-3.26
CATEGORIES=		security
MASTER_SITES=		http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel

CONFLICTS=		stunnel-[4-9]*

USE_BUILDLINK2=		# defined
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE} \
			--with-cert-dir="${SSLCERTS}" \
			--with-pem-dir="${SSLCERTS}" \
			--with-tcp-wrappers \
			--sysconfdir="${PKG_SYSCONFDIR}"

PKG_SYSCONFSUBDIR=	stunnel

.include "../../security/openssl/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
