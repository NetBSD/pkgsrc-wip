# $NetBSD: Makefile,v 1.6 2012/11/23 22:33:31 othyro Exp $

DISTNAME=		# cvs package
PKGNAME=		es40-0.18
CATEGORIES=		emulators
EXTRACT_ONLY=		#
VGABIOS=		vgabios-0.6b.bin
DISTFILES=		${VGABIOS}
SITES.${VGABIOS}=	http://savannah.gnu.org/download/vgabios/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.es40.org/
COMMENT=	AlphaServer ES40 emulator

CVS_REPOSITORIES=	es40
CVS_ROOT.es40=		:pserver:anonymous:@es40.cvs.sourceforge.net:/cvsroot/es40
WRKSRC=			${WRKDIR}/es40
.include "../../wip/mk/cvs-package.mk"

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_SCRIPT=	./configure_2.sh
USE_TOOLS=		gmake

# XXX why does the SDL test fail?
CFLAGS+=	-DHAVE_SDL -I${BUILDLINK_PREFIX.SDL}/include/SDL
LIBS+=		-lSDL
CONFIGURE_ENV+=	ac_cv_func__strdup=no
BUILD_ENV+=	es40_cfg_LDADD=Exception.o

# off_t is always 64 bits on NetBSD
CFLAGS.NetBSD+=		-Doff64_t=off_t -Dftello64=ftello -Dfseeko64=fseeko

INSTALLATION_DIRS=	share/es40 share/examples/es40

post-extract:
	cp ${DISTDIR}/${VGABIOS} ${WRKDIR}
	cp ${WRKSRC}/config/config.* ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${VGABIOS} \
	 ${DESTDIR}${PREFIX}/share/es40
	${INSTALL_DATA} ${WRKSRC}/src/es40.cfg \
	  ${DESTDIR}${PREFIX}/share/examples/es40
	${INSTALL_DATA} ${FILESDIR}/es40-netbsd.cfg \
	  ${DESTDIR}${PREFIX}/share/examples/es40

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
