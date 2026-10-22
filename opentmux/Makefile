# $NetBSD: Makefile,v 1.71 2026/10/21 19:22:45 ktnb Exp $

DISTNAME=		opentmux-0.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_CODEBERG:=opentmux/}
CODEBERG_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codeberg.org/opentmux/opentmux/
COMMENT=	Fork of tmux-3.6a before any AI was introduced
LICENSE=	modified-bsd

CONFLICTS=	tmux-[0-9]*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-sixel

USE_TOOLS+=	pkg-config
USE_FEATURES+=	strnlen

SUBST_CLASSES+=			sysconfdir
SUBST_STAGE.sysconfdir=		pre-configure
SUBST_MESSAGE.sysconfdir=	Do not force sysconfdir to /etc
SUBST_FILES.sysconfdir=		configure configure.ac
SUBST_SED.sysconfdir=		-e '/Default opentmux\.conf goes in \/etc/d'
SUBST_SED.sysconfdir+=		-e '/sysconfdir=\/etc/d'

# opentmux expects setupterm in libcurses, but it is in libterminfo
CONFIGURE_ARGS+=	ac_cv_lib_curses_setupterm=yes
LDFLAGS.NetBSD+=	-lterminfo

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.if ${MACHINE_PLATFORM:MSunOS-5.1[0-9]-*} && \
    ${CC_VERSION:Mgcc-4.[6-9].*}
BUILDLINK_TRANSFORM+=	opt:-D_XPG4_2:-D_XPG6
.endif

# https://trac.macports.org/changeset/127986
.if ${MACHINE_PLATFORM:MDarwin-1[0-9].*}
CPPFLAGS+=	-D__DARWIN_VERS_1050=0
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "QNX"
CONFIGURE_ARGS+=	--enable-utf8proc
.include "../../converters/utf8proc/buildlink3.mk"
.endif

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
