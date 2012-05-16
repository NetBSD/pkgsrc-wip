# $NetBSD: Makefile,v 1.13 2012/05/16 14:18:48 fhajny Exp $

PKGNAME=		${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		1

COMMENT=		Passenger module for running Rails and Rack applications on Apache2

.include "../../wip/ruby-passenger/Makefile.common"

PKG_APACHE_ACCEPTED=	apache24 apache22 apache2
APACHE_MODULE=		YES

DEPENDS+=		ruby[0-9]*-${DISTNAME}:../../wip/ruby-passenger

do-build:
	cd ${WRKSRC}/build && ${RAKE} apache2:clean apache2

do-install:
	${INSTALL_LIB} ${WRKSRC}/ext/apache2/mod_passenger.so ${DESTDIR}${PREFIX}/lib/httpd/mod_passenger.so

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
