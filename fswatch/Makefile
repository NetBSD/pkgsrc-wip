# $NetBSD: Makefile,v 1.2 2015/05/10 07:41:59 thomasklausner Exp $

DISTNAME=	fswatch-1.11.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=emcrisostomo/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/emcrisostomo/fswatch
COMMENT=	Cross-platform file change monitor with multiple backends
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake autoconf automake makeinfo
INFO_FILES=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	4.8

PLIST_VARS+=	fen fsevents inotify kqueue

.if ${OPSYS} == "Darwin"
PLIST.fsevents=		yes
.elif ${OPSYS} == "Linux"
PLIST.inotify=		yes
.elif ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	ac_cv_header_sys_inotify_h=no
PLIST.fen=		yes
.endif
.if defined(PKG_HAVE_KQUEUE)
PLIST.kqueue=		yes
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
