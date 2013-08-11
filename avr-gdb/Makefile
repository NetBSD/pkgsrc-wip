# $NetBSD: Makefile,v 1.2 2013/08/11 04:14:34 makoto Exp $

DISTNAME=	gdb-7.6
PKGNAME=	avr-gdb-7.6
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GNU gdb for Atmel AVR 8-bit RISC microcontrollers
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CONFIG_LDFLAGS=${LDFLAGS:M*:Q}
CONFIGURE_ARGS+=	--target=avr
CONFIGURE_ARGS+=	--program-prefix=avr
CONFIGURE_ARGS+=	-with-curses
# elfread.c is to be included in init.c to support bfd_target_elf_flavour
CONFIGURE_ENV+=		gdb_cv_var_elf=yes
MAKE_ENV+=		gdb_cv_var_elf=yes
# Native gdb has following lines also activated
#CONFIGURE_ENV+=		gdb_cv_struct_lwp=yes
#MAKE_ENV+=		gdb_cv_struct_lwp=yes


INSTALLATION_DIRS=	bin
TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${DESTDIR}${PREFIX}/bin/avr-gdb

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
