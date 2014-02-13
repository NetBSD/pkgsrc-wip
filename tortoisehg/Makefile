# $NetBSD: Makefile,v 1.1 2014/02/13 19:05:33 nros Exp $

DISTNAME=		tortoisehg-2.11
CATEGORIES=		devel
MASTER_SITES=		http://bitbucket.org/tortoisehg/targz/downloads/

MAINTAINER=		nros@users.sourceforge.net
HOMEPAGE=		http://tortoisehg.org/
COMMENT=		GUI for Mercurial
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gettext
USE_LANGUAGES=		c
REPLACE_PYTHON+=	thg
PYDISTUTILSPKG=		yes

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.1.3:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-iniparse>=0.4:../../textproc/py-iniparse
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	mercurial>=2.8.1:../../devel/mercurial

pre-configure:
		sed 	-e 's:@PREFIX@:${PREFIX}:g' \
			${FILESDIR}/config.py > \
			${WRKSRC}/tortoisehg/util/config.py

thg_icon=		/share/pixmaps/tortoisehg/icons/thg_logo.ico
SUBST_CLASSES+=		df
SUBST_STAGE.df=		post-configure
SUBST_MESSAGE.df=	Fixing icon reference in desktop file
SUBST_FILES.df=		contrib/thg.desktop
SUBST_SED.df=		-e 's:thg_logo:${PREFIX}${thg_icon}:1'

pre-build:
	cd ${WRKSRC}/doc && ${MAKE_PROGRAM} html
	rm ${WRKSRC}/doc/build/html/.buildinfo
	mv ${WRKSRC}/doc/build/html ${WRKSRC}
	mv ${WRKSRC}/contrib/mergetools.rc ${WRKSRC}
	mv ${WRKSRC}/contrib/thg.desktop ${WRKSRC}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt4-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
