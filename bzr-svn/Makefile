# $NetBSD: Makefile,v 1.5 2011/11/22 21:13:44 ddeus Exp $

DISTNAME=	bzr-svn-${VER}
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzr-svn/1.1/${VER}/+download/
MASTER_SITES+=	http://samba.org/~jelmer/bzr/
VER=		1.1.1

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://bazaar-vcs.org/BzrForeignBranches/Subversion
COMMENT=	Foreign Subversion repository support for Bazaar
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED=	27 26 25
PYTHON_PATCH_SCRIPTS= info.py wiki.py

DEPENDS+=	bzr>=2.4:../../wip/bzr
DEPENDS+=	${PYPKGPREFIX}-subvertpy>=0.8.8:../../devel/py-subvertpy

.include "../../lang/python/pyversion.mk"

DEPENDS=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

# for make test
USE_TOOLS+=	gmake
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

# NOTE: This must run in a UTF-8 locale, e.g. LC_TYPE=en_US.utf8 make test
#TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
#TEST_DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
#TEST_TARGET=	check-verbose

.include "../../wip/bzr/plugin.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
