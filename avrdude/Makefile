# $NetBSD: Makefile,v 1.6 2015/01/18 07:50:32 makoto Exp $

DISTNAME=		avrdude-6.3
CATEGORIES=		cross
MASTER_SITES=		http://download.savannah.gnu.org/releases/avrdude/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.nongnu.org/avrdude/
COMMENT=		Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v2

# make: make: don't know how to make ./libavrdude.a. Stop
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake autoreconf
INFO_FILES=		yes
EGDIR=			${PREFIX}/share/examples/avrdude
CONF_FILES_PERMS=	${EGDIR}/avrdude.conf ${PKG_SYSCONFDIR}/avrdude.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		DEFAULT_SER_PORT=${DEFAULT_SERIAL_DEVICE:Q}
PLIST_SUBST+=		DISTNAME=${DISTNAME}

# The autotools used by this pkg are older than what's in pkgsrc
# currently.  This makes the diffs huge.
pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "options.mk"
.include "../../devel/libftdi/buildlink3.mk"
.include "../../devel/libhid/buildlink3.mk"
.include "../../wip/libftdi1/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
# elf_getshdrstrndx
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
