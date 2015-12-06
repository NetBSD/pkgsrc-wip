# $NetBSD: Makefile,v 1.7 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=	moeclock
PKGNAME=	${DISTNAME}-1.2.0.2
CATEGORIES=	time
MASTER_SITES=	http://moeclock.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/moeclock/
COMMENT=	Wallpaper changing clock
LICENSE=	gnu-gpl-v3 #AND cc-by-v3.0
# The time signal voice must not be modified and distributed separately.

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-gnome2-[0-9]*:../../x11/py-gnome2

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-ORBit via py-gnome2, py-gtk2

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing dynamic python
SUBST_FILES.fix-python+=	moeclock.py
SUBST_FILES.fix-python+=	moeclock
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'
SUBST_SED.fix-python+=		-e 's,python ,${PYTHONBIN} ,'
SUBST_SED.fix-python+=		-e 's,/usr/share,${PREFIX}/share,'

SUBST_CLASSES+=			prefix
SUBST_STAGE.prefix=		pre-configure
SUBST_MESSAGE.prefix=		Fixing pkgsrc prefix
SUBST_FILES.prefix+=		moeclock.desktop
SUBST_SED.prefix+=		-e 's,@PREFIX@,${PREFIX},'

CHECK_INTERPRETER_SKIP+=	share/applications/moeclock.desktop

pre-configure:
	${ECHO} "#F366FF" > ${WRKSRC}/default/color_setting.txt
	${ECHO} "#86cecb" > ${WRKSRC}/mikunchu/color_setting.txt

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
