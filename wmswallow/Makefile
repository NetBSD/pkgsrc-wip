# $NetBSD: Makefile,v 1.3 2014/06/01 12:49:49 thomasklausner Exp $
#

DISTNAME=	wmswallow
PKGNAME=	${DISTNAME}-0.6.1
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://dockapps.windowmaker.org/download.php/id/141/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dockapps.windowmaker.org/file.php/id/102
COMMENT=	Dock any (!) Application into the WindowMaker dock
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS+=	bin

BUILD_TARGET=	xfree
LDFLAGS+=	${X11_LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmswallow ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
