# $NetBSD: Makefile,v 1.17 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=		PyPE1.8.2
PKGNAME=		${PYPKGPREFIX}-PyPE-1.8.2
PKGREVISION=		1
WRKSRC=			${WRKDIR}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pype/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pype.sourceforge.net/
COMMENT=		Lightweight, but powerful editor for Python

DEPENDS=	${PYPKGPREFIX}-wxWidgets>=2.4.2.4:../../x11/py-wxWidgets

REPLACE_PYTHON=	pype.py
NO_BUILD=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-wxWidgets

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PYSITELIB}/pype
	${INSTALL_DATA} ${WRKSRC}/configuration.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}/pype/configuration.py
	${INSTALL_DATA} ${WRKSRC}/parsers.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}/pype/parsers.py
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/${PYSITELIB}/pype/readme.txt
	${INSTALL_DATA} ${FILESDIR}/__init__.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}/pype/__init__.py
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pype.py ${DESTDIR}${PREFIX}/bin/pype.py-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
