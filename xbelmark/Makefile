NetBSD $NetBSD: Makefile,v 1.2 2003/12/30 20:03:00 cjep Exp $
#

DISTNAME=		xbelmark.py
PKGNAME=		xbelmark-20030119
WRKSRC=			${WRKDIR}
CATEGORIES=		textproc www
MASTER_SITES=		http://www.stud.uni-hamburg.de/users/lennart/projects/xbelmark/
EXTRACT_SUFX=		# nothing to extract

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.stud.uni-hamburg.de/users/lennart/projects/xbelmark/
COMMENT=		XBEL XML bookmarks to readable HTML converter

DEPENDS=		py23-expat-[0-9]*:../../textproc/py-expat

NO_BUILD=		YES

PYTHON_VERSIONS_ACCEPTED=	22 22pth 23 23pth
PYTHON_PATCH_SCRIPTS=	xbelmark.py

do-extract:
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xbelmark
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/xbelmark/
	${INSTALL_SCRIPT} ${WRKSRC}/xbelmark.py ${PREFIX}/bin/xbelmark.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
