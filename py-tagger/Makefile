# $NetBSD: Makefile,v 1.5 2010/10/27 18:10:04 shattered Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_INCOMPATIBLE=\
			15 20 21 22

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
