# $NetBSD: Makefile,v 1.1.1.1 2008/01/23 07:53:01 obache Exp $
#

DISTNAME=	Babel-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/babel/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://babel.edgewall.org/
COMMENT=	Collection of tools for internationalizing Python applications

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../wip/pytz

PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
