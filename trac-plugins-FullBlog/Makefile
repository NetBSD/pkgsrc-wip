# $NetBSD: Makefile,v 1.1.1.1 2009/07/17 09:16:08 rsmarples Exp $

DISTNAME=	TracFullBlogPlugin-0.1dev
PKGNAME=	trac-plugins-FullBlog-0.1pre6158
PKGREVISION=	# blank on purpose even though pkglint moans
EGG_NAME=	${DISTNAME}
CATEGORIES=	www

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/FullBlogPlugin
COMMENT=	Blog plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	fullblog
SVN_ROOT.fullblog=	http://trac-hacks.org/svn/fullblogplugin/0.11
SVN_TAG.fullblog=	6158

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/fullblog

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
