# $NetBSD: Makefile,v 1.12 2014/02/07 11:33:14 szptvlfn Exp $
DISTNAME=	xmonad-${VERSION}
PKGNAME=	xmonad-${VERSION}
VERSION=	0.11
CATEGORIES=	wm

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://xmonad.org/
COMMENT=	Tiling window manager

LICENSE=	modified-bsd

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xmonad.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-x11/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
