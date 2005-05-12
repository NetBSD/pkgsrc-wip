# $NetBSD: Makefile,v 1.5 2005/05/12 15:20:18 minskim Exp $
#

DISTNAME=		xbelmark.py
PKGNAME=		xbelmark-20040924
CATEGORIES=		textproc www
MASTER_SITES=		http://www.stud.uni-hamburg.de/users/lennart/projects/xbelmark/
EXTRACT_SUFX=		# nothing to extract

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.stud.uni-hamburg.de/users/lennart/projects/xbelmark/
COMMENT=		XBEL XML bookmarks to readable HTML converter

DEPENDS=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

WRKSRC=			${WRKDIR}
NO_BUILD=		YES

PYTHON_VERSIONS_INCOMPATIBLE=	21 20 15
PYTHON_PATCH_SCRIPTS=	xbelmark.py

do-extract:
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xbelmark
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/xbelmark/
	${INSTALL_SCRIPT} ${WRKSRC}/xbelmark.py ${PREFIX}/bin/xbelmark.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
