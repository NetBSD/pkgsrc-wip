# $NetBSD: Makefile,v 1.4 2012/09/24 17:14:42 asau Exp $

DISTNAME=	bsvc-2.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.bradfordmott.com/bsvc/distributions/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	nocker.bk@gmail.com
HOMEPAGE=	http://www4.ncsu.edu/~bwmott/bsvc/
COMMENT=	Extensible hardware simulation framework with MC68K support
#LICENSE=	# TODO

DEPENDS+=	tk>=8.4:../../x11/tk

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_LANGUAGES=	c
USE_LANGUAGES+=	c++
MAKE_ENV+=	WRKSRC=${WRKSRC}
MAKE_ENV+=	PROJECT_BASE=${PREFIX}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
DOCWRKDIR=	${WRKDIR}/${DISTNAME}/doc
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
EGWRKDIR=	${WRKDIR}/${DISTNAME}/samples

SUBST_CLASSES+=			fix-exit
SUBST_STAGE.fix-exit=		pre-configure
SUBST_MESSAGE.fix-exit=		Fixing exit().
SUBST_FILES.fix-exit=		${WRKSRC}/Assemblers/68kasm/*.c
SUBST_SED.fix-exit=		-e 's/exit()/_Exit(1)/g'

SUBST_CLASSES+=			fix-old-cpp
SUBST_STAGE.fix-old-cpp=	pre-configure
SUBST_MESSAGE.fix-old-cpp=	Fixing old C++ code.
SUBST_FILES.fix-old-cpp=	${WRKSRC}/*/*.cxx
SUBST_FILES.fix-old-cpp+=	${WRKSRC}/*/*.hxx
SUBST_FILES.fix-old-cpp+=	${WRKSRC}/*/*/*.cxx
SUBST_FILES.fix-old-cpp+=	${WRKSRC}/*/*/*.cxx
SUBST_SED.fix-old-cpp=		-e 's/iostream\.h/iostream/; s/strstream\.h/strstream/; s/fstream\.h/fstream/'

SUBST_CLASSES+=			fix-make
SUBST_STAGE.fix-make=		pre-configure
SUBST_MESSAGE.fix-make=		Fixing make declaration.
SUBST_FILES.fix-make=		${WRKSRC}/Makefile
SUBST_FILES.fix-make+=		${WRKSRC}/*/Makefile
SUBST_FILES.fix-make+=		${WRKSRC}/*/*/Makefile
SUBST_SED.fix-make=		-e 's/make/$$\(MAKE\)/g'

pre-patch:
	cp ${WRKSRC}/Makefile.Linux ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/68kasm
	${INSTALL_DATA_DIR} ${DOCDIR}/Manual
	${INSTALL_DATA_DIR} ${DOCDIR}/Manual/ps
	${INSTALL_DATA_DIR} ${DOCDIR}/Manual/html
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/m68000
	${INSTALL_DATA_DIR} ${EGDIR}/m68360
	${INSTALL_DATA_DIR} ${EGDIR}/m68360/gas1
	${INSTALL_DATA_DIR} ${EGDIR}/m68360/gcc2
	${INSTALL_DATA_DIR} ${EGDIR}/m68360/gcc3
	${INSTALL_DATA_DIR} ${EGDIR}/m68360/gcc4
	${INSTALL_DATA_DIR} ${EGDIR}/m68360/gcc5
	${INSTALL_DATA_DIR} ${EGDIR}/m68360/gdb6
	${INSTALL_DATA_DIR} ${EGDIR}/m68360/gdb7

	${INSTALL_DATA} ${DOCWRKDIR}/Readme.doc ${DOCDIR}
	${INSTALL_DATA} ${DOCWRKDIR}/68kasm/* ${DOCDIR}/68kasm
	${INSTALL_DATA} ${DOCWRKDIR}/Manual/Readme.doc ${DOCDIR}/Manual
	${INSTALL_DATA} ${DOCWRKDIR}/Manual/ps/* ${DOCDIR}/Manual/ps
	${INSTALL_DATA} ${DOCWRKDIR}/Manual/html/* ${DOCDIR}/Manual/html

	${INSTALL_DATA} ${EGWRKDIR}/m68000/* ${EGDIR}/m68000
	${INSTALL_DATA} ${EGWRKDIR}/m68360/gas1/* ${EGDIR}/m68360/gas1
	${INSTALL_DATA} ${EGWRKDIR}/m68360/gcc2/* ${EGDIR}/m68360/gcc2
	${INSTALL_DATA} ${EGWRKDIR}/m68360/gcc3/* ${EGDIR}/m68360/gcc3
	${INSTALL_DATA} ${EGWRKDIR}/m68360/gcc4/* ${EGDIR}/m68360/gcc4
	${INSTALL_DATA} ${EGWRKDIR}/m68360/gcc5/* ${EGDIR}/m68360/gcc5
	${INSTALL_DATA} ${EGWRKDIR}/m68360/gdb6/* ${EGDIR}/m68360/gdb6
	${INSTALL_DATA} ${EGWRKDIR}/m68360/gdb7/* ${EGDIR}/m68360/gdb7

.include "../../mk/bsd.pkg.mk"
