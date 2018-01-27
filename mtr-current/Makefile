# $NetBSD$

CATEGORIES=	net
PKGBASE=	mtr
PKGVERSION=	0.87.225
PKGNAME=	${PKGBASE}-${PKGVERSION}
DISTNAME=	${PKGBASE}-${GITHUB_HASH}
MASTER_SITES=	https://github.com/${GITHUB_USER}/${PKGBASE}/tarball/${GITHUB_HASH}/
WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PKGBASE}-${GITHUB_HASH}

GITHUB_HASH=	e6d0a7e
GITHUB_USER=	traviscross

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool
LICENSE=	gnu-gpl-v2

CONFLICTS=	mtr-[0-9]*
CONFLICTS+=	mtr-graph-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		autoconf autoreconf automake
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/mtr

.include "options.mk"

SPECIAL_PERMS=	sbin/mtr-packet ${SETUID_ROOT_PERMS}

# Remove hard-coded compiler option that GCC 3.x doesn't support.
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3.*)
BUILDLINK_TRANSFORM+=	rm:-Wno-pointer-sign
.endif

.if !empty(MACHINE_PLATFORM:MDarwin-??.*-*)
LIBS+=	-lresolv
.endif

SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	post-patch
SUBST_MESSAGE.fix-version=	Fixing version
SUBST_FILES.fix-version=	configure.ac
SUBST_SED.fix-version=		-e '/build-aux\/git-version-gen/s/\[.*\]/[${PKGVERSION}]/'

pre-configure:
	autoreconf -fi ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtr ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/mtr-packet ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/mtr-packet.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/mtr

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
