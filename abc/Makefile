# $NetBSD$

GITHUB_PROJECT=	abc
GITHUB_TAG=	ef5389d31526003c2ebd7e6d6d6fe3848a20f0a2
DISTNAME=	${GITHUB_PROJECT}-0.0.0.5430
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-OpenRoad-Project/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/The-OpenRoad-Project/abc/
COMMENT=	System for Sequential Logic Synthesis and Formal Verification
#LICENSE=	https://github.com/The-OpenROAD-Project/abc?tab=License-1-ov-file

WRKSRC=		${WRKDIR}/abc-ef5389d31526003c2ebd7e6d6d6fe3848a20f0a2
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax find

CMAKE_CONFIGURE_ARGS+=	-DABC_USE_NAMESPACE=abc

INSTALLATION_DIRS+=	bin lib include

BUILDDIR=	${WRKSRC}/${CMAKE_BUILD_DIR}
INCLUDEDIR=	${DESTDIR}${PREFIX}/include/abc

do-install:
.for idir in ${INSTALLATION_DIRS}
	${MKDIR} -p ${DESTDIR}${PREFIX}/${idir}
.endfor
	${INSTALL} ${BUILDDIR}/abc ${DESTDIR}${PREFIX}/bin
	${INSTALL} ${BUILDDIR}/libabc.a ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/src && ${FIND} . -name \*.h -exec ${PAX} -rw {} ${INCLUDEDIR} \;

.include "../../mk/readline.buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
