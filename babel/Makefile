# $NetBSD: Makefile,v 1.3 2008/05/22 15:38:46 tnn2 Exp $
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
