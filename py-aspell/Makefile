# $NetBSD: Makefile,v 1.3 2009/02/15 13:53:33 kralian Exp $
#

DISTNAME=	aspell-python1.11
PKGNAME=	${PYPKGPREFIX}-aspell-1.11
CATEGORIES=	textproc python
MASTER_SITES=	http://www.wmula.republika.pl/proj/aspell-python/download/

COMMENT=	Python wrapper for GNU Aspell
HOMEPAGE=	http://www.wmula.republika.pl/proj/aspell-python/
MAINTAINER=	pkgsrc-users@NetBSD.org

PYDISTUTILSPKG=	yes

WRKSRC=	${WRKDIR}/aspell-python

HTMLDIR=	share/doc/html/aspell-python

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/${HTMLDIR}

.include "../../textproc/aspell/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
