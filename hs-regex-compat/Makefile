# $NetBSD: Makefile,v 1.2 2009/05/21 04:53:25 phonohawk Exp $
#

DISTNAME=	regex-compat-0.92
PKGREVISION=	1
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
