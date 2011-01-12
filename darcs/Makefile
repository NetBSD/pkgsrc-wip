# $NetBSD: Makefile,v 1.26 2011/01/12 05:56:33 phonohawk Exp $

DISTNAME=	darcs-2.5
PKGNAME=	${DISTNAME}
CATEGORIES=	devel scm

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://www.darcs.net/
COMMENT=	Distributed revision control system
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
