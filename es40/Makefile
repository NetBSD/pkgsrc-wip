# $NetBSD: Makefile,v 1.1.1.1 2008/03/06 16:10:11 tnn2 Exp $
#

DISTNAME=	es40_018_src
PKGNAME=	es40-0.18
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=es40/}
EXTRACT_SUFX=	.zip
EXTRACT_OPTS_ZIP=	-aqo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://es40.sourceforge.net/
COMMENT=	AlphaServer ES40 emulator

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c++
USE_TOOLS=	gmake

CFLAGS+=	-I ${BUILDLINK_PREFIX.SDL}/include/SDL

# off_t is always 64 bits on NetBSD
CFLAGS.NetBSD+=		-Doff64_t=off_t -Dftello64=ftello -Dfseeko64=fseeko

INSTALLATION_DIRS=	bin share/examples/es40
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/es40 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/es40.cfg \
	  ${DESTDIR}${PREFIX}/share/examples/es40

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
