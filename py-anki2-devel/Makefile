# $NetBSD: Makefile,v 1.42 2018/03/11 18:08:28 wiz Exp $

DISTNAME=	anki-2.1.0beta37-source
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/anki/anki2/:C/-source//}
CATEGORIES=	misc x11
MASTER_SITES=	https://apps.ankiweb.net/downloads/beta/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://ankisrs.net/
COMMENT=	Flashcard learning program (v2)
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-audio-[0-9]*:../../audio/py-audio
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator

WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}

.include "options.mk"

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/pixmaps share/applications

REPLACE_PYTHON=		runanki tools/runanki.system

USE_TOOLS+=		bash:run

REPLACE_BASH=		tools/tests.sh tools/build_ui.sh

SUBST_CLASSES+=		inst
SUBST_SED.inst+=	-e 's,/usr/share/anki,${PREFIX}/share/anki,'
SUBST_FILES.inst+=	tools/runanki.system anki/lang.py
SUBST_STAGE.inst=	pre-build
SUBST_MESSAGE.inst=	Fixing installation path.

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_FILES.man+=	Makefile
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing path to man page directory.

MAKE_FLAGS+=		PREFIX=${PREFIX} DESTDIR=${DESTDIR}

post-extract:
	${RM} -rf ${WRKSRC}/libanki/thirdparty

# due to patch-Makefile
post-install:
	rm ${DESTDIR}${PREFIX}/share/anki/Makefile.orig

.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
