# $NetBSD: Makefile,v 1.4 2011/02/25 09:47:49 thomasklausner Exp $
#

DISTNAME=	pyparsing-1.5.2
PKGNAME=	${PYPKGPREFIX}-parsing-1.5.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyparsing/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pyparsing.wikispaces.com/
COMMENT=	General parsing module for Python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes
PY_PATCHPLIST=		yes

PYTHON_VERSIONS_ACCEPTED=  27 26 25 24

INSTALLATION_DIRS+=	share/doc/pyparsing share/doc/html/pyparsing share/examples/pyparsing

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${DESTDIR}${PREFIX}/share/doc/pyparsing
	${INSTALL_DATA} ${WRKSRC}/*.html ${DESTDIR}${PREFIX}/share/doc/pyarsing
	${INSTALL_DATA} ${WRKSRC}/htmldoc/* ${DESTDIR}${PREFIX}/share/doc/html/pyparsing
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/examples/pyparsing

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
