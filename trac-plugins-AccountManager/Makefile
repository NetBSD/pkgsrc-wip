# $NetBSD: Makefile,v 1.12 2012/03/10 14:36:56 obache Exp $

DISTNAME=	accountmanagerplugin_0.11-r${SVN_REV}
PKGNAME=	trac-plugins-AccountManager-0.3.2
EGG_NAME=	TracAccountManager-0.3.2
CATEGORIES=	www
MASTER_SITES=	-http://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/AccountManagerPlugin
COMMENT=	User account management plugin for Trac
#LICENSE=	THE BEER-WARE LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{,ja-}trac>=0.12:../../www/trac
DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-babel>=0.9.5:../../devel/py-babel

SVN_REV=	10618
SVN_MOD=	accountmanagerplugin/0.11
WRKSRC=		${WRKDIR}/${SVN_MOD}

post-extract:
	find ${WRKSRC} -type f -print | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
