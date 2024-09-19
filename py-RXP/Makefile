# $NetBSD: Makefile,v 1.7 2015/07/11 01:49:07 jihbed Exp $

DISTNAME=	pyRXP-2.1.0
PKGNAME=	${PYPKGPREFIX}-rxp-2.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyRXP/}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.reportlab.org/pyrxp.html
COMMENT=	Validating XML parser for Python)

WRKSRC=	${WRKDIR}/pyRXP-2.1.0

MAKE_ENV+=	LIBERROR=0
PYDISTUTILSPKG=	YES

DOCDIR=	${PREFIX}/share/doc/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst  ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
