# $NetBSD: Makefile,v 1.4 2005/04/11 21:14:58 tvierling Exp $
#

DISTNAME=		buildbot-0.3.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/buildbot/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://buildbot.sourceforge.net/
COMMENT=		System to automate the compile/test cycle

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
