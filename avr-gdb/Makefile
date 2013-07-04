# $NetBSD: Makefile,v 1.1 2013/07/04 04:31:43 makoto Exp $

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

INSTALLATION_DIRS=	bin
TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${DESTDIR}${PREFIX}/bin/avr-gdb

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
