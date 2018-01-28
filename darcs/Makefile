# $NetBSD: Makefile,v 1.35 2014/08/12 21:24:14 szptvlfn Exp $

DISTNAME=	darcs-2.8.4
PKGNAME=	${DISTNAME}
CATEGORIES=	devel scm

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://www.darcs.net/
COMMENT=	Distributed revision control system
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+= -fforce-char8-encoding
.include "options.mk"

CONFIGURE_ARGS+=	--extra-include-dirs=${PREFIX}/include
CONFIGURE_ARGS+=	--extra-lib-dirs=${PREFIX}/lib

.include "../../wip/mk/haskell.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-hashed-storage/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-html/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/hs-tar/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
