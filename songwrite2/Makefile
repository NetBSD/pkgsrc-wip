# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:52 thomasklausner Exp $

DISTNAME=	Songwrite2-0.4.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/songwrite/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.gna.org/oomadness/en/songwrite/
COMMENT=	Music score and songbook editor
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

USE_PKGLOCALEDIR=		yes
USE_LANGUAGES=			# none
BUILD_OPTIONS=			# blank
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2, py-EditObj2

#INSTALLATION_DIRS+=	share/doc/${PKGBASE} share/locale/en/LC_MESSAGES/
#INSTALLATION_DIRS+=	share/locale/fr/LC_MESSAGES share/${PKGBASE}
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	main.py setup.cfg
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/|${PREFIX}/|g"
SUBST_STAGE.prefix=	pre-configure

.include "options.mk"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build ${BUILD_OPTIONS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py install --root=${DESTDIR} --prefix=${PREFIX}
	${INSTALL_MAN} ${WRKSRC}/manpage/man1/songwrite2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../print/evince/buildlink3.mk"
DEPENDS+=	timidity-[0-9]*:../../audio/timidity
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-EditObj2-[0-9]*:../../wip/py-EditObj2
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
