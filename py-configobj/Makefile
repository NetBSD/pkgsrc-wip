# $NetBSD: Makefile,v 1.5 2010/04/16 20:10:32 jihbed Exp $
#

DISTNAME=	configobj-4.7.2.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/c/configobj/
EXTRACT_SUFX=	.gz#md5=201dbaa732a9049c839f9bb6c27fc7b5

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.voidspace.org.uk/python/configobj.html
COMMENT=	Simple but powerful config file reader and write
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/configobj-4.7.2
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED= 26 25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
