# $NetBSD: Makefile,v 1.2 2012/01/30 06:16:26 noud4 Exp $
#

DISTNAME=	fs-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://pyfilesystem.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/pyfilesystem/
COMMENT=	Creates a common interface to filesystems
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT= user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
