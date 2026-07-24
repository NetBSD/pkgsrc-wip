# $NetBSD$

DISTNAME=	hawk-v0.9
PKGNAME=	${DISTNAME:S,-v,-scheme-,}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=djwatson/}
GITHUB_PROJECT=	hawk
GITHUB_RELEASE=	v0.9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://djwatson.github.io/hawk/
COMMENT=	Scheme jit that makes code fly!
# not use about this, some third party files are "do as you please"
# and some third party files have no explicit copyright
LICENSE=	mit AND modified-bsd

# needs [[musttail]]
#GCC_REQD=		15
PKGSRC_COMPILER=	clang

USE_LANGUAGES+=		c c++
CMAKE_CONFIGURE_ARGS+=	-DBOOTSTRAP=ON
CMAKE_CONFIGURE_ARGS+=	-DPKGSRCLDFLAGS="-L${PREFIX}/lib -Wl,-rpath -Wl,${PREFIX}/lib"

NOT_PAX_MPROTECT_SAFE+=	bin/hawk
INSTALLATION_DIRS+=	libexec
SH_ARG_LIST=		$$@

post-install:
	${ECHO} "#/bin/sh" > ${WRKSRC}/hawk-cc
	${ECHO} >> ${WRKSRC}/hawk-cc
	${ECHO} "exec ${PREFIX}/bin/clang -L${PREFIX}/lib -Wl,-rpath -Wl,${PREFIX}/lib \"${SH_ARG_LIST:Q}\"" >> ${WRKSRC}/hawk-cc
	${INSTALL_SCRIPT} ${WRKSRC}/hawk-cc ${DESTDIR}${PREFIX}/libexec/hawk-cc

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/capstone/buildlink3.mk"
.include "../../devel/cmake/build.mk"
BUILDLINK_DEPMETHOD.Gauche=	build
.include "../../lang/gauche/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
