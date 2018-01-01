# $NetBSD: Makefile,v 1.20 2015/04/02 15:40:14 fhajny Exp $

PKGNAME=		${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${DISTNAME}

COMMENT=		Passenger module for running Rails and Rack applications on Apache2

BUILDLINK_DEPMETHOD.libeio=	build
BUILDLINK_DEPMETHOD.curl=	build

RUBY_VERSIONS_ACCEPTED=	22 23   # www/ruby-rack via wip/ruby-passenger

.include "../../wip/ruby-passenger/Makefile.common"

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
