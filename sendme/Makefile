# $NetBSD$

DISTNAME=	sendme-0.37.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=n0-computer/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/n0-computer/sendme/
COMMENT=	Peer-to-peer file and directory transfer tool
LICENSE=	mit OR apache-2.0

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES+=	c c++

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
