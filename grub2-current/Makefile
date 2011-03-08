# $NetBSD: Makefile,v 1.23 2011/03/08 22:56:13 gregoire Exp $
#

DISTNAME=		grub-bazaar-snapshot
PKGNAME=		grub2-${BZR_REVISION}.${TODAY}
CATEGORIES=		sysutils

MAINTAINER=		gsutre@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/grub/grub-2.en.html
COMMENT=		GRand Unified Bootloader, version 2 (development snapshot)
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

#
# XXX: Linux-*-powerpc and others?
#
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

PKG_SYSCONFSUBDIR=	${PKGBASE}

USE_TOOLS+=		autoconf automake gettext-m4
USE_TOOLS+=		gmake bison makeinfo
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--program-transform-name='s,grub-,grub2-,'
CONFIGURE_ARGS+=	--disable-efiemu
CONFIGURE_ARGS+=	--disable-grub-emu-usb
CONFIGURE_ARGS+=	--disable-grub-emu-sdl
CONFIGURE_ARGS+=	--disable-grub-emu-pci
INFO_FILES=		yes

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

# The modified Makefile installs all configuration scripts in ${EGDIR}.
MAKE_ENV+=		EGDIR=${EGDIR}

.include "../../mk/bsd.prefs.mk"

EGFILES=		00_header 05_pkgsrc_theme 30_os-prober 40_custom 41_custom
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

#
# Requirements: GCC >= 4.1.3, Flex >= 2.5.35 and help2man.
#
GCC_REQD=		4.1.3
BUILD_DEPENDS+=		flex>=2.5.35:../../devel/flex
BUILD_DEPENDS+=		help2man>=1.36:../../converters/help2man

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
# The following substitution adjusts the package name (grub2).
#
SUBST_CLASSES+=			fix-name-1
SUBST_STAGE.fix-name-1=		post-patch
SUBST_MESSAGE.fix-name-1=	Fixing package name in configure.ac.
SUBST_FILES.fix-name-1=		configure.ac
SUBST_SED.fix-name-1=		-e 's,^AC_INIT(\[GRUB\],AC_INIT(\[GRUB2\],g'

#
# The following substitutions fix the command names in man pages.
#
SUBST_CLASSES+=			fix-name-2
SUBST_STAGE.fix-name-2=		post-build
SUBST_MESSAGE.fix-name-2=	Fixing command names in man pages.
SUBST_FILES.fix-name-2=		grub-*.[1-9]
SUBST_SED.fix-name-2=		-e '\,^\.TH , { s,GRUB-,GRUB2-,g ; s,grub-,grub2-,g ; }'
SUBST_SED.fix-name-2+=		-e '\,^\.SH NAME, { n ; s,^grub-,grub2-,g ; }'
SUBST_SED.fix-name-2+=		-e '\,^\.SH SYNOPSIS, { n ; s,\.B grub-,\.B grub2-,g ; }'

#
# The following substitution and post-patch rule adjust the name of the
# generated info file (grub2.info).
#
SUBST_CLASSES+=			fix-name-3
SUBST_STAGE.fix-name-3=		post-patch
SUBST_MESSAGE.fix-name-3=	Fixing package name for texinfo manual.
SUBST_FILES.fix-name-3=		docs/Makefile.am docs/grub2.texi
SUBST_SED.fix-name-3=		-e 's,grub\.info,grub2\.info,g'
SUBST_SED.fix-name-3+=		-e 's,grub\.texi,grub2\.texi,g'
SUBST_SED.fix-name-3+=		-e 's,grub_TEXINFOS,grub2_TEXINFOS,g'

post-patch: do-move-texinfo

.PHONY: do-move-texinfo
do-move-texinfo:
	${MV} ${WRKSRC}/docs/grub.texi ${WRKSRC}/docs/grub2.texi

#
# The following substitutions adjust the configuration paths:
# - $sysconfdir/grub.d is replaced by $sysconfdir in scripts, and by $EGDIR
#   in Makefile.in.
# - $sysconfdir/default/grub is replaced by $sysconfdir/default.conf in
#   scripts.
#
SUBST_CLASSES+=			fix-paths-1 fix-paths-2
SUBST_STAGE.fix-paths-1=	post-patch
SUBST_MESSAGE.fix-paths-1=	Fixing configuration paths in makefile.
SUBST_FILES.fix-paths-1=	conf/Makefile.common
SUBST_SED.fix-paths-1=		-e 's,\$$(sysconfdir)/grub.d,\$$(EGDIR),g'
SUBST_STAGE.fix-paths-2=	post-patch
SUBST_MESSAGE.fix-paths-2=	Fixing configuration paths in scripts.
SUBST_FILES.fix-paths-2=	util/grub-install.in util/grub-mkconfig.in
SUBST_SED.fix-paths-2=		-e 's,\$${sysconfdir}/grub.d,\$${sysconfdir},g'
SUBST_SED.fix-paths-2+=		-e 's,\$${sysconfdir}/default/grub,\$${sysconfdir}/default.conf,g'

#
# The following substitution adjusts the installation directory of the
# bash completion file.
#
SUBST_CLASSES+=			fix-paths-3
SUBST_STAGE.fix-paths-3=	post-patch
SUBST_MESSAGE.fix-paths-3=	Fixing bash completion installation path.
SUBST_FILES.fix-paths-3=	util/bash-completion.d/Makefile.am
SUBST_SED.fix-paths-3=		-e 's,bash_completion_script = grub,bash_completion_script = grub2,g'
SUBST_SED.fix-paths-3+=		-e 's,\$$(sysconfdir)/bash_completion.d,\$$(datadir)/bash-completion.d,g'

post-install:
	${INSTALL_DATA} ${FILESDIR}/default.conf ${DESTDIR}${EGDIR}/default.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/05_pkgsrc_theme ${DESTDIR}${EGDIR}/05_pkgsrc_theme

# Options for this package
.include "options.mk"

# Helper file to access the bazaar repository, download translations and font
# files, and generate the configure script with autogen.sh.
.include "download.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
