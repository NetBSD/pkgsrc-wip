# $NetBSD: Makefile,v 1.2 2008/03/06 18:36:10 tnn2 Exp $
#

DISTNAME=		es40_018_src
PKGNAME=		es40-0.18
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=es40/}
EXTRACT_SUFX=		.zip
EXTRACT_OPTS_ZIP=	-aqo
EXTRACT_ONLY=		es40_018_src.zip
VGABIOS=		vgabios-0.6a.debug.bin
DISTFILES=		${DEFAULT_DISTFILES} ${VGABIOS}
SITES.${VGABIOS}=	http://savannah.gnu.org/download/vgabios/

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

INSTALLATION_DIRS=	bin share/es40 share/examples/es40

post-extract:
	cp ${DISTDIR}/${VGABIOS} ${WRKDIR}
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/es40 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${VGABIOS} \
	 ${DESTDIR}${PREFIX}/share/es40
	${INSTALL_DATA} ${WRKSRC}/es40.cfg \
	  ${DESTDIR}${PREFIX}/share/examples/es40
	${INSTALL_DATA} ${FILESDIR}/es40-netbsd.cfg \
	  ${DESTDIR}${PREFIX}/share/examples/es40

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
