# $NetBSD: Makefile,v 1.4 2012/10/07 17:17:46 asau Exp $

DISTNAME=	fullblognotification_0.11-r${SVN_REV}
PKGNAME=	trac-plugins-FullBlogNotification-0.1pre${SVN_REV}
PKGREVISION=	1
EGG_NAME=	TracFullBlogNotificationPlugin-0.1
CATEGORIES=	www
MASTER_SITES=	-https://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	https://trac-hacks.org/wiki/FullBlogNotificationPlugin
COMMENT=	E-mail Notification for the FullBlog plugin for Trac

DEPENDS+=	trac-plugins-FullBlog>=0.1pre6158:../../wip/trac-plugins-FullBlog

SVN_REV=	7463
SVN_MOD=	fullblognotificationplugin/0.11
WRKSRC=		${WRKDIR}/${SVN_MOD}

post-extract:
	find ${WRKSRC} -type f | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
