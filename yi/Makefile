# $NetBSD: Makefile,v 1.3 2012/10/07 20:11:11 asau Exp $
#

DISTNAME=	yi-0.6.3.0
PKGNAME=	${DISTNAME}
CATEGORIES=	editors

MAINTAINER=	pho@cielonegro.org
COMMENT=	The Haskell-Scriptable Editor
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+= \
	-f-cocoa \
	-f-scion \
	-f-ghcAPI \
	-f-hacking \
	-f-testing

.include "options.mk"

.include "../../wip/mk/haskell.mk"
.include "../../wip/alex/buildlink3.mk"
.include "../../wip/hs-Diff/buildlink3.mk"
.include "../../wip/hs-cautious-file/buildlink3.mk"
.include "../../wip/hs-data-accessor/buildlink3.mk"
.include "../../wip/hs-data-accessor-monads-fd/buildlink3.mk"
.include "../../wip/hs-data-accessor-template/buildlink3.mk"
.include "../../wip/hs-derive/buildlink3.mk"
.include "../../wip/hs-dlist/buildlink3.mk"
.include "../../wip/hs-dyre/buildlink3.mk"
.include "../../wip/hs-fingertree/buildlink3.mk"
.include "../../wip/hs-ghc-paths/buildlink3.mk"
.include "../../wip/hs-hint/buildlink3.mk"
.include "../../wip/hs-monads-fd/buildlink3.mk"
.include "../../wip/hs-pointedlist03/buildlink3.mk"
.include "../../wip/hs-pureMD5/buildlink3.mk"
.include "../../wip/hs-regex-base/buildlink3.mk"
.include "../../wip/hs-regex-tdfa/buildlink3.mk"
.include "../../wip/hs-rosezipper1/buildlink3.mk"
.include "../../wip/hs-split/buildlink3.mk"
.include "../../wip/hs-uniplate/buildlink3.mk"
.include "../../wip/hs-unix-compat/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
