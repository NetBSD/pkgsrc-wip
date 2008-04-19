# $NetBSD: Makefile,v 1.2 2008/04/19 20:24:41 mj_turner Exp $

DISTNAME=	httplib2-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://httplib2.googlecode.com/files/

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	http://code.google.com/p/httplib2/
COMMENT=	Comprehensive http client library for Python

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	24 23

# Install README manually
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
