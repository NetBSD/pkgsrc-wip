# $NetBSD: Makefile,v 1.6 2014/01/25 10:38:22 thomasklausner Exp $

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

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-mxDateTime via py-logilab-common

.include "../../lang/python/egg.mk"
.include "../../devel/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
