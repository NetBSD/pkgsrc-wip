# $NetBSD$

GITHUB_PROJECT=	Odin
GITHUB_TAG=	f64139987006a40c0548cdc507c4aca72e1435ea
DISTNAME=	odin-0.0.0.10843
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=odin-lang/}

MAINTAINER=		mail@andreasjonsson.se
HOMEPAGE=		https://odin-lang.org/
COMMENT=		General-purpose programming language
LICENSE=		modified-bsd

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c11
USE_CXX_FEATURES=	c++17
USE_CWRAPPERS=		no

CFLAGS+=	-Wno-unused-result -Wno-return-local-addr

USE_TOOLS+=	bash pax
TOOL_DEPENDS+=	git-2.*:../../devel/git

INSTALLATION_DIRS=	bin odin
WRKSRC=			${WRKDIR}/Odin-${GITHUB_TAG}

do-build:
	cd ${WRKSRC} && \
		ODIN_ROOT=${WRKSRC} \
		${BASH} ./build_odin.sh release

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
