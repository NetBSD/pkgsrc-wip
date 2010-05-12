# $NetBSD: Makefile,v 1.1.1.1 2010/05/12 16:08:56 jihbed Exp $
#

VERS=	2.1.1
DISTNAME=	yapps${VERS}
PKGNAME=	${PYPKGPREFIX}-yapps2-${VERS}
CATEGORIES=	textproc python
MASTER_SITES=	http://theory.stanford.edu/~amitp/yapps/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://theory.stanford.edu/~amitp/yapps/
COMMENT=	Yet Another Python Parser System
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Yapps-2.1.1
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
