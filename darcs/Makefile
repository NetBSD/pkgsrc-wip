# $NetBSD: Makefile,v 1.22 2010/02/12 06:50:59 phonohawk Exp $

DISTNAME=		darcs-beta-${VERSION}
PKGNAME=		darcs-${VERSION}
VERSION=		2.3.98.3
CATEGORIES=		devel scm

MAINTAINER=		matias@dotbsd.org
HOMEPAGE=		http://www.darcs.net/
COMMENT=		Distributed revision control system
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+= -fbytestring -futf8-string -f-type-witnesses -f-test
.include "options.mk"

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-hashed-storage/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-html/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
