# $NetBSD: Makefile,v 1.2 2011/05/15 11:07:35 thomasklausner Exp $

DISTNAME=		debugger-git
CATEGORIES=		devel
MASTER_SITES=		https://github.com/path64/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/path64/
COMMENT=		X86/x86_64 debugger with the goal to drop-in replace gdb
LICENSE=		2-clause-bsd

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PKG_DESTDIR_SUPPORT=	user-destdir

GIT_REPOSITORIES=	debugger
GIT_REPO.debugger=	git://github.com/path64/debugger.git
WRKSRC=			${WRKDIR}/debugger
USE_CMAKE=		yes

USE_LANGUAGES=		c c++

REPLACE_PYTHON=		src/mkdoctext.py src/mkdwfspec.py src/mkopcodes.py

.include "../../lang/python/application.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
