# $NetBSD: Makefile,v 1.15 2012/09/24 16:50:03 asau Exp $

# XXX This uses the version of apache2 distfile instead of
# XXX the AP_AB_BASEREVISION from the support/ab.c source.
PKGNAME=		apachebench2-${APACHE_VERSION}
PKGREVISION=		2
CATEGORIES=		benchmarks www

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		Apache HTTP (Web) server benchmarking tool

BUILD_DEFS+=		IPV6_READY
#USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
BUILD_TARGET=		ab

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-static-ab

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-build:
	cd ${WRKSRC}/srclib/pcre && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/srclib/apr-util && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/srclib/apr && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/support && ${SETENV} ${MAKE_ENV} ${MAKE} ab

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/support/ab ${DESTDIR}${PREFIX}/sbin/apachebench2
	${INSTALL_MAN} ${WRKSRC}/docs/man/ab.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/apachebench2.8

.include "../../www/apache2/Makefile.common"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
