# $NetBSD: Makefile,v 1.13 2010/01/17 10:55:53 gregoire Exp $
#

DISTNAME=		grub-bazaar-snapshot
PKGNAME=		grub2-${TODAY}
CATEGORIES=		sysutils

MAINTAINER=		gregoire.sutre@gmail.com
HOMEPAGE=		http://www.gnu.org/software/grub/grub-2.en.html
COMMENT=		GRand Unified Bootloader, version 2 (development snapshot)
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

# Helper file for access to the bazaar repository and for autogen.sh.
.include "bzr.mk"

#
# XXX: Linux-*-powerpc and others?
#
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

PKG_SYSCONFSUBDIR=	${PKGBASE}

USE_TOOLS+=		autoconf automake gettext-m4
USE_TOOLS+=		gmake bison makeinfo
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--program-transform-name=s,grub,grub2,
CONFIGURE_ARGS+=	--enable-grub-fstest
CONFIGURE_ARGS+=	--disable-efiemu
CONFIGURE_ARGS+=	--disable-grub-emu-usb
CONFIGURE_ARGS+=	--disable-grub-emu-pci
INFO_FILES=		yes

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

# The modified Makefile installs all configuration scripts in ${EGDIR}.
MAKE_ENV+=		EGDIR=${EGDIR}

.include "../../mk/bsd.prefs.mk"

EGFILES=		00_header 05_pkgsrc_theme 30_os-prober 40_custom
.if ${OPSYS} == "FreeBSD"
EGFILES+=		10_kfreebsd
.elif ${OPSYS} == "Linux"
EGFILES+=		10_linux
.elif ${OPSYS} == "NetBSD"
EGFILES+=		10_netbsd
.endif
.for file in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file} ${ROOT_USER} ${ROOT_GROUP} 0755
.endfor
CONF_FILES+=		${EGDIR}/README ${PKG_SYSCONFDIR}/README
CONF_FILES+=		${EGDIR}/default.conf.sample ${PKG_SYSCONFDIR}/default.conf

TODAY!=			${DATE} -u +'%Y%m%d'

# GRUB 2 current development trunk seems to prefer a recent version of gcc.
GCC_REQD=		4.1.3

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
# The following substitutions adjust the configuration and library paths:
# - $sysconfdir/grub.d is replaced by $sysconfdir in scripts, and by $EGDIR
#   in Makefile.in.
# - $sysconfdir/default/grub is replaced by $sysconfdir/default.conf in
#   scripts.
# - $libdir/grub is replaced by $libdir/grub2 in Makefile.in and in scripts.
# - DEFAULT_DIRECTORY in include/grub/util/misc.h.
#
SUBST_CLASSES+=			fix-paths-1 fix-paths-2 fix-paths-3
SUBST_STAGE.fix-paths-1=	pre-configure
SUBST_MESSAGE.fix-paths-1=	Fixing configuration and library paths in makefile.
SUBST_FILES.fix-paths-1=	Makefile.in
SUBST_SED.fix-paths-1=		-e 's,\$$(sysconfdir)/grub.d,\$$(EGDIR),g'
SUBST_SED.fix-paths-1+=		-e 's,\$$(libdir)/grub,\$$(libdir)/grub2,g'
SUBST_STAGE.fix-paths-2=	pre-configure
SUBST_MESSAGE.fix-paths-2=	Fixing configuration and library paths in scripts.
SUBST_FILES.fix-paths-2=	util/grub-mkconfig.in util/update-grub_lib.in
SUBST_FILES.fix-paths-2+=	util/grub.d/[0-3]*.in
SUBST_FILES.fix-paths-2+=	util/grub-install.in
SUBST_SED.fix-paths-2=		-e 's,\$${sysconfdir}/grub.d,\$${sysconfdir},g'
SUBST_SED.fix-paths-2+=		-e 's,\$${sysconfdir}/default/grub,\$${sysconfdir}/default.conf,g'
SUBST_SED.fix-paths-2+=		-e 's,\$${libdir}/grub,\$${libdir}/grub2,g'
SUBST_STAGE.fix-paths-3=	pre-configure
SUBST_MESSAGE.fix-paths-3=	Fixing default directory in include/grub/util/misc.h.
SUBST_FILES.fix-paths-3=	include/grub/util/misc.h
SUBST_SED.fix-paths-3=		-e 's,"/grub","/grub2",g'
SUBST_SED.fix-paths-3+=		-e 's,"/boot/grub","/boot/grub2",g'

# This package uses help2man to generate man pages.
BUILD_DEPENDS+=		help2man>=1.36:../../converters/help2man

post-install:
	${INSTALL_DATA} ${FILESDIR}/default.conf ${EGDIR}/default.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/05_pkgsrc_theme ${EGDIR}/05_pkgsrc_theme

.include "options.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
