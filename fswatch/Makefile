# $NetBSD: Makefile,v 1.1 2015/05/07 22:25:32 jonthn Exp $

DISTNAME=	fswatch-1.4.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=emcrisostomo/}

HOMEPAGE=	https://github.com/emcrisostomo/fswatch
COMMENT=	Cross-platform file change monitor with multiple backends
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake autoconf automake makeinfo
INFO_FILES=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
