# $NetBSD$

GITHUB_PROJECT=	offset
GITHUB_TAG=	v0.1.11
DISTNAME=	v0.1.11
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=freedomlayer/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/freedomlayer/offset/
COMMENT=	Offset payment engine
LICENSE=	gnu-agpl-v3


INSTALLATION_DIRS=	bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stcompact ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stctrl ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stindex ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stmgr ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stnode ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/strelay ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"
.include "../../wip/capnproto/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
