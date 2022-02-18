# $NetBSD$

DISTNAME=	davis-0.1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=SimonPersson/}
GITHUB_PROJECT=	davis
GITHUB_TAG=	f16a22288e6cac4b62ba8cc25cba06c6ae4a89ab

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SimonPersson/davis/
COMMENT=	CLI client for MPD
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/davis \
		 ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
