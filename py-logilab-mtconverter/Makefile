# $NetBSD: Makefile,v 1.8 2014/12/05 17:23:17 othyro Exp $

DISTNAME=	logilab-mtconverter-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	logilab_mtconverter-0.8.0
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	http://ftp.logilab.org/pub/mtconverter/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-mtconverter
COMMENT=	Library convert from a MIME type to another
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-logilab-common>=0.53.0:../../devel/py-logilab-common

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-mxDateTime via py-logilab-common

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
