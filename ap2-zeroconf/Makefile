# $NetBSD: Makefile,v 1.6 2014/06/22 19:57:10 thomasklausner Exp $

DISTNAME=	mod_zeroconf-0.3
PKGNAME=	ap2-zeroconf-0.3
PKGREVISION=	3
CATEGORIES=	www net
MASTER_SITES=	http://people.apache.org/~sctemme/Apcon2003/TU10/

MAINTAINER=	eggert@macvaerk.dtu.dk
HOMEPAGE=	http://www.temme.net/sander/mod_zeroconf/
COMMENT=	Allows apache2 to register on a Zero Configuration network


WRKSRC=		${WRKDIR}/mod_zeroconf

APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mod_zeroconf
NO_CONFIGURE=		YES
APXSFLAGS+=		-I ${PREFIX:Q}/include/howl
APXSFLAGS+=		-L ${PREFIX:Q}/lib
APXSFLAGS+=		-l howl

do-build:
	cd ${WRKSRC} && ${APXS} ${APXSFLAGS} -c mod_zeroconf.c

do-install:
	cd ${WRKSRC} && ${APXS} -i mod_zeroconf.la
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_zeroconf
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt ${PREFIX}/share/doc/mod_zeroconf/

.include "../../mk/apache.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
