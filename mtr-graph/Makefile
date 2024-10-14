# $NetBSD$

CATEGORIES=	net
PKGBASE=	mtr085
PKGVERSION=	172
PKGREVISION=	1
PKGNAME=	${PKGBASE}-${PKGVERSION}
DISTNAME=	${PKGBASE}-${GITHUB_HASH}
MASTER_SITES=	${MASTER_SITE_GITHUB:=${GITHUB_USER}/}/${PKGBASE}/tarball/${GITHUB_HASH}/
WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PKGBASE}-${GITHUB_HASH}

GITHUB_HASH=	49d2669
GITHUB_USER=	yvs2014

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bitwizard.nl/mtr/
COMMENT=	MTR v0.85 fork with whois info, IDN, unicode
LICENSE=	gnu-gpl-v2
USE_LANGUAGES=	c

CONFLICTS=	mtr-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		meson pkg-config
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/mtr

MESON_ARGS+=	-DCAP=false
MESON_ARGS+=	-DSBIN=true

.include "options.mk"

SPECIAL_PERMS=	sbin/mtr ${SETUID_ROOT_PERMS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/mtr

.include "../../devel/meson/build.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
