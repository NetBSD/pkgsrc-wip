# $NetBSD$

DISTNAME=	schily-2021-06-07
PKGNAME=	dmake-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/schilytools/
COMMENT=	SunPro parallel make
LICENSE=	cddl-1.0

USE_LANGUAGES=	c c++

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	smake>=1.3nb11:../../devel/smake
SMAKE=		MAKEFLAGS= smake
MAKE_FLAGS+=	DESTDIR=${DESTDIR} INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}
# Honor CPPFLAGS, CFLAGS and LDFLAGS
MAKE_FLAGS+=	CPPOPTX=${CPPFLAGS:Q} COPTX=${CFLAGS:Q} LDOPTX=${LDFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/lib/make

# Shared platform specific code for schilytools (provided by smake package)
.include "../../devel/smake/Makefile.common"

do-configure:
	cd ${WRKSRC}/inc && ${SMAKE} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && for library in libschily libgetopt ;		\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/sunpro && ${SMAKE} ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC}/sunpro && ${INSTALL_PROGRAM}			\
		${WRKSRC}/sunpro/Make/bin/make/common/OBJ/*/make	\
		${DESTDIR}${PREFIX}/bin/dmake
	cd ${WRKSRC}/sunpro && ${INSTALL_MAN}				\
		${WRKSRC}/sunpro/Make/bin/make/common/dmake.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/sunpro && ${INSTALL_DATA}				\
		${WRKSRC}/sunpro/Make/bin/make/common/make.rules.file	\
		${DESTDIR}${PREFIX}/share/lib/make/make.rules

.include "../../mk/bsd.pkg.mk"
