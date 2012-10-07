# $NetBSD: Makefile,v 1.7 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=		pytagger-0.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		audio python
MASTER_SITES=		http://www.liquidx.net/static/pytagger/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.liquidx.net/pytagger/
COMMENT=		ID3v1 and ID3v2 tag library in Python
LICENSE=		modified-bsd

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

HTMLDIR=	${PREFIX}/share/doc/html/${PKGNAME}

INSTALLATION_DIRS+=	${HTMLDIR}/private ${HTMLDIR}/public

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/html/index.html ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/html/epydoc.css ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/html/private/* ${DESTDIR}${HTMLDIR}/private
	${INSTALL_DATA} ${WRKSRC}/html/private/* ${DESTDIR}${HTMLDIR}/public

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
