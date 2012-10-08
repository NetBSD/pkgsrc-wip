# $NetBSD: Makefile,v 1.2 2012/10/08 14:00:39 asau Exp $
#

DISTNAME=	blaze-textual-0.2.0.4
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
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
