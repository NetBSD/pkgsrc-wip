# $NetBSD: Makefile,v 1.8 2013/03/31 00:59:49 szptvlfn Exp $

DISTNAME=	xmonad-contrib-0.11
PKGNAME=	${DISTNAME}
PKGREVISION=    1
CATEGORIES=	wm

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://xmonad.org/
COMMENT=	Third party extensions for xmonad

LICENSE=	modified-bsd

.include "options.mk"

.include "../../x11/libXft/buildlink3.mk"
.include "../../wip/hs-random/buildlink3.mk"
.include "../../wip/hs-x11/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/xmonad/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
