# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	wahcade-0.99pre8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	http://www.anti-particle.com/projects/wahcade/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.anti-particle.com/wahcade.shtml
COMMENT=	GNU/Linux-friendly clone of Minwah's MameWAH
LICENSE=	gnu-gpl-v2

WRKSRC=				${WRKDIR}/wahcade
USE_PKGLOCALEDIR=		yes
USE_LANGUAGES=			# none
USE_TOOLS+=			bash
PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-imaging

REPLACE_BASH+=		doc/samples/run_mess.sh
REPLACE_PYTHON+=	*.py

SUBST_CLASSES+=		share
SUBST_FILES.share=	constants.py
SUBST_MESSAGE.share=	Fixing DATADIR.
SUBST_SED.share=	-e "s|os.getcwd()|'${PREFIX}/share/games/wahcade/'|1"
SUBST_STAGE.share=	post-patch

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} && ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} && \
		${PYTHONBIN} setup.py install --root=${DESTDIR}

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/wahcade*.py
	${LN} -fs ${DESTDIR}${PREFIX}/share/games/wahcade/wahcade.py \
		${DESTDIR}${PREFIX}/bin/wahcade
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/applications/wahcade*.desktop
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/games/wahcade/glade2.py

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
.include "../../devel/py-game/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
