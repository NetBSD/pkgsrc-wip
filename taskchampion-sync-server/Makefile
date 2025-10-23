# $NetBSD$
# Seems wrong making this DISTNAME?
DISTNAME=	0.7.0
GITHUB_PROJECT= taskchampion-sync-server
GITHUB_TAG=	refs/tags/v${DISTNAME}
PKGNAME= ${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=GothenburgBitFactory/}
DIST_SUBDIR=	${GITHUB_PROJECT}
WRKSRC= ${WRKDIR}/${PKGNAME}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	https://github.com/GothenburgBitFactory/taskchampion-sync-server/
COMMENT=	Sync server for taskwarrior and other taskchampion applications
LICENSE=	mit
USE_TOOLS+=	perl gmake

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${GITHUB_PROJECT} ${DESTDIR}${PREFIX}/bin

# url2pkg-marker (please do not remove this line.)
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
