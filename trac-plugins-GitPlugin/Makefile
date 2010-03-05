# $NetBSD: Makefile,v 1.3 2010/03/05 13:21:18 lexort Exp $

DISTNAME=	TracGitPlugin-0.1dev
PKGNAME=	trac-plugins-GitPlugin-0.1pre${SVNVERSION}
SVNVERSION=	6442
# PKGREVISION should be empty rather than unset because svn-package.mk
# does the wrong thing if it is unset, even though pkglint will complain
PKGREVISION=	
EGG_NAME=	${DISTNAME}
CATEGORIES=	www

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/wiki/GitPlugin
COMMENT=	GIT plugin for Trac
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac
DEPENDS+=	scmgit-base>=1.5.6:../../devel/scmgit-base

SVN_REPOSITORIES=	gitplugin
SVN_ROOT.gitplugin=	http://trac-hacks.org/svn/gitplugin/0.11
SVN_TAG.gitplugin=	${SVNVERSION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/gitplugin

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
