# $NetBSD: Makefile,v 1.5 2009/07/20 13:12:26 rsmarples Exp $

DISTNAME=	TracAccountManager-0.2.1dev
PKGNAME=	trac-plugins-AccountManager-0.2.1pre5836
PKGREVISION=	# empty
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/AccountManagerPlugin
COMMENT=	User account management plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	acct_mgr
SVN_ROOT.acct_mgr=	http://trac-hacks.org/svn/accountmanagerplugin/0.11
SVN_TAG.acct_mgr=	5836

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/acct_mgr

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
