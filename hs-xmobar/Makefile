# $NetBSD: Makefile,v 1.14 2014/07/24 21:20:39 szptvlfn Exp $

DISTNAME=	xmobar-0.20.1
CATEGORIES=	sysutils

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Xmobar is a minimalistic text based status bar
LICENSE=	modified-bsd

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../www/hs-HTTP/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../devel/hs-stm/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
