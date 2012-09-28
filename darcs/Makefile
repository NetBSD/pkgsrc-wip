# $NetBSD: Makefile,v 1.27 2012/09/28 21:24:30 asau Exp $

DISTNAME=	darcs-2.5
PKGNAME=	${DISTNAME}
CATEGORIES=	devel scm

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://www.darcs.net/
COMMENT=	Distributed revision control system
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+= -fhttp -fterminfo -fcolor -fmmap
.include "options.mk"

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-hashed-storage/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-html/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/hs-tar/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
