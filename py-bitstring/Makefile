# $NetBSD: Makefile,v 1.7 2009/08/28 10:46:43 jihbed Exp $
#

DISTNAME=	bitstring-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://python-bitstring.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/python-bitstring/
COMMENT=	Tools for analysis and modification of binary data in python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED= 26 25 24
PYDISTUTILSPKG=	yes

DOCDIR=		${PREFIX}/share/doc/py-bitstring

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/bitstring_manual.pdf ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
