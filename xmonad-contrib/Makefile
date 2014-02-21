# $NetBSD: Makefile,v 1.10 2014/02/21 10:39:03 szptvlfn Exp $

DISTNAME=	xmonad-contrib-0.11.2
PKGNAME=	${DISTNAME}
CATEGORIES=	wm

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://xmonad.org/
COMMENT=	Third party extensions for xmonad
LICENSE=	modified-bsd

.include "options.mk"

.include "../../x11/libXft/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-random/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-x11/buildlink3.mk"
.include "../../wip/xmonad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
