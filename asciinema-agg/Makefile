# $NetBSD$

DISTNAME=	agg-1.5.0
PKGNAME=	${DISTNAME:S/^/asciinema-/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=asciinema/}
GITHUB_PROJECT=	agg
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asciinema/agg
COMMENT=	Asciinema gif generator
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/agg ${DESTDIR}${PREFIX}/bin/asciinema-agg

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
