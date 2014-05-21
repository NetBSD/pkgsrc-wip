# $NetBSD: Makefile,v 1.12 2014/05/21 21:04:46 szptvlfn Exp $

DISTNAME=	xmobar-0.20.1
CATEGORIES=	sysutils

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Xmobar is a minimalistic text based status bar
LICENSE=	modified-bsd

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-HTTP/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/hs-stm/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
