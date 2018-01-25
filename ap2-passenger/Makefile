# $NetBSD$

PKGNAME=		${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${DISTNAME}
COMMENT=		Passenger module for running Rails and Rack applications on Apache2

BUILDLINK_DEPMETHOD.curl=	build

DEPENDS+=		${RUBY_PKGPREFIX}-${DISTNAME}:../../wip/ruby-passenger

.include "../../wip/ruby-passenger/Makefile.common"

RUBY_VERSIONS_ACCEPTED=	22 23   # www/ruby-rack via wip/ruby-passenger
APACHE_MODULE=		YES
USE_APR=		YES

# Get rid of these bits from www/apache24 as they break build on SunOS
BUILDLINK_TRANSFORM+=	rm:-D_XOPEN_SOURCE
BUILDLINK_TRANSFORM+=	rm:-D_XOPEN_SOURCE_EXTENDED=1

INSTALLATION_DIRS+=	lib/httpd

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${RAKE} apache2

do-install:
	${INSTALL_LIB} ${WRKSRC}/buildout/apache2/mod_passenger.so \
	  ${DESTDIR}${PREFIX}/lib/httpd/mod_passenger.so

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
