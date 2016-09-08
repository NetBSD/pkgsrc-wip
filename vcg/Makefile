# $NetBSD: Makefile,v 1.20 2015/07/04 16:18:36 joerg Exp $

DISTNAME=	vcg.1.30.r3.17
PKGNAME=	vcg-1.30
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Visualization Tool for compiler graphs

LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/vcg.1.30
USE_TOOLS+=	imake lex

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		install
SUBST_STAGE.install=	post-patch
SUBST_SED.install=	-e 's|/bin/install|/usr/bin/install|g'
SUBST_FILES.install=	${WRKSRC}/preconf/X11cc${OPSYS}/conf

SUBST_CLASSES+=		sed
SUBST_STAGE.sed=	post-patch
SUBST_SED.sed=		-e 's|/usr/bin/sed|/bin/sed|g'
SUBST_FILES.sed=	${WRKSRC}/preconf/X11cc${OPSYS}/conf
SUBST_FILES.sed+=	${WRKSRC}/preconf/X11cc${OPSYS}/demo.csh
SUBST_FILES.sed+=	${WRKSRC}/preconf/X11cc${OPSYS}/tMakefile

SUBST_CLASSES+=		touch
SUBST_STAGE.touch=	post-patch
SUBST_SED.touch=	-e 's|/usr/bin/touch|/bin/touch|g'
SUBST_FILES.touch=	${WRKSRC}/preconf/X11cc${OPSYS}/conf
SUBST_FILES.touch+=	${WRKSRC}/preconf/X11cc${OPSYS}/demo.csh
SUBST_FILES.touch+=	${WRKSRC}/preconf/X11cc${OPSYS}/tMakefile

.endif

pre-patch:
	${MKDIR} ${WRKSRC}/preconf/X11cc${OPSYS}
	${CP} ${FILESDIR}/conf ${WRKSRC}/preconf/X11cc${OPSYS}
	${CP} ${FILESDIR}/demo.csh ${WRKSRC}/preconf/X11cc${OPSYS}
	${CP} ${FILESDIR}/globals.h ${WRKSRC}/preconf/X11cc${OPSYS}
	${CP} ${FILESDIR}/tMakefile ${WRKSRC}/preconf/X11cc${OPSYS}

INSTALLATION_DIRS+=	share/doc/vcg share/examples/vcg

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/visual.ps ${DESTDIR}${PREFIX}/share/doc/vcg
	${INSTALL_DATA} ${WRKSRC}/expl/*.vcg ${DESTDIR}${PREFIX}/share/examples/vcg

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
