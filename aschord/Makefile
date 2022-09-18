# $NetBSD$

DISTNAME=	aschord-0.2.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=yzhong52/}
GITHUB_PROJECT=	ascii_chord
GITHUB_TAG=	b2f3e6ee2aa2cd444a5900c3b460a53ab64c70f7

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yzhong52/ascii_chord/
COMMENT=	Print guitar chord with ascii characters given its name
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/aschord \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
