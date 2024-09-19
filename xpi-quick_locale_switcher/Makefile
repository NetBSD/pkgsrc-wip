# $NetBSD: Makefile,v 1.6 2012/10/07 20:11:10 asau Exp $
#

DISTNAME=	quick_locale_switcher-1.7.8
PKGNAME=	xpi-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=addons/1333/}
EXTRACT_SUFX=	-tb+fx+sm.xpi

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://addons.mozilla.org/en-US/firefox/addon/quick-locale-switcher/
COMMENT=	Quickly change the locale preference in Mozilla applications
LICENSE=	mpl-1.1

NO_BUILD=	yes

USE_TOOLS+=	pax unzip

EXTRACT_OPTS+=	-f zip
EXTRACT_DIR=	${WRKSRC}

XPI_APPS=		firefox firefox10 firefox36
XPI_APPS+=		thunderbird thunderbird10
XPI_APPS+=		seamonkey
XPI_ID=			{25A1388B-6B18-46c3-BEBA-A81915D0DE8F}
XPI_DIR=		lib/xpi/extensions/${XPI_ID}

INSTALLATION_DIRS+=	${XPI_DIR}

SUBST_CLASSES+=		gui
SUBST_STAGE.gui=	pre-configure
SUBST_MESSAGE.gui=	Change GUI locale by default
SUBST_FILES.gui+=	defaults/preferences/prefs.js
SUBST_SED.gui+=		-e 's/pref("extensions.qls.switch_gulocale", false);/pref("extensions.qls.switch_gulocale", true);/'

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/${XPI_DIR}
.for app in ${XPI_APPS}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/${app}/extensions
	${LN} -sf ${PREFIX}/${XPI_DIR} ${DESTDIR}${PREFIX}/lib/${app}/extensions/${XPI_ID}
.endfor

.include "../../mk/bsd.pkg.mk"
