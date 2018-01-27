# $NetBSD: Makefile,v 1.4 2015/03/14 02:09:54 krytarowski Exp $
#

DISTNAME=		mg
CATEGORIES=		editors
CVS_REPOSITORIES=	mg
CVS_ROOT.mg=		anoncvs@anoncvs.openbsd.org:/cvs/src/usr.bin

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cvsweb.openbsd.org/cgi-bin/cvsweb/src/usr.bin/mg/
COMMENT=	Small, fast, public domain EMACS style editor

USE_NCURSES=	yes # Uses NCURSES internals

CONFLICTS+=	mg2a-[0-9]*

USE_BSD_MAKEFILE=	yes
USE_FEATURES=		nbcompat

NBCOMPAT_CONFIGURE_ARGS+=	--enable-openbsd-source

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
