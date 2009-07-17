# $NetBSD: Makefile,v 1.1.1.1 2009/07/17 09:18:16 rsmarples Exp $

DISTNAME=	TracFullBlogNotification-0.1dev
PKGNAME=	trac-plugins-FullBlogNotification-0.1pre5330
PKGREVISION=	# blank on purpose even though pkglint moans
EGG_NAME=	${DISTNAME}
CATEGORIES=	www

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/FullBlogNotificationPlugin
COMMENT=	E-mail Notification for the FullBlog plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	trac-plugins-FullBlog>=0.1pre6158:../../wip/trac-plugins-FullBlog

SVN_REPOSITORIES=	fbnp
SVN_ROOT.fbnp=		http://trac-hacks.org/svn/fullblognotificationplugin/0.11
SVN_TAG.fbnp=		5330

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/fbnp

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
