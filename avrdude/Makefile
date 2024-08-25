# $NetBSD$

DISTNAME=		avrdude-7.3
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITHUB:=avrdudes/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/avrdudes/avrdude/
COMMENT=		Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS+=		lex yacc

.include "../../mk/bsd.prefs.mk"

CMAKE_CONFIGURE_ARGS+=		-D BUILD_SHARED_LIBS=1
.if   ${OPSYS} == "DragonFly" ||	\
	${OPSYS} == "FreeBSD" ||	\
	${OPSYS} == "Linux" ||		\
	${OPSYS} == "SunOS"
CMAKE_CONFIGURE_ARGS+=		-D HAVE_PARPORT=1
CMAKE_CONFIGURE_ARGS+=		-D DEFAULT_PAR_PORT=${DEFAULT_PARALLEL_DEVICE}
.endif
CMAKE_CONFIGURE_ARGS+=		-D DEFAULT_SER_PORT=${DEFAULT_SERIAL_DEVICE}

EGDIR=			${PREFIX}/share/examples/avrdude
CONF_FILES_PERMS=	${EGDIR}/avrdude.conf ${PKG_SYSCONFDIR}/avrdude.conf \
				${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644
INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/avrdude.conf ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../comms/libhidapi/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/libftdi1/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
