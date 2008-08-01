# $NetBSD: Makefile,v 1.2 2008/08/01 02:09:15 obache Exp $

DISTNAME=	TracWebAdmin-0.1.2dev_r5911
PKGNAME=	trac-plugins-WebAdmin-0.1.2.5911
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://projects.edgewall.com/trac/wiki/WebAdmin
COMMENT=	Web admin plugin for trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.10:../../www/trac

CONFLICTS+=	{ja-,}trac>=0.11

SVN_REPOSITORIES=	webadmin
SVN_ROOT.webadmin=	http://svn.edgewall.com/repos/trac/sandbox/webadmin
SVN_MODULE.webadmin=	#
SVN_TAG.webadmin=	5911

PYDISTUTILSPKG=		yes

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/webadmin

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

PRIVILEGED_STAGES+=	clean

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
