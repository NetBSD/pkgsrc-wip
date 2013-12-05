# $NetBSD: Makefile,v 1.28 2013/12/05 05:34:20 phonohawk Exp $

DISTNAME=	darcs-2.8.4
PKGNAME=	${DISTNAME}
CATEGORIES=	devel scm

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://www.darcs.net/
COMMENT=	Distributed revision control system
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+= -fforce-char8-encoding
.include "options.mk"

CONFIGURE_ARGS+= --extra-include-dirs=${PREFIX:Q}/include
CONFIGURE_ARGS+= --extra-lib-dirs=${PREFIX:Q}/lib

.include "../../wip/mk/haskell.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-hashed-storage/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-html/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-random/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/hs-tar/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
