# $NetBSD: Makefile,v 1.8 2010/05/22 13:22:31 obache Exp $

DISTNAME=	accountmanagerplugin_0.11-r${SVN_REV}
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

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REV=	7731
SVN_MOD=	accountmanagerplugin/0.11
WRKSRC=		${WRKDIR}/${SVN_MOD}

post-extract:
	find ${WRKSRC} -type f -print | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
