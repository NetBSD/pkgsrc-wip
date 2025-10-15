# $NetBSD$

DISTNAME=	stalwart-0.13.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=stalwartlabs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://stalw.art/
COMMENT=	Open-source mail & collaboration server
LICENSE=	gnu-agpl-v3

## See also
## <https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=286326>
## <https://aur.archlinux.org/packages/stalwart-mail-server>

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

BUILDLINK_TRANSFORM+=	rm:-lc++

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stalwart ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stalwart-cli ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
