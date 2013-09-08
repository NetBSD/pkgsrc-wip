# $NetBSD: Makefile,v 1.6 2013/09/08 00:09:02 kimmo Exp $

# fetching by tag from GitHub needs some special treatment
DISTNAME=	gnosek-fcgiwrap-${VERSION}-${VERSION_TAG}
PKGNAME=	fcgiwrap-${VERSION}
CATEGORIES=	www

COMMENT=	FastCGI wrapper for plain CGI scripts
LICENSE=	mit

VERSION=	1.1.0
VERSION_TAG=	3-g4b2151e

WRKSRC=		${WRKDIR}/gnosek-fcgiwrap-${DISTNAME:C/.*-g//}
MASTER_SITES=	https://github.com/gnosek/fcgiwrap/tarball/${DISTNAME:C/.*-g//}/

FETCH_USING=	curl

CATEGORIES=	www
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nginx.localdomain.pl/wiki/FcgiWrap
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoreconf

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
