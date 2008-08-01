# $NetBSD: Makefile,v 1.2 2008/08/01 08:52:52 obache Exp $

DISTNAME=	TracAccountManager-0.2.1dev
PKGNAME=	trac-plugins-AccountManager-0.2.1pre3857
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/AccountManagerPlugin
COMMENT=	User account management plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	acct_mgr
SVN_ROOT.acct_mgr=	http://trac-hacks.org/svn/accountmanagerplugin/trunk
SVN_MODULE.acct_mgr=	#
SVN_TAG.acct_mgr=	3857

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/trunk

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
