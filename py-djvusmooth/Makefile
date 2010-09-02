# $NetBSD: Makefile,v 1.2 2010/09/02 20:29:05 ryo-on Exp $
#

DISTNAME=	djvusmooth-0.2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics textproc
MASTER_SITES=	http://pypi.python.org/packages/source/d/djvusmooth/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://jwilk.net/software/djvusmooth
COMMENT=	Graphical editor for DjVu documents
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-xdg:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-wxWidgets:../../x11/py-wxWidgets
DEPENDS+=	${PYPKGPREFIX}-djvulibre:../../wip/py-djvulibre
DEPENDS+=	djvulibre-tools:../../graphics/djvulibre-tools

PYTHON_VERSIONS_ACCEPTED=	26 25
PYDISTUTILSPKG=	yes

MANFILES=	djvusmooth.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${MANFILES:Q} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
