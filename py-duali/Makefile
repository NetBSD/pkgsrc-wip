# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	duali-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://switch.dl.sourceforge.net/project/arabeyes/Duali/0.1.1/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.arabeyes.org/project.php?proj=duali
COMMENT=	The Arabic Spellchecker
#LICENSE=	modified-bsd

#DEPENDS+=	duali-data>=1.0:../../wip/duali-data

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/share/duali,${PREFIX}/share/duali,g'
SUBST_SED.paths+=	-e 's,/etc,${PREFIX}/etc,g'
SUBST_FILES.paths+=	setup.py duali.conf
SUBST_MESSAGE.paths=	Fixing header search paths.

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24 23
PYDISTUTILSPKG= yes

INSTALLATION_DIRS=	share/doc/py-duali ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/py-duali
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/py-duali


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
