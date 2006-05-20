# $NetBSD: Makefile,v 1.1.1.1 2006/05/20 07:02:51 yomram Exp $
#

DISTNAME=	aspell-python1.11
PKGNAME=	${PYPKGPREFIX}-aspell-1.11
CATEGORIES=	textproc python
MASTER_SITES=	http://www.republika.pl/wmula/proj/aspell-python/

COMMENT=	Python wrapper for GNU Aspell
HOMEPAGE=	http://www.republika.pl/wmula/proj/aspell-python/
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
