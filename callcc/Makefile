# $NetBSD$

DISTNAME=	callcc-0.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=djwatson/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/djwatson/callcc/
COMMENT=	R7RS scheme compiler with LLVM backend
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

# Uses clang specific features
PKGSRC_COMPILER=	clang
USE_TOOLS+=		gmake pkg-config
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

pre-build:
	LIBS=`pkg-config --libs gmp libutf8proc`; \
	${ECHO} "(define callcc-link-libs \"$${LIBS}\")" > ${WRKSRC}/compiler/bc-libs.scm

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_DEPMETHOD.Gauche=	build
.include "../../lang/gauche/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
