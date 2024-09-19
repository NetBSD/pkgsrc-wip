# $NetBSD: Makefile,v 1.3 2012/12/29 14:54:37 othyro Exp $

DISTNAME=	tipp10_2.1.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	games
# \todo: https://www.tipp10.com/de/download/getfile/3/ is the
# real source. We need a webbrowser user-agent string to get
# this, otherwise we get a 0 length gzip file. This is why we
# are using Debian as a source.
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/tipp10/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tipp10.com/
COMMENT=	Touch typing tutor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c++

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing data directory paths
SUBST_FILES.paths=	main.cpp sql/connection.h sql/lessontablesql.cpp \
			widget/downloaddialog.cpp widget/fingerwidget.cpp \
			widget/helpbrowser.cpp \
			widget/illustrationdialog.cpp \
			widget/keyboard.cpp widget/lessonresult.cpp \
			widget/licensedialog.cpp widget/mainwindow.cpp \
			widget/numpad.cpp widget/progressionwidget.cpp \
			widget/regexpdialog.cpp widget/settingsdialog.cpp \
			widget/settingsdialogx.cpp widget/settingspages.cpp \
			widget/startwidget.cpp \
			widget/tickerboard.cpp widget/trainingwidget.cpp \
			widget/txtmessagedialog.cpp widget/updatedialog.cpp
SUBST_SED.paths=	-e 's,QCoreApplication::applicationDirPath(),QString("${PREFIX}/share/tipp10"),g'

INSTALLATION_DIRS+=	bin share/tipp10/help/de/content
INSTALLATION_DIRS+=	share/tipp10/help/de/img share/tipp10/help/en/content
INSTALLATION_DIRS+=	share/tipp10/help/en/img share/tipp10/img

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tipp10 ${DESTDIR}${PREFIX}/bin/tipp10
	${INSTALL_DATA} ${WRKSRC}/*.aif ${DESTDIR}${PREFIX}/share/tipp10
	${INSTALL_DATA} ${WRKSRC}/metronome.wav ${DESTDIR}${PREFIX}/share/tipp10
	${INSTALL_DATA} ${WRKSRC}/release/tipp10v2.template ${DESTDIR}${PREFIX}/share/tipp10
	${INSTALL_DATA} ${WRKSRC}/release/help/de/content/* ${DESTDIR}${PREFIX}/share/tipp10/help/de/content
	${INSTALL_DATA} ${WRKSRC}/release/help/de/img/* ${DESTDIR}${PREFIX}/share/tipp10/help/de/img
	${INSTALL_DATA} ${WRKSRC}/release/help/de/index.html ${DESTDIR}${PREFIX}/share/tipp10/help/de
	${INSTALL_DATA} ${WRKSRC}/release/help/en/content/* ${DESTDIR}${PREFIX}/share/tipp10/help/en/content
	${INSTALL_DATA} ${WRKSRC}/release/help/en/img/*.png ${DESTDIR}${PREFIX}/share/tipp10/help/en/img
	${INSTALL_DATA} ${WRKSRC}/release/help/en/index.html ${DESTDIR}${PREFIX}/share/tipp10/help/en
	${INSTALL_DATA} ${WRKSRC}/img/* ${DESTDIR}${PREFIX}/share/tipp10/img

DEPENDS+=	qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
