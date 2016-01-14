# $NetBSD: Makefile,v 1.2 2015/05/10 07:41:59 thomasklausner Exp $

DISTNAME=	fswatch-1.7.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=emcrisostomo/}

HOMEPAGE=	https://github.com/emcrisostomo/fswatch
COMMENT=	Cross-platform file change monitor with multiple backends
LICENSE=	gnu-gpl-v3

# needs autopoint
BUILD_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake autoconf automake makeinfo
INFO_FILES=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
