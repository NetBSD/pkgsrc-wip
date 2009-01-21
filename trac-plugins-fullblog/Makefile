# $NetBSD: Makefile,v 1.1.1.1 2009/01/21 13:03:33 rsmarples Exp $

DISTNAME=	TracFullBlog-0.1dev
PKGNAME=	trac-plugins-fullblog-0.1pre5070
EGG_NAME=	${DISTNAME}
CATEGORIES=	www

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/FullBlogPlugin
COMMENT=	Blog plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	fullblog
SVN_ROOT.fullblog=	http://trac-hacks.org/svn/fullblogplugin/0.11
SVN_TAG.fullblog=	5070

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/fullblog

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
