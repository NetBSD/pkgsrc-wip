# $NetBSD: Makefile,v 1.3 2013/07/03 14:12:42 yvs4sf Exp $

CATEGORIES=	net
PKGBASE=	mtr
PKGVERSION=	0.85.99
#PKGREVISION=	1
#
PKGNAME=	${PKGBASE}-${PKGVERSION}
DISTNAME=	${PKGBASE}-${GITVERSION}
#
# non-successive package versions workaround:
#
# nb1:	git:16c6a85
#	+ patch https://bugs.launchpad.net/mtr/+bug/701514
#	+ fix https://bugs.launchpad.net/mtr/+bug/1180403
#	+ fix https://bugs.launchpad.net/mtr/+bug/1189174
#	+ fix https://bugs.launchpad.net/mtr/+bug/1189221
#
MASTER_SITES=	https://github.com/${GITHUB_USER}/${PKGBASE}/tarball/${GITVERSION}/
FETCH_USING=	curl
WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PKGBASE}-${GITVERSION}

GITVERSION=	6c94317
GITHUB_USER=	traviscross

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_TOOLS+=		autoconf autoreconf automake
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/mtr

.include "options.mk"

# mtr uses libtermcap by default, but needs wattr_{on,off} from (n)curses,
# so we rewrite -ltermcap to -lncurses (which will be auto-mangled into
# -lcurses on the appropriate platforms).
BUILDLINK_TRANSFORM+=	l:termcap:ncurses

SPECIAL_PERMS=	sbin/mtr ${SETUID_ROOT_PERMS}

# Remove hard-coded compiler option that GCC 3.x doesn't support.
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3.*)
BUILDLINK_TRANSFORM+=	rm:-Wno-pointer-sign
.endif

.if !empty(MACHINE_PLATFORM:MDarwin-??.*-*)
LIBS+=	-lresolv
.endif

pre-configure:
	autoreconf -fi ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtr ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/mtr

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
