# $NetBSD: Makefile,v 1.10 2014/05/15 21:49:08 szptvlfn Exp $
#

DISTNAME=	haskeline-0.7.1.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Command-line interface for user input, written in Haskell
LICENSE=	modified-bsd

# We want the terminfo library to be used.
CONFIGURE_ARGS+= -fterminfo

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-terminfo/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
