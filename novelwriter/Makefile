# $NetBSD$

DISTNAME=		novelWriter-2.7.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=		editors python
MASTER_SITES=		${MASTER_SITE_GITHUB:=vkbo/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://novelwriter.io/
COMMENT=		Plain text editor for novels
LICENSE=		gnu-gpl-v3 AND apache-2.0 AND cc-by-v4.0

WRKSRC=			${WRKDIR}/${DISTNAME}

TOOL_DEPENDS+=		${PYPKGPREFIX}-setuptools>=77:../../devel/py-setuptools

DEPENDS+=		${PYPKGPREFIX}-qt6>=6.4:../../x11/py-qt6
DEPENDS+=		${PYPKGPREFIX}-enchant>=3.0.0:../../textproc/py-enchant

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
