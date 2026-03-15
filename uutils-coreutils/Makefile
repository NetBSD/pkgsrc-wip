# $NetBSD$

DISTNAME=	coreutils-0.7.0
PKGNAME=	uutils-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=uutils/}
GITHUB_PROJECT=	coreutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uutils.github.io/coreutils/
COMMENT=	Cross-platform Rust rewrite of the GNU coreutils
LICENSE=	mit

RUST_REQ=	1.88.0

# TODO: fill in PROGS
PROGS+=		yes

INSTALLATION_DIRS+=	uutils-coreutils/bin

post-install:
.for program in ${PROGS}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} coreutils uu-${program}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} coreutils ../uutils-coreutils/bin/${program}
.endfor

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
