# $NetBSD$

DISTNAME=	gdb-12.1
PKGNAME=	${DISTNAME:S/^/avr-/}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAKE_JOBS_SAFE=	yes

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceware.org/gdb/
COMMENT=	GNU gdb for Atmel AVR 8-bit RISC microcontrollers
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LANGUAGES=		c c++11
USE_TOOLS+=		bash gmake
CONFIG_SHELL=		${TOOLS_PATH.bash}
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CONFIG_LDFLAGS=${LDFLAGS:M*:Q}
CONFIGURE_ARGS+=	--target=avr
CONFIGURE_ARGS+=	--program-prefix=avr
CONFIGURE_ARGS+=	--with-curses
# elfread.c is to be included in init.c to support bfd_target_elf_flavour
CONFIGURE_ENV+=		gdb_cv_var_elf=yes
MAKE_ENV+=		gdb_cv_var_elf=yes
# Native gdb has following lines also activated
#CONFIGURE_ENV+=	gdb_cv_struct_lwp=yes
#MAKE_ENV+=		gdb_cv_struct_lwp=yes

INSTALLATION_DIRS=	bin

# DejaGnu is required for the test suite
TEST_TARGET=		check
TEST_DEPENDS+=		dejagnu>=1.6.2:../../devel/dejagnu

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${DESTDIR}${PREFIX}/bin/avr-gdb

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../textproc/source-highlight/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
