# $NetBSD: Makefile,v 1.1.1.1 2011/05/31 00:50:56 mrampke Exp $

DISTNAME=		tipp10_source_v2-1-0
EXTRACT_SUFFIX=		.zip
DISTFILES=		${DISTNAME}${EXTRACT_SUFFIX}
PKGVERSION=		2.1.0
PKGNAME=		tipp10-${PKGVERSION}
CATEGORIES=		games
MASTER_SITES=		http://2pktfkt.de/pkgsrc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tipp10.com/
COMMENT=		Touch typing tutor
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES+=		c++

.include		 "../../x11/qt4-libs/buildlink3.mk"
.include		 "../../x11/qt4-tools/buildlink3.mk"
DEPENDS+=		qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing data directory paths
SUBST_FILES.paths=	main.cpp sql/connection.h sql/lessontablesql.cpp \
    			widget/downloaddialog.cpp widget/fingerwidget.cpp widget/helpbrowser.cpp \
			widget/illustrationdialog.cpp widget/keyboard.cpp widget/lessonresult.cpp \
			widget/licensedialog.cpp widget/mainwindow.cpp widget/numpad.cpp \
			widget/progressionwidget.cpp widget/regexpdialog.cpp widget/settingsdialog.cpp \
			widget/settingsdialogx.cpp widget/settingspages.cpp widget/startwidget.cpp \
			widget/tickerboard.cpp widget/trainingwidget.cpp widget/txtmessagedialog.cpp \
			widget/updatedialog.cpp
SUBST_SED.paths=	-e 's,QCoreApplication::applicationDirPath(),QString("${PREFIX}/share/tipp10"),g'

do-configure:
	cd ${WRKSRC}; env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	${INSTALL} ${WRKSRC}/tipp10 ${DESTDIR}${PREFIX}/bin/tipp10
	mkdir -p ${DESTDIR}${PREFIX}/share/tipp10
	cp -R ${WRKSRC}/release/help ${WRKSRC}/release/tipp10v2.template ${WRKSRC}/metronome.wav ${WRKSRC}/metronome.aif ${WRKSRC}/error.aif ${WRKSRC}/img ${DESTDIR}${PREFIX}/share/tipp10


.include "../../mk/bsd.pkg.mk"
