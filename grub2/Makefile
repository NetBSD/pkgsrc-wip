# $NetBSD: Makefile,v 1.10 2009/12/16 14:37:31 gregoire Exp $
#

DISTNAME=		grub-1.97.1
PKGNAME=		grub2-1.97.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=		gregoire.sutre@labri.fr
HOMEPAGE=		http://www.gnu.org/software/grub/grub-2.en.html
COMMENT=		GRand Unified Bootloader, version 2
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

#
# XXX: Linux-*-powerpc and others?
#
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

PKG_SYSCONFSUBDIR=	${PKGBASE}

USE_TOOLS+=		gmake bison makeinfo
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--program-transform-name=s,grub,grub2,
INFO_FILES=		yes

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
EGFILES=		00_header 30_os-prober 40_custom README
.for file in ${EGFILES}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

# The patched Makefile installs configuration scripts in ${EGDIR}.
MAKE_ENV+=		EGDIR=${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
CONF_FILES+=		${EGDIR}/00_${OPSYS:tl} ${PKG_SYSCONFDIR}/00_${OPSYS:tl}
.endif

#
# NetBSD has opendisk support since 1.3.  The following lines are required
# for proper detection of devices (e.g. in grub2-mkdevicemap).
# XXX: remove the following lines when opendisk auto-detection is added to
#      GRUB 2's configure script (it is in GRUB Legacy's configure.ac).
#
.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M1.[0-2]*)
CFLAGS+=		-DHAVE_OPENDISK
LDFLAGS+=		-lutil
.endif

# This package uses help2man to generate man pages.
BUILD_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
