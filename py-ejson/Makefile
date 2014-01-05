# $NetBSD: Makefile,v 1.4 2014/01/05 04:10:07 othyro Exp $
#

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

WRKSRC=		${WRKDIR}/${PKG}-${PKGVERSION}
USE_LANGUAGES=	# none
EGG_NAME=	${PKG}-${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
