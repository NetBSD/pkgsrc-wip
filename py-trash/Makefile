# $NetBSD: Makefile,v 1.1.1.1 2009/04/03 22:21:03 jihbed Exp $
#

DISTNAME=	pytrash-0.2
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	sysutils
MASTER_SITES=	http://pytrash.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/pytrash/
COMMENT=	The command line tool for the GNOME Trash

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
