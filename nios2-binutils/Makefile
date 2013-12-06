# $NetBSD: Makefile,v 1.12 2013/12/06 01:06:15 makoto Exp $

DISTNAME=		binutils-2.24
PKGNAME=		${DISTNAME:S/^/nios2-/}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/binutils/
COMMENT=		GNU binutils for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v3

BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo

# No need to use makeinfo - this package doesn't install the documentation.
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_CONFIGURE_HOST=	no
INFO_FILES=		# empty

NIOS2_TARGET=		nios2-elf
CONFIGURE_ARGS+=	--disable-werror --target=${NIOS2_TARGET} --disable-nls
PLIST_SUBST+=		NIOS2_TARGET=${NIOS2_TARGET:Q}

BUILD_DEFS+=		CROSSBASE
PATH:=			${CROSSBASE}/bin:${PATH}
AUTO_MKDIRS=		yes

# Prevent the need to run texi2pod.pl and pod2man hence
# the need for perl as build dependency.
post-configure:
	set -e;							\
	cd ${WRKSRC};						\
	for f in ld/ldver.texi ld/ld.1 gas/doc/gasver.texi	\
	  gas/doc/as.1; do					\
		${TOUCH} $${f};					\
	done

# following file installed is reference only, not used at all for the moment
post-install:
	${INSTALL_DATA} files/nios2elf-netbsd.x ${DESTDIR}${PREFIX}/${NIOS2_TARGET}/lib/ldscripts

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# ./configure.lineno: 3239: Syntax error: Missing '}'
# Makefile:2991: recipe for target 'configure-opcodes' failed
# gmake[1]: *** [configure-opcodes] Error 1
# gmake[1]: Leaving directory '/export/WRKOBJDIR/wip/avr-binutils/work/binutils-2.24'
# see avr-binutils
PKGSRC_MAKE_ENV+=	SH=/bin/ksh
