# $NetBSD: Makefile,v 1.4 2008/12/14 10:45:31 tnn2 Exp $

.include "../../wip/io/version.mk"

DISTNAME=		io-${IO_VERSION}
PKGNAME=		io-vm-${IO_VERSION}
PKGREVISION=		0
CATEGORIES=		lang
MASTER_SITES=		${IO_MASTER_SITES}
EXTRACT_SUFX=   	.tar.bz2

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		Small programming language


#USE_PKGLOCALEDIR=	yes
NO_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_TARGET=		vm
WRKSRC=			${WRKDIR}/io

SUBST_CLASSES+=			fix-paths
SUBST_CLASSES+=			fix-linking

SUBST_STAGE.fix-paths=		pre-build
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'

SUBST_STAGE.fix-linking=	pre-build
SUBST_MESSAGE.fix-linking=	Fixing linking.
SUBST_FILES.fix-linking=	tools/Makefile
SUBST_SED.fix-linking=		-e 's,LFLAGS +=-lm,LFLAGS +=-lm -L${PREFIX}/lib ${LINKER_RPATH_FLAG}${PREFIX}/lib,g'

INSTALLATION_DIRS=		bin include/io lib lib/io lib/io/addons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/binaries/io ${PREFIX}/bin
	${CP} -rf ${WRKSRC}/_build/headers/*.h ${PREFIX}/include/io/
	${INSTALL_LIB} ${WRKSRC}/_build/dll/libiovmall.so  ${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/_build/lib/libiovmall.a  ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
