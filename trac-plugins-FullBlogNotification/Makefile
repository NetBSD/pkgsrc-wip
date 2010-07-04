# $NetBSD: Makefile,v 1.2 2010/07/04 19:39:18 rsmarples Exp $

DISTNAME=	fullblognotification_0.11-r${SVN_REV}
PKGNAME=	trac-plugins-FullBlogNotification-0.1pre${SVN_REV}
PKGREVISION=	# blank on purpose even though pkglint moans
EGG_NAME=	TracFullBlogNotification-0.1dev
CATEGORIES=	www
MASTER_SITES=	-http://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/FullBlogNotificationPlugin
COMMENT=	E-mail Notification for the FullBlog plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	trac-plugins-FullBlog>=0.1pre6158:../../wip/trac-plugins-FullBlog

SVN_REV=	7463
SVN_MOD=	fullblognotificationplugin/0.11
WRKSRC=		${WRKDIR}/${SVN_MOD}

post-extract:
	find ${WRKSRC} -type f | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
