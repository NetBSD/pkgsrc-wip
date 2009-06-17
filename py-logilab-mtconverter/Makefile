# $NetBSD: Makefile,v 1.1.1.1 2009/06/17 23:32:42 jihbed Exp $
#

DISTNAME=	logilab-mtconverter-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	http://ftp.logilab.org/pub/mtconverter/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-mtconverter
COMMENT=	Library convert from a MIME type to another
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
