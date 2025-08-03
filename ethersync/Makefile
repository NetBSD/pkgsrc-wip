# $NetBSD$

DISTNAME=	ethersync-0.7.0
CATEGORIES=	net editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=ethersync/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethersync/ethersync/
COMMENT=	Peer-to-peer, editor-agnostic collaborative editing
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c

WRKSRC=		${WRKDIR}/${DISTNAME}/daemon

INSTALLATION_DIRS+=	share/doc/ethersync

post-install:
	${INSTALL_DATA} ${WRKSRC}/../README.md ${DESTDIR}${PREFIX}/share/doc/ethersync

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
