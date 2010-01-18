# $NetBSD: Makefile,v 1.2 2010/01/18 09:38:30 thomasklausner Exp $
#

DISTNAME=	logilab-mtconverter-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
