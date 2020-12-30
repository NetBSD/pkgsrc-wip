# $NetBSD$

DISTNAME=	carp-0.4.8
CATEGORIES=	lang
#MASTER_SITES=	${MASTER_SITE_GITHUB:=carp-lang/}
MASTER_SITES+=	${MASTER_SITE_GITHUB:=dressupgeekout/}
GITHUB_PROJECT=	Carp
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	00757580ecf6ca1fe5fce62908ae21fd3d3b36bf

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	A statically typed Lisp
LICENSE=	apache-2.0

NOT_PAX_MPROTECT_SAFE+=	bin/carp
NOT_PAX_MPROTECT_SAFE+=	bin/carp-header-parse

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../wip/hs-cmark/buildlink3.mk"
.include "../../wip/hs-open-browser/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
