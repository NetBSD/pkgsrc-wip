# $NetBSD: Makefile,v 1.1.1.1 2009/01/30 15:13:12 phonohawk Exp $
#

DISTNAME=	regex-compat-0.92
PKGNAME=	hs-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://sourceforge.net/projects/lazy-regex
COMMENT=	Replaces/Enhances Haskell Text.Regex

USE_LANGUAGES=	# none

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-regex-base/buildlink3.mk"
.include "../../wip/hs-regex-posix/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
