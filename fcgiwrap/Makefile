# $NetBSD: Makefile,v 1.8 2014/06/01 12:49:35 thomasklausner Exp $

DISTNAME=	fcgiwrap-1.1.0
CATEGORIES=	www
MASTER_SITES=	-https://github.com/gnosek/${DISTNAME:S|-|/archive/|}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nginx.localdomain.pl/wiki/FcgiWrap
COMMENT=	FastCGI wrapper for plain CGI scripts
LICENSE=	mit


GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoreconf pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
