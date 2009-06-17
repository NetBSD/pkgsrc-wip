# $NetBSD: Makefile,v 1.2 2009/06/18 00:02:28 jihbed Exp $
#

DISTNAME=	pytrash-0.2
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	sysutils
MASTER_SITES=	http://pytrash.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/pytrash/
COMMENT=	The command line tool for the GNOME Trash

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
