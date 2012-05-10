# $NetBSD: Makefile,v 1.6 2012/05/10 20:11:34 noud4 Exp $

DISTNAME=	fullblogplugin_0.11-r${SVN_REV}
PKGNAME=	trac-plugins-FullBlog-0.1.1pre${SVN_REV}
PKGREVISION=	2
EGG_NAME=	TracFullBlogPlugin-0.1.1
CATEGORIES=	www
MASTER_SITES=	-http://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/FullBlogPlugin
COMMENT=	Blog plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REV=	7969
SVN_MOD=	fullblogplugin/0.11
WRKSRC=		${WRKDIR}/${SVN_MOD}

post-extract:
	find ${WRKSRC} -type f -print | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
