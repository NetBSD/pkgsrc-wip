# $NetBSD$
#

DISTNAME=		vym-2.8.8
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vym/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.insilmaril.de/vym/
COMMENT=		Generate and manipulate maps which show your thoughts
LICENSE=		gnu-gpl-v2

EXTRACT_USING=		bsdtar

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
DEPENDS+=		zip-[0-9]*:../../archivers/zip

USE_LANGUAGES=		c++
USE_TOOLS+=		perl:run bash:run gzip

REPLACE_BASH+=		scripts/makedist-vym scripts/vivym
REPLACE_BASH+=		scripts/getbinaries scripts/screencast

REPLACE_RUBY+=		scripts/jigger
REPLACE_RUBY+=		scripts/make-qrc.rb

CHECK_INTERPRETER_SKIP=	share/vym/scripts/bugger \
			share/vym/scripts/vym-addmail.rb

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/vym

SUBST_CLASSES+=		flags
SUBST_STAGE.flags=	pre-configure
SUBST_MESSAGE.flags=	Fix path to flags
SUBST_FILES.flags=	src/exportoofiledialog.cpp src/main.cpp src/mainwindow.cpp
SUBST_VARS.flags=	PREFIX

SUBST_CLASSES+=		man-bin
SUBST_STAGE.man-bin=	post-build
SUBST_MESSAGE.man-bin=	Fixing bin path in man page
SUBST_FILES.man-bin=	doc/vym.1
SUBST_SED.man-bin=	-e 's;/usr/bin/;${PREFIX}/bin/;g'

SUBST_CLASSES+=		man-doc
SUBST_STAGE.man-doc=	post-build
SUBST_MESSAGE.man-doc=	Fixing doc path in man page
SUBST_FILES.man-doc=	doc/vym.1
SUBST_SED.man-doc=	-e 's;/usr/share/doc/packages/vym;${PREFIX}/share/doc/vym;g'

post-extract:
	${CHMOD} a-x ${WRKSRC}/icons/vym.ico
	${GZIP_CMD} -d ${WRKSRC}/doc/vym.1.gz

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QTDIR}/bin/qmake -unix \
		PREFIX=${PREFIX} \
		BINDIR=${PREFIX}/bin \
		DATADIR=${PREFIX}/share/vym \
		DOCDIR=${PREFIX}/share/doc/vym vym.pro

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/vym.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/vym.pdf ${DESTDIR}${PREFIX}/share/doc/vym
	${INSTALL_DATA} ${WRKSRC}/doc/vym_es.pdf ${DESTDIR}${PREFIX}/share/doc/vym
	${INSTALL_DATA} ${WRKSRC}/doc/vym_fr.pdf ${DESTDIR}${PREFIX}/share/doc/vym

.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
