# $NetBSD: Makefile,v 1.6 2007/01/24 20:02:03 lkundrak Exp $

DISTNAME=		grub2
PKGNAME=		grub2-${GRUB_VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		# not defined

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://www.gnu.org/software/grub/grub.html
COMMENT=		Universal multiboot compilant GNU boot manager and loader

CVS_REPOSITORIES=	grub2
CVS_ROOT.grub2=		:pserver:anonymous:@cvs.savannah.gnu.org:/sources/grub
CVS_MODULE.grub2=	grub2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison

CONFLICTS=		grub-[0-9]*
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64
# XXX: Linux-*-powerpc and others

.if ${MACHINE_ARCH} == "x86_64"
GRUB_MACHINE_ARCH=	"i386"
.else
GRUB_MACHINE_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUBST+=		GRUB_MACHINE_ARCH=${GRUB_MACHINE_ARCH}
PLIST_SRC=		${PKGDIR}/PLIST

PKG_OPTIONS_VAR=	PKG_OPTIONS.grub2
PKG_SUPPORTED_OPTIONS=	grub-mm-debug grub-emu
# Both will be off once the stable release is out
#PKG_SUGGESTED_OPTIONS=
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

###
### Include memory manager debugging
###

.if !empty(PKG_OPTIONS:Mgrub-mm-debug)
CONFIGURE_ARGS+=	--enable-mm-debug
.endif

###
### Build and install the `grub-emu' debugging utility
###

.if !empty(PKG_OPTIONS:Mgrub-emu)
CONFIGURE_ARGS+=	--enable-grub-emu
PLIST_SRC+=		${PKGDIR}/PLIST.grub-emu
.include "../../mk/curses.buildlink3.mk"
#.include "../../devel/ncurses/buildlink3.mk"
.endif

.include "../../wip/grub2/version.mk"

.include "../../wip/libargp/buildlink3.mk"
.include "../../archivers/liblzo/buildlink3.mk"
.include "../../devel/binutils/buildlink3.mk"

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
