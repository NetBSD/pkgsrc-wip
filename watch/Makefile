# $NetBSD: Makefile,v 1.1 2015/05/08 12:43:31 jonthn Exp $

DISTNAME=	procps-ng-3.3.15
PKGNAME=	watch-3.3.15
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=procps-ng/}
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	https://gitlab.com/procps-ng/procps
COMMENT=	Execute a program periodically, showing output fullscreen
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake autoconf automake
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh --nopo

# Disable everything except 'watch' program
CONFIGURE_ARGS+=	--disable-pidof
CONFIGURE_ARGS+=	--disable-linux-systemtools
CONFIGURE_ARGS+=	--disable-kill
CONFIGURE_ARGS+=	--disable-slabtop

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
