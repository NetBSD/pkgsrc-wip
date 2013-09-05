# $NetBSD: Makefile,v 1.18 2013/09/05 10:55:51 fhajny Exp $

PKGNAME=		${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${DISTNAME}

COMMENT=		Passenger module for running Rails and Rack applications on Apache2

BUILDLINK_DEPMETHOD.libeio=	build
BUILDLINK_DEPMETHOD.libev=	build
BUILDLINK_DEPMETHOD.curl=	build
.include "../../wip/ruby-passenger/Makefile.common"

PKG_APACHE_ACCEPTED=	apache24 apache22 apache2
APACHE_MODULE=		YES
USE_APR=		YES

DEPENDS+=		${RUBY_PKGPREFIX}-${DISTNAME}:../../wip/ruby-passenger

INSTALLATION_DIRS+=	lib/httpd

# Get rid of these bits from www/apache24 as they break build on SunOS
BUILDLINK_TRANSFORM+=	rm:-D_XOPEN_SOURCE_EXTENDED=1
BUILDLINK_TRANSFORM+=	rm:-D_XOPEN_SOURCE

do-build:
	cd ${WRKSRC}/build && ${PKGSRC_SETENV} ${MAKE_ENV} ${RAKE} apache2

do-install:
	${INSTALL_LIB} ${WRKSRC}/buildout/apache2/mod_passenger.so \
	  ${DESTDIR}${PREFIX}/lib/httpd/mod_passenger.so

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
