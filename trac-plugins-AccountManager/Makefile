# $NetBSD: Makefile,v 1.10 2010/08/28 00:45:44 obache Exp $

DISTNAME=	accountmanagerplugin_trnk-r${SVN_REV}
PKGNAME=	trac-plugins-AccountManager-0.2.1pre${SVN_REV}
EGG_NAME=	TracAccountManager-0.2.1dev
CATEGORIES=	www
MASTER_SITES=	-http://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/AccountManagerPlugin
COMMENT=	User account management plugin for Trac
#LICENSE=	THE BEER-WARE LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{,ja-}trac>=0.12:../../www/trac

SVN_REV=	8246
SVN_MOD=	accountmanagerplugin/trunk
WRKSRC=		${WRKDIR}/${SVN_MOD}

post-extract:
	find ${WRKSRC} -type f -print | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
