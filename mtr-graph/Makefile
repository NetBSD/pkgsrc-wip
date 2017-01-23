# $NetBSD$

CATEGORIES=	net
PKGBASE=	mtr
PKGVERSION=	0.85.99
PKGREVISION=	11
PKGNAME=	${PKGBASE}-graph-${PKGVERSION}
DISTNAME=	${PKGBASE}-${GITHUB_HASH}
MASTER_SITES=	https://github.com/${GITHUB_USER}/${PKGBASE}/tarball/${GITHUB_HASH}/
WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PKGBASE}-${GITHUB_HASH}

GITHUB_HASH=	e78fa1f
GITHUB_USER=	yvs2014

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool
LICENSE=	gnu-gpl-v2

CONFLICTS=	mtr-[0-9]*
CONFLICTS+=	mtr-current-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		autoconf autoreconf automake
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/mtr

.include "options.mk"

SPECIAL_PERMS=	sbin/mtr ${SETUID_ROOT_PERMS}

pre-configure:
	autoreconf -fi ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtr ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/mtr

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
