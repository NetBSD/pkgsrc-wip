# $NetBSD: Makefile,v 1.1.1.1 2004/01/04 03:54:59 mpasternak Exp $

# XXX This uses the version of apache2 distfile instead of
# XXX the AP_AB_BASEREVISION from the support/ab.c source.
PKGNAME=		apachebench2-${APACHE_VERSION}
CATEGORIES=		benchmarks www

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://httpd.apache.org/
COMMENT=		Apache HTTP (Web) server benchmarking tool

BUILD_DEFS+=		USE_INET6
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
#USE_LIBTOOL=		YES
#LIBTOOL_OVERRIDE=	${WRKSRC}/srclib/apr/libtool
GNU_CONFIGURE=		YES
ALL_TARGET=		ab

# Apache Portable Runtime library configure options
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}
CONFIGURE_ARGS+=	--with-apr-util=${LOCALBASE}
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-static-ab
# ab_LTFLAGS="-static"

do-build:
	cd ${WRKSRC}/srclib/pcre && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/support && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/support/ab ${PREFIX}/sbin/apachebench2
	${INSTALL_MAN} ${WRKSRC}/docs/man/ab.8 ${PREFIX}/share/man/man8/apachebench2.8

.include "../../www/apache2/Makefile.common"
.include "../../security/openssl/buildlink2.mk"
.include "../../devel/apr/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
