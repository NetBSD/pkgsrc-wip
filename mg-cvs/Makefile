# $NetBSD: Makefile,v 1.3 2015/03/14 00:14:43 krytarowski Exp $
#

DISTNAME=	mg
CATEGORIES=	editors
CVS_REPOSITORIES=	mg
CVS_ROOT.mg=		anoncvs@anoncvs.openbsd.org:/cvs/src/usr.bin

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cvsweb.openbsd.org/cgi-bin/cvsweb/src/usr.bin/mg/
COMMENT=	Small, fast, public domain EMACS style editor

USE_NCURSES=	yes # Uses NCURSES internals
USE_TOOLS+=	install
MAKE_ENV+=	prefix=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CONFLICTS+=	mg2a-[0-9]*

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
