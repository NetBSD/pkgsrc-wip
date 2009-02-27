# $NetBSD: Makefile,v 1.3 2009/02/27 12:11:28 rsmarples Exp $

DISTNAME=	TracFullBlog-0.1dev
PKGNAME=	trac-plugins-fullblog-0.1pre5210
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
SVN_TAG.fullblog=	5210

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/fullblog

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
