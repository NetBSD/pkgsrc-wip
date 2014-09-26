# $NetBSD: Makefile,v 1.2 2014/09/26 09:51:23 yvs4sf Exp $

CATEGORIES=	net
PKGBASE=	mtr
PKGVERSION=	0.85.99
PKGREVISION=	1
PKGNAME=	${PKGBASE}-graph-${PKGVERSION}
DISTNAME=	${PKGBASE}-${GITVERSION}
MASTER_SITES=	https://github.com/${GITHUB_USER}/${PKGBASE}/tarball/${GITVERSION}/
WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PKGBASE}-${GITVERSION}

GITVERSION=	87d5961
GITHUB_USER=	yvs2014

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool
LICENSE=	gnu-gpl-v2

CONFLICTS=	mtr-[0-9]*
CONFLICTS+=	mtr-current-[0-9]*

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
