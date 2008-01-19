# $NetBSD: Makefile,v 1.1.1.1 2008/01/19 14:04:28 obache Exp $

DISTNAME=	TracAccountManager-0.1.3dev_r2548
PKGNAME=	trac-plugins-AccountManager-0.1.3.2548
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/AccountManagerPlugin
COMMENT=	User account management plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.10:../../www/trac
DEPENDS+=	trac-plugins-WebAdmin-[0-9]*:../../wip/trac-plugins-WebAdmin

SVN_REPOSITORIES=	acct_mgr
SVN_ROOT.acct_mgr=	http://trac-hacks.org/svn/accountmanagerplugin/0.10
SVN_MODULE.acct_mgr=	#
SVN_TAG.acct_mgr=	2548

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/0.10

PRIVILEGED_STAGES+=	clean

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
