# $NetBSD: Makefile,v 1.7 2013/10/09 12:18:36 fhajny Exp $

DISTNAME=	fcgiwrap-1.1.0
CATEGORIES=	www
MASTER_SITES=	-https://github.com/gnosek/${DISTNAME:S|-|/archive/|}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nginx.localdomain.pl/wiki/FcgiWrap
COMMENT=	FastCGI wrapper for plain CGI scripts
LICENSE=	mit

FETCH_USING=	curl

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoreconf pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
