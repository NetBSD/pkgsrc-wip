# $NetBSD: Makefile,v 1.1.1.1 2009/03/11 23:46:05 jihbed Exp $
#

DISTNAME=	configobj-4.5.3
PKGNAME=	${PYPKGPREFIX}-configobj-4.5.3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=configobj/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://configobj.sourceforge.net/
COMMENT=	Simple but powerful config file reader and write

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED= 25
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

#PYQ_DOCDIR=	${PREFIX}/share/doc/${PYPKGPREFIX}-configobj


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
