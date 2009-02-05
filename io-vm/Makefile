# $NetBSD: Makefile,v 1.6 2009/02/05 23:04:00 milosn Exp $

.include "../../wip/io/version.mk"

DISTNAME=		io-${IO_VERSION}
PKGNAME=		io-vm-${IO_VERSION}
#PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${IO_MASTER_SITES}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		http://www.iolanguage.com/
COMMENT=		Small programming language


#USE_PKGLOCALEDIR=	yes
NO_CONFIGURE=		yes
USE_TOOLS+=		gmake pax
BUILD_TARGET=		vm
WRKSRC=			${WRKDIR}/io

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-build
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=			fix-linking
SUBST_STAGE.fix-linking=	pre-build
SUBST_MESSAGE.fix-linking=	Fixing linking.
SUBST_FILES.fix-linking=	tools/Makefile
SUBST_SED.fix-linking=		-e 's,LFLAGS +=-lm,LFLAGS +=-lm -L${PREFIX}/lib ${LINKER_RPATH_FLAG}${PREFIX}/lib,g'

INSTALLATION_DIRS=		bin include/io lib lib/io lib/io/addons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/binaries/io ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/include/io
	cp ${WRKSRC}/_build/headers/*.h ${PREFIX}/include/io/
	${INSTALL_LIB} ${WRKSRC}/_build/dll/libiovmall.so  ${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/_build/lib/libiovmall.a  ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
