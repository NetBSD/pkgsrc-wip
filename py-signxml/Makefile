# $NetBSD$

DISTNAME=	signxml-4.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=XML-Security/}
GITHUB_PROJECT=	signxml
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/XML-Security/signxml/
COMMENT=	XML Signature and XAdES in Python
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/${DISTNAME}

# "lxml >= 5.2.1, < 7",  # Ubuntu 24.04 LTS
DEPENDS+=	${PYPKGPREFIX}-lxml>=5.2.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-cryptography>=43.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-certifi>=2023.11.17:../../security/py-certifi

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
