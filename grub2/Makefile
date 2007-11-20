# $NetBSD: Makefile,v 1.8 2007/11/20 05:56:10 bsadewitz Exp $

DISTNAME=		grub2
PKGREVISION=		1
PKGNAME=		grub2-${GRUB_VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		# not defined

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://www.gnu.org/software/grub/grub.html
COMMENT=		Multiboot compilant GNU boot manager and loader

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison
CONFIGURE_ARGS+=	--program-transform-name=s,grub,grub2,

MAKE_JOBS_SAFE=		no

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
EGFILES=		00_header 10_linux 10_hurd
CONF_FILES+=		${EGFILES:@.f.@:${EGDIR}/${.f.}\
				${PKG_SYSCONFDIR}/${.f.}@}
GRUB_MACHINE_ARCH=	${"${MACHINE_ARCH}" == "x86_64":?i386:${MACHINE_ARCH}}

MAKE_ENV+=		LIBARGP=-largp
MAKE_ENV+=		EGDIR=${EGDIR}
##
## XXX: Linux-*-powerpc and others
##
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64
PLIST_SUBST+=		GRUB_MACHINE_ARCH=${GRUB_MACHINE_ARCH}
PKG_SYSCONFSUBDIR=	${PKGBASE}
REPLACE_SH+=		*.sh *.in */*.in */*/*.in */*/*/*.in

.include "cvs.mk"
.include "options.mk"

.include "../../wip/libargp/buildlink3.mk"
.include "../../archivers/liblzo/buildlink3.mk"
.include "../../devel/binutils/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"

.include "../../mk/bsd.pkg.mk"
