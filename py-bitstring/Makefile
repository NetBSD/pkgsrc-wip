# $NetBSD: Makefile,v 1.11 2012/10/06 17:22:16 asau Exp $
#

DISTNAME=	bitstring-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://python-bitstring.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/python-bitstring/
COMMENT=	Tools for analysis and modification of binary data in python
LICENSE=	mit


USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26

PYDISTUTILSPKG=	yes

DOCDIR=		${PREFIX}/share/doc/py-bitstring

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/bitstring_manual.pdf ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
