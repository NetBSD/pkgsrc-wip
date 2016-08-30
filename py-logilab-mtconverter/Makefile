# $NetBSD: Makefile,v 1.9 2014/12/31 13:58:34 thomasklausner Exp $

DISTNAME=	logilab-mtconverter-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	http://ftp.logilab.org/pub/mtconverter/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-mtconverter
COMMENT=	Library convert from a MIME type to another
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-logilab-common>=0.53.0:../../devel/py-logilab-common

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
