# $NetBSD: Makefile,v 1.3 2010/07/09 18:39:17 jihbed Exp $
#

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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
