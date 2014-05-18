# $NetBSD: Makefile,v 1.4 2014/05/18 21:33:26 szptvlfn Exp $
#

DISTNAME=	blaze-textual-0.2.0.8
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast rendering of common datatypes
LICENSE=	modified-bsd

.include "options.mk"

.include "../../wip/mk/haskell.mk"
PLIST_VARS+= native
PRINT_PLIST_AWK+= \
	{ gsub(/${PKGVERSION:S/./\./g:C/nb[0-9]*$$//}/, "$${PKGVERSION}"); } \
	/Blaze\/Text\/Double\/Native\./ { print "$${PLIST.native}" $$0; next; }

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
