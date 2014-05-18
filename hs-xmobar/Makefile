# $NetBSD: Makefile,v 1.10 2014/05/18 21:33:30 szptvlfn Exp $

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
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/hs-stm/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-x11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
