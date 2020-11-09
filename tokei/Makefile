# $NetBSD$

DISTNAME=		tokei-12.0.4a
CATEGORIES=		devel textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=XAMPPRocky/}
DIST_SUBDIR=		${GITHUB_PROJECT}
GITHUB_PROJECT=		tokei
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		ng0@NetBSD.org
HOMEPAGE=		https://github.com/XAMPPRocky/tokei/
COMMENT=		Displays statistics about code
LICENSE=		apache-2.0 AND mit

.include "cargo-depends.mk"

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

post-install:
	${RM} ${DESTDIR}${PREFIX}/.crates2.json

.include "../../wip/mk/cargo-binary.mk"
.include "../../mk/bsd.pkg.mk"
