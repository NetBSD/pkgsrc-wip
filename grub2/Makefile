# $NetBSD: Makefile,v 1.25 2021/05/24 19:54:11 wiz Exp $

DISTNAME=		grub-2.12
PKGNAME=		${DISTNAME:S/grub/grub2/}
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gnu.org/gnu/grub/
EXTRACT_SUFX=		.tar.xz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/grub/
COMMENT=		GRand Unified Bootloader, version 2
LICENSE=		gnu-gpl-v3

TOOL_DEPENDS+=		help2man>=1.36:../../converters/help2man

GCC_REQD+=		4.4
FLEX_REQD+=		2.5.35

CONFLICTS=		grub-[0-9]*

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

FORTIFY_SUPPORTED=	no
MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no
SSP_SUPPORTED=		no

# kernel.img in grub-core sometimes doesn't exist for the 'install' rule
MAKE_JOBS_SAFE=		no

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake flex bison gettext:run gawk pkg-config

.include "../../lang/python/tool.mk"
PYTHON_FOR_BUILD_ONLY=	tool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-efiemu
CONFIGURE_ARGS+=	--disable-grub-emu-sdl
CONFIGURE_ARGS+=	--disable-grub-emu-pci
CONFIGURE_ARGS+=	--disable-werror

INFO_FILES=		yes
USE_PKGLOCALEDIR=	yes

MAKE_FLAGS+=	BUILD_LDFLAGS=${COMPILER_RPATH_FLAG}${X11BASE}/lib

.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-Wno-unused-value

post-configure:
	touch work/${DISTNAME}/grub-core/extra_deps.lst

#post-build:
#cd ${WRKSRC}/grub-core && ${GMAKE} kernel.img

#
# The configure script sets the variables `target_cpu' and `platform', which
# are used for the location of the library directory.  The following mimics
# the configure script's behavior for i386 and x86_64.
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
# Unset ABI to prevent pkgsrc's gcc wrapper from messing with -m flags.
#
.if defined(ABI) && !empty(ABI)
.  undef ABI
.endif

#
# Configuration files.
#
PKG_SYSCONFSUBDIR=	grub
EGDIR=			${PREFIX}/share/examples/grub
INSTALL_MAKE_FLAGS+=	grubconfdir=${EGDIR}
INSTALL_MAKE_FLAGS+=	bashcompletiondir=${EGDIR}
INSTALL_MAKE_FLAGS+=	bash_completion_script=grub-bash-completion.sh

EGFILES=		00_header 05_pkgsrc_theme 30_os-prober 40_custom 41_custom
.if ${OPSYS} == "FreeBSD"
EGFILES+=		10_kfreebsd
.elif ${OPSYS} == "Linux"
EGFILES+=		10_linux
.elif ${OPSYS} == "NetBSD"
EGFILES+=		10_netbsd
.endif
.for file in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
.endfor
CONF_FILES+=		${EGDIR}/README ${PKG_SYSCONFDIR}/README
CONF_FILES+=		${EGDIR}/default.conf.sample ${PKG_SYSCONFDIR}/default.conf

post-install: do-install-custom-config

.PHONY: do-install-custom-config
do-install-custom-config:
	${INSTALL_DATA} ${FILESDIR}/default.conf ${DESTDIR}${EGDIR}/default.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/05_pkgsrc_theme ${DESTDIR}${EGDIR}/05_pkgsrc_theme

#
# Force installation of all OS configuration scripts in ${EGDIR}.
#
SUBST_CLASSES+=			fix-os-conf
SUBST_STAGE.fix-os-conf=	pre-configure
SUBST_MESSAGE.fix-os-conf=	Fixing installation of OS configuration scripts.
SUBST_FILES.fix-os-conf=	Makefile.in
SUBST_SED.fix-os-conf=		-e 's,^@COND_HOST_[A-Z]*_TRUE@,,g'

#
# Adjust the configuration paths in scripts.
#
SUBST_CLASSES+=			fix-paths-1
SUBST_STAGE.fix-paths-1=	pre-configure
SUBST_MESSAGE.fix-paths-1=	Fixing configuration paths in scripts.
SUBST_FILES.fix-paths-1=	util/grub-mkconfig.in
SUBST_SED.fix-paths-1=		-e 's,\(\$${sysconfdir}"\{0\,1\}\)/grub.d,\1,g'
SUBST_SED.fix-paths-1+=		-e 's,\(\$${sysconfdir}"\{0\,1\}\)/default/grub,\1/default.conf,g'

#
# Adjust the search paths for fonts in configure.
#
SUBST_CLASSES+=			fix-fonts
SUBST_STAGE.fix-fonts=		pre-configure
SUBST_MESSAGE.fix-fonts=	Fixing fonts search paths in configure.
SUBST_FILES.fix-fonts=		configure
SUBST_SED.fix-fonts=		-e 's,/usr/share/fonts,${PREFIX}/share/fonts,'

#
# Do not use `\t' with sed, as it's not portable.
#
SUBST_CLASSES+=			fix-sed-tabs
SUBST_STAGE.fix-sed-tabs=	pre-configure
SUBST_MESSAGE.fix-sed-tabs=	Fixing tabulations for sed in scripts.
SUBST_FILES.fix-sed-tabs=	util/grub.d/*.in
SUBST_SED.fix-sed-tabs=		-e 's,\\t,	,g'

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
