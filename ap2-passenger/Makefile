# $NetBSD: Makefile,v 1.16 2012/08/10 11:37:24 fhajny Exp $

PKGNAME=		${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${DISTNAME}

COMMENT=		Passenger module for running Rails and Rack applications on Apache2

.include "../../wip/ruby-passenger/Makefile.common"

PKG_APACHE_ACCEPTED=	apache24 apache22 apache2
APACHE_MODULE=		YES

DEPENDS+=		${RUBY_PKGPREFIX}-${DISTNAME}:../../wip/ruby-passenger

INSTALLATION_DIRS+=	lib/httpd

do-build:
	cd ${WRKSRC}/build && ${RAKE} apache2:clean apache2

do-install:
	${INSTALL_LIB} ${WRKSRC}/ext/apache2/mod_passenger.so ${DESTDIR}${PREFIX}/lib/httpd/mod_passenger.so

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
