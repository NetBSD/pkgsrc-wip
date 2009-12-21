# $NetBSD: Makefile,v 1.15 2009/12/21 10:28:29 gregoire Exp $
#

DISTNAME=		grub-1.97.1
PKGNAME=		grub2-1.97.1
PKGREVISION=		2
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
CONFIGURE_ARGS+=	--enable-grub-fstest
CONFIGURE_ARGS+=	--disable-efiemu
CONFIGURE_ARGS+=	--disable-grub-emu-usb
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
CONF_FILES+=		${EGDIR}/10_${OPSYS:tl} ${PKG_SYSCONFDIR}/10_${OPSYS:tl}
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

#
# GRUB 2's configure script sets the variables `target_cpu' and `platform',
# which are used to define the location of library directory.  We must take
# this into account for PLIST.  The following mimics the behavior of the
# configure script.  Our job is simpler as we only accept i386 and x86_64
# (see definition of ONLY_FOR_PLATFORM above).
#
GRUB_TARGET_CPU=	${MACHINE_ARCH}
.if ${LOWER_VENDOR} == "apple"
GRUB_PLATFORM=		efi
.else
GRUB_PLATFORM=		pc
.endif
.if ${GRUB_TARGET_CPU} == "x86_64" && ${GRUB_PLATFORM} == "pc"
GRUB_TARGET_CPU=	i386
.endif
PLIST_SUBST+=		GRUB_TARGET_CPU=${GRUB_TARGET_CPU}
PLIST_SUBST+=		GRUB_PLATFORM=${GRUB_PLATFORM}

#
# The following substitutions fix the configuration and library paths:
# - $sysconfdir/grub.d is replaced by $sysconfdir in scripts, and by $EGDIR
#   in Makefile.in.
# - $sysconfdir/default/grub is replaced by $sysconfdir/default.conf in
#   scripts
# - $libdir/grub is replaced by $libdir/grub2 in Makefile.in and in scripts.
#
SUBST_CLASSES+=			fix-paths-1 fix-paths-2
SUBST_STAGE.fix-paths-1=	pre-configure
SUBST_MESSAGE.fix-paths-1=	Fixing configuration and library paths in makefile.
SUBST_FILES.fix-paths-1=	Makefile.in
SUBST_SED.fix-paths-1=		-e 's,\$$(sysconfdir)/grub.d,\$$(EGDIR),g'
SUBST_SED.fix-paths-1+=		-e 's,\$$(libdir)/grub,\$$(libdir)/grub2,g'
SUBST_STAGE.fix-paths-2=	pre-configure
SUBST_MESSAGE.fix-paths-2=	Fixing configuration and library paths in scripts.
SUBST_FILES.fix-paths-2=	util/grub-mkconfig.in util/update-grub_lib.in
SUBST_FILES.fix-paths-2+=	util/grub.d/[0-3]*
SUBST_FILES.fix-paths-2+=	util/i386/pc/grub-install.in
SUBST_FILES.fix-paths-2+=	util/sparc64/ieee1275/grub-install.in
SUBST_SED.fix-paths-2=		-e 's,\$${sysconfdir}/grub.d,\$${sysconfdir},g'
SUBST_SED.fix-paths-2+=		-e 's,\$${sysconfdir}/default/grub,\$${sysconfdir}/default.conf,g'
SUBST_SED.fix-paths-2+=		-e 's,\$${libdir}/grub,\$${libdir}/grub2,g'

# This package uses help2man to generate man pages.
BUILD_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
