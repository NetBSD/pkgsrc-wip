# $NetBSD: Makefile,v 1.4 2010/07/04 19:26:06 rsmarples Exp $

DISTNAME=	gitplugin_0.12-r${SVN_REV}
PKGNAME=	trac-plugins-GitPlugin-0.1pre${SVN_REV}
EGGNAME=	TracGitPlugin-0.12.0.2dev
CATEGORIES=	www
MASTER_SITES=	-http://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/wiki/GitPlugin
COMMENT=	GIT plugin for Trac
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.12:../../www/trac
DEPENDS+=	scmgit-base>=1.5.6:../../devel/scmgit-base

SVN_REV=	7757
SVN_MOD=	gitplugin/0.12
WRKSRC=		${WRKDIR}/${SVN_MOD}

post-extract:
	find ${WRKSRC} -type f | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
