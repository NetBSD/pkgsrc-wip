# $NetBSD: Makefile,v 1.2 2004/05/10 01:27:36 blef Exp $
#

DISTNAME=		buildbot-0.3.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/buildbot/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://buildbot.sourceforge.net/
COMMENT=		System to automate the compile/test cycle

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
