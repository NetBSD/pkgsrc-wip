# $NetBSD: Makefile,v 1.2 2003/11/28 21:59:45 jeremy-c-reed Exp $
#

DISTNAME=		xpde-0.4.0-20030730
PKGNAME=		xpde-0.4.0
WRKSRC=			${WRKDIR}/xpde-0.4.0
CATEGORIES=		misc wm x11
MASTER_SITES=		http://www.xpde.com/releases/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.xpde.com/
COMMENT=		"Desktop environment for X11 (Windows XP interface clone)"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse_compat-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_x11-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

NO_BUILD=		# defined

do-install:
	cd ${WRKSRC} && ./install.sh ${PREFIX}/emul/linux/opt/xpde ../../usr/lib/

.include "../../mk/bsd.pkg.mk"
