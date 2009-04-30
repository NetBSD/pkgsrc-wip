# $NetBSD: Makefile,v 1.1.1.1 2009/04/30 21:03:21 rsmarples Exp $

DISTNAME=	TracGitPlugin-0.1dev
PKGNAME=	trac-plugins-GitPlugin-0.1pre5396
PKGREVISION=	# blank on purpose even though pkglint moans
EGG_NAME=	${DISTNAME}
CATEGORIES=	www

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/wiki/GitPlugin
COMMENT=	GIT plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac
DEPENDS+=	scmgit-base>=1.5.6:../../devel/scmgit-base

SVN_REPOSITORIES=	gitplugin
SVN_ROOT.gitplugin=	http://trac-hacks.org/svn/gitplugin/0.11
SVN_TAG.gitplugin=	5396

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/gitplugin

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
