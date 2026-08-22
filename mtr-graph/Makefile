# $NetBSD$

CATEGORIES=	net
PKGBASE=	mtr085
PKGVERSION=	307
PKGREVISION=	1
DISTNAME=	${PKGBASE}-${PKGVERSION}

MASTER_SITES=	${MASTER_SITE_GITHUB:=yvs2014/}
GITHUB_TAG=	e99d753823df2dd6fba3ca4d1c4636b78ee3e559

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Experimenting with MTR tool: mtr085 with whois info, IDN, NLS
LICENSE=	gnu-gpl-v2
USE_LANGUAGES=	c

CONFLICTS=	mtr-[0-9]*

USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/mtr

MESON_ARGS+=	-DCAP=false
MESON_ARGS+=	-DSBIN=true

.include "options.mk"

#SPECIAL_PERMS= sbin/mtr ${SETUID_ROOT_PERMS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/mtr

.include "../../devel/meson/build.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
