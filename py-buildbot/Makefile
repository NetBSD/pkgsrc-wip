# $NetBSD: Makefile,v 1.1.1.1 2003/11/08 05:26:20 mpasternak Exp $
#

DISTNAME=		buildbot-0.3.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/buildbot/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://buildbot.sourceforge.net/
COMMENT=		System to automate the compile/test cycle

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Twisted-[0-9]*:../../wip/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
