# $NetBSD: Makefile,v 1.2 2015/06/10 13:43:17 ahp-nils Exp $

DISTNAME=	pymailq-0.5.3
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pymailq/mailq/}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=outini/}
GITHUB_PROJECT=	pymailq
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/outini/pymailq
COMMENT=	Postfix queue control python tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
