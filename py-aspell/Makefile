# $NetBSD: Makefile,v 1.4 2009/05/27 22:41:29 jihbed Exp $
#

DISTNAME=	aspell-python1.11
PKGNAME=	${PYPKGPREFIX}-aspell-1.11
CATEGORIES=	textproc python
MASTER_SITES=	http://wm.ite.pl/proj/aspell-python/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wm.ite.pl/proj/aspell-python/index-c.html
COMMENT=	Python wrapper for GNU Aspell
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT= user-destdir

WRKSRC=	${WRKDIR}/aspell-python

PYDISTUTILSPKG=	yes

HTMLDIR=	${PREFIX}/share/doc/html/aspell-python

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DESTDIR}/${HTMLDIR}


.include "../../textproc/aspell/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
