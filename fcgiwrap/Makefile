# $NetBSD: Makefile,v 1.3 2011/12/03 23:27:48 cheusov Exp $

# fetching by tag from GitHub needs some special treatment
DISTNAME=	gnosek-fcgiwrap-${VERSION}-4-g58ec209
PKGNAME=	fcgiwrap-${VERSION}
CATEGORIES=	www

COMMENT=	FastCGI wrapper for plain CGI scripts
LICENSE=	mit

VERSION=	1.0.3

WRKSRC=		${WRKDIR}/gnosek-fcgiwrap-${DISTNAME:C/.*-g//}
MASTER_SITES=	https://github.com/gnosek/fcgiwrap/tarball/${DISTNAME:C/.*-g//}/

FETCH_USING=	curl

CATEGORIES=	www
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nginx.localdomain.pl/wiki/FcgiWrap
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
