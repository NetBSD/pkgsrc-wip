# $NetBSD: Makefile,v 1.11 2010/02/19 16:45:57 cheusov Exp $

DISTNAME=	mc-4.7.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.midnight-commander.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://www.midnight-commander.org/
COMMENT=	User-friendly file manager and visual shell

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config unzip:run zip:run
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PLIST_SRC+=		${PKGDIR}/PLIST.cons.saver
.endif

# we need working e2fsprogs and gpm packages first
CONFIGURE_ARGS+=	--without-ext2undel
CONFIGURE_ARGS+=	--without-gpm-mouse
CONFIGURE_ARGS+=	UNZIP=${TOOLS_PATH.unzip} ZIP=${TOOLS_PATH.zip}

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

PKG_SYSCONFSUBDIR=	mc
SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	lib/vfs/mc-vfs/extfs.c lib/vfs/mc-vfs/sfs.c
SUBST_VARS.conf=	PKG_SYSCONFDIR

EGDIR=			${PREFIX}/share/examples/mc

conffiles=	cedit.menu edit.indent.rc edit.spell.rc filehighlight.ini \
		mc.ext mc.keymap mc.keymap.default mc.keymap.emacs mc.lib \
		mc.menu mc.menu.sr syntax/Syntax

.if !empty(PKG_OPTIONS:Mvfs)
conffiles+=	extfs.ini sfs.ini
.endif

.if !empty(PKG_OPTIONS:Mcharset)
conffiles+=	mc.charsets
.endif

.for i in ${conffiles}
CONF_FILES+=     ${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor

INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/syntax

post-install:
# remove dir if no extensions were installed there
	rmdir ${DESTDIR}${PREFIX}/lib/mc 2>/dev/null || ${TRUE}
.if !empty(PKG_OPTIONS:Mvfs)
	${INSTALL_DATA} ${WRKSRC}/lib/vfs/mc-vfs/extfs/extfs.ini ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/vfs/mc-vfs/extfs/sfs.ini ${DESTDIR}${EGDIR}
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
