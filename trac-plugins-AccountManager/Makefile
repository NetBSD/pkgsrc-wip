# $NetBSD: Makefile,v 1.16 2015/02/20 11:57:21 obache Exp $

DISTNAME=	${SVN_MOD}_tags_${SVN_TAG}-${SVN_REV}
PKGNAME=	trac-plugins-AccountManager-0.4.4
EGG_NAME=	TracAccountManager-0.4.4
CATEGORIES=	www
MASTER_SITES=	-http://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}/tags/${SVN_TAG}?old_path=%2F&old=${SVN_REV}&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://trac-hacks.org/wiki/AccountManagerPlugin
COMMENT=	User account management plugin for Trac
LICENSE=	modified-bsd

DEPENDS+=	{,ja-}trac>=0.12:../../www/trac
DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-babel>=0.9.5:../../devel/py-babel

SVN_TAG=	acct_mgr-0.4.4
SVN_REV=	13806
SVN_MOD=	accountmanagerplugin
WRKSRC=		${WRKDIR}/${SVN_MOD}/tags/${SVN_TAG}

# Unwanted "/" in archive. 
EXTRACT_OPTS+=		-x
EXTRACT_ELEMENTS=	/

.include "../../mk/bsd.prefs.mk"

# and NetBSD's buitlin unzip cannot handled well it.
.if !empty(OPSYS:MNetBSD)
_TOOLS_USE_PKGSRC.unzip=	yes
.endif

post-extract:
	find ${WRKSRC} -type f -print | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
