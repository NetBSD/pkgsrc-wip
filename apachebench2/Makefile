# $NetBSD: Makefile,v 1.5 2004/05/02 22:01:54 blef Exp $

# XXX This uses the version of apache2 distfile instead of
# XXX the AP_AB_BASEREVISION from the support/ab.c source.
PKGNAME=		apachebench2-${APACHE_VERSION}
CATEGORIES=		benchmarks www

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		Apache HTTP (Web) server benchmarking tool

BUILD_DEFS+=		USE_INET6
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
#USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
ALL_TARGET=		ab

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-static-ab

do-build:
	cd ${WRKSRC}/srclib/pcre && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/srclib/apr-util && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/srclib/apr && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/support && ${SETENV} ${MAKE_ENV} ${MAKE} ab

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/support/ab ${PREFIX}/sbin/apachebench2
	${INSTALL_MAN} ${WRKSRC}/docs/man/ab.8 ${PREFIX}/man/man8/apachebench2.8

.include "../../www/apache2/Makefile.common"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
