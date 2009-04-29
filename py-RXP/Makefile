# $NetBSD: Makefile,v 1.5 2009/04/29 00:38:02 jihbed Exp $
#

DISTNAME=	pyRXP-1.13-daily-unix
PKGNAME=	${PYPKGPREFIX}-rxp-1.13
CATEGORIES=	textproc
MASTER_SITES=	http://www.reportlab.org/daily/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.reportlab.org/pyrxp.html
COMMENT=	Validating XML parser for Python

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/pyRXP-1.13
MAKE_ENV+=	LIBERROR=0
PYDISTUTILSPKG=	YES

DOCDIR=	${PREFIX}/share/doc/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
