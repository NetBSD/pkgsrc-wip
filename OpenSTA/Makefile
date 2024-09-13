# $NetBSD$

GITHUB_TAG=	2dcf169d9fe8a03aac659f9a214dd6dad6cefecf
DISTNAME=	OpenSTA-2.5.0
CATEGORIES=	cad devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-OpenROAD-Project/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/The-OpenROAD-Project/OpenSTA/
COMMENT=	Gate level static timing verifier
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/OpenSTA-${GITHUB_TAG}

GCC_REQD+=	13
FORCE_CXX_STD=	c++20

USE_LANGUAGES=	c++

USE_TOOLS+= chmod cp bison

INSTALLATION_DIRS+=	etc

post-install:
	${CP} -r ${WRKSRC}/etc/ ${DESTDIR}${PREFIX}
	${CHMOD} +x ${DESTDIR}${PREFIX}/etc/TclEncode.tcl

.include "../../devel/swig3/buildlink3.mk"
.include "../../wip/cudd/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
