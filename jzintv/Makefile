# $NetBSD$

DISTNAME=	jzintv-20200712-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	emulators
MASTER_SITES=	http://spatula-city.org/~im14u2c/intv/dl/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spatula-city.org/~im14u2c/intv/dl/
COMMENT=	Mattel Intellivision emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CFLAGS+=	-DUSE_STRCASECMP
# LDFLAGS ignored by build
CFLAGS+=	-L${BUILDLINK_DIR}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.readline}/lib

WRKSRC=		${WRKDIR}/${DISTNAME}/src

INSTALLATION_DIRS=	bin

do-install:
.for n in as1600 bin2luigi bin2rom cgc_update crc32 dasm0256 dasm1600 \
	dis1600 frombit frombit_r fromhex gms2rom imvtogif imvtoppm \
	intvname jzintv jzintv_batch luigi2bin lzo_embed rom2bin rom2luigi \
	rom_merge rom_metadata show_grom split_rom tobit tobit_f tobit_r tohex
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/bin/${n} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
