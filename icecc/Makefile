# $NetBSD: Makefile,v 1.1.1.1 2004/08/28 10:05:43 plunky Exp $

# Package version reflects icecc version, with PKGREVISION incremented
# for any tool updates, according to the authors scheme.
DISTNAME=		icecc-2.9
PKGREVISION=		1
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=icecc/}
DISTFILES=		icecc-2.9.tar.bz2		\
			icebgset-1.3.tar.bz2		\
			icecursorscfg-0.6.tar.bz2	\
			iceked-1.5.tar.bz2		\
			iceiconcvt-1.0.tar.bz2		\
			icemergeprefs-0.5.tar.bz2	\
			icemc-2.1.tar.bz2		\
			icerrun-0.5.tar.bz2		\
			icesndcfg-1.3.tar.bz2		\
			icets-1.4.tar.bz2		\
			icewm4vim.tar.bz2		\
			icewoed-1.8.tar.bz2

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://icecc.sourceforge.net/
COMMENT=		IceWM Control Centre

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}

QSRC=			icecc-2.9 icebgset-1.3 iceked-1.5 icemc-2.1
QSRC+=			icesndcfg-1.3 icets-1.4 icewoed-1.8

PYTHON_PATCH_SCRIPTS=	icecursorscfg-0.6/icecurcfg.py iceiconcvt-1.0/iceiconcvt.py
PYTHON_PATCH_SCRIPTS+=	icemergeprefs-0.5/icemergeprefs.py icerrun-0.5/icerrrun.py
PYTHON_PATCH_SCRIPTS+=	icerrun-0.5/icerrun.py

SUBST_CLASSES=		path
SUBST_STAGE.path=	patch
SUBST_FILES.path=	icebgset-1.3/icebgset.pro icecc-2.9/icecc.pro iceked-1.5/iceked.pro
SUBST_FILES.path+=	icemc-2.1/icemc.pro icesndcfg-1.3/icesndcfg.pro icets-1.4/icets.pro
SUBST_FILES.path+=	icewoed-1.8/icewoed.pro
SUBST_FILES.path+=	icecursorscfg-0.6/icecurcfg.py iceiconcvt-1.0/iceiconcvt.py
SUBST_FILES.path+=	icemergeprefs-0.5/icemergeprefs.py
SUBST_SED.path=		"s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.path=	"Fixing hardcoded paths."

BUILD_DIRS=		${QSRC:S/^/${WRKSRC}\//}

do-configure:
.   for dir in ${QSRC}
	cd ${WRKSRC}/${dir} && ${QTDIR}/bin/qmake "QMAKE_MKDIR=${MKDIR}" "QMAKE_CHK_DIR_EXISTS=${TEST} -d"
.   endfor

post-install:
.   for script in ${PYTHON_PATCH_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${PREFIX}/bin
.   endfor

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
