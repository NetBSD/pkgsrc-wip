# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	odin-25.8.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=odin-lang/}
GITHUB_PROJECT=	Odin
GITHUB_TAG=	dev-2025-08 # Note that this is a different format from the pkgsrc version.

MAINTAINER=		mail@andreasjonsson.se
HOMEPAGE=		https://odin-lang.org/
COMMENT=		General-purpose programming language
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c11
USE_CXX_FEATURES=	c++17
USE_CWRAPPERS=		no

USE_TOOLS+=	pax

INSTALLATION_DIRS=	bin odin
CFLAGS+=		-Wno-unused-result -Wno-return-local-addr

do-build:
	cd ${WRKSRC} && ./build_odin.sh release

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/odin ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/odin ${DESTDIR}${PREFIX}/odin
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/odin
	cd ${WRKSRC} && pax -rw base ${DESTDIR}${PREFIX}/odin
	cd ${WRKSRC} && pax -rw core ${DESTDIR}${PREFIX}/odin
	cd ${WRKSRC} && pax -rw vendor ${DESTDIR}${PREFIX}/odin

.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
