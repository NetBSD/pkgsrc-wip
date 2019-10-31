# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=avian2/}
GITHUB_PROJECT=	unidecode
GITHUB_TAG=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tablix.org/~avian/git/
COMMENT=	ASCII transliterations of Unicode text
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

EGG_NAME=	Unicode-${PKGVERSION_NOREV}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
