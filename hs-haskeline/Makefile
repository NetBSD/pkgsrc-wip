# $NetBSD: Makefile,v 1.8 2013/09/02 23:21:31 szptvlfn Exp $
#

DISTNAME=	haskeline-0.7.0.3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Command-line interface for user input, written in Haskell
LICENSE=	modified-bsd

# We want the terminfo library to be used.
CONFIGURE_ARGS+= -fterminfo

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-terminfo/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
