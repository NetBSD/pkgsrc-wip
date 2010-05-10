# $NetBSD: Makefile,v 1.6 2010/05/10 02:14:31 phonohawk Exp $
#

DISTNAME=	haskeline-0.6.2.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Command-line interface for user input, written in Haskell

# We want the terminfo library to be used.
CONFIGURE_ARGS+= -fterminfo

.include "../../wip/mk/haskell.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-terminfo/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
