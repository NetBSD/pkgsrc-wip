# $NetBSD$

DISTNAME=	typst-${GITHUB_TAG:C/-/./:C/-/./}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=typst/}
GITHUB_PROJECT=	typst
GITHUB_TAG=	22-03-21

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://typst.app/
COMMENT=	Markup-based typesetting system
LICENSE=	apache-2.0

#USE_LANGUAGES+=	c c++
#USE_TOOLS+=	gmake pkg-config

#TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"
.include "cargo-depends-git.mk"

INSTALLATION_DIRS=	bin

post-extract:
.for name rev url path in ${CARGO_GIT_FILES}
	${MV} ${WRKDIR}/${name}-${rev} ${WRKDIR}/vendor/${path}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/zola ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
