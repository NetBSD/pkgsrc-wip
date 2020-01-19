# $NetBSD: Makefile,v 1.12 2012/10/16 09:40:27 jihbed Exp $
#

DISTNAME=	bitstring-3.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitstring/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://scott-griffiths.github.io/bitstring/
COMMENT=	Tools for analysis and modification of binary data in python
LICENSE=	mit


USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

DOCDIR=		${PREFIX}/share/doc/py-bitstring

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/bitstring_manual.pdf ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
