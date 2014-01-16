# $NetBSD: Makefile,v 1.5 2014/01/16 10:40:57 thomasklausner Exp $

DISTNAME=	0.1.5
PKG=		ejson
PKGNAME=	${PYPKGPREFIX}-${PKG}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/Yipit/ejson/archive/
DIST_SUBDIR=	${PKG}-${DISTNAME}
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Yipit/ejson/
COMMENT=	Extensible JSON serializers and deserializers
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

WRKSRC=		${WRKDIR}/${PKG}-${PKGVERSION}
USE_LANGUAGES=	# none
EGG_NAME=	${PKG}-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
