# $NetBSD: Makefile,v 1.1.1.1 2011/09/27 15:13:01 phonohawk Exp $
#

DISTNAME=	blaze-textual-0.2.0.4
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast rendering of common datatypes
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT= user-destdir
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
