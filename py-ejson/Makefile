# $NetBSD: Makefile,v 1.1 2013/06/07 22:28:00 othyro Exp $
#

DISTNAME=	0.1.5
PKGNAME=	${PYPKGPREFIX}-ejson-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/Yipit/ejson/archive/
DIST_SUBDIR=	ejson-${DISTNAME}
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Yipit/ejson/
COMMENT=	Extensible JSON serializers and deserializers
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/ejson-${PKGVERSION}
USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
