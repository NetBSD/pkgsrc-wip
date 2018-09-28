# $NetBSD$

DISTNAME=	schily-2018-09-26
PKGNAME=	smake-1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michael.baeuerle@gmx.net
COMMENT=	Highly portable UNIX make implementation
LICENSE=	cddl-1.0

MAKE_JOBS_SAFE=	no
MAKE_FLAGS+=	GMAKE_NOWARN=true

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

# Platform specific code (for sharing with other packages based on schilytools)
.include "../../wip/smake/Makefile.common"

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	smake/smake.1
SUBST_SED.man=		-e "s,/opt/schily/share/lib/smake/defaults.smk,${PREFIX}/share/lib/smake/defaults.smk,g"
SUBST_MESSAGE.man=	Fix path for default rules in manpage.

do-configure:
	cd ${WRKSRC}/inc && ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC}/libschily && ${MAKE_PROGRAM} ${MAKE_FLAGS}
	cd ${WRKSRC}/smake && ${MAKE_PROGRAM} ${MAKE_FLAGS}

# Documentation is in ${WRKSRC}/README.compile
do-install:
	cd ${WRKSRC}/smake && ${MAKE_PROGRAM} ${MAKE_FLAGS}		\
		INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}	\
			DESTDIR=${DESTDIR} install

.include "../../mk/bsd.pkg.mk"
