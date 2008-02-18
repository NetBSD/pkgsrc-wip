# $NetBSD: Makefile,v 1.2 2008/02/18 13:40:48 obache Exp $
#

DISTNAME=	Babel-0.9.2
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
