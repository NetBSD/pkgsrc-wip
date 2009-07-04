# $NetBSD: Makefile,v 1.5 2009/07/04 16:03:29 jihbed Exp $
#

DISTNAME=	bitstring-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://python-bitstring.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://python-bitstring.googlecode.com/
COMMENT=	Tools for analysis and modification of binary data in python
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PYDISTUTILSPKG=	yes


DOCDIR=		${PREFIX}/share/doc/py-bitstring

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/bitstring.pdf ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
