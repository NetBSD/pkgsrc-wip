# $NetBSD: Makefile,v 1.21 2010/01/24 03:55:01 phonohawk Exp $

DISTNAME=		darcs-2.3.1
PKGNAME=		${DISTNAME}
CATEGORIES=		devel scm

MAINTAINER=		matias@dotbsd.org
HOMEPAGE=		http://www.darcs.net/
COMMENT=		Distributed revision control system
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+= -fbytestring -futf8-string -f-type-witnesses -f-test
.include "options.mk"

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-hashed-storage3/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-html/buildlink3.mk"
.include "../../wip/hs-mmap4/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
