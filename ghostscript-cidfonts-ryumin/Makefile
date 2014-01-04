# $NetBSD: Makefile,v 1.11 2014/01/04 14:59:37 makoto Exp $

DISTNAME=	ghostscript-cidfonts-ryumin-${GS_VERSION}
DISTFILES=	# empty
PKGREVISION=	6
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enable Ryumin-Light and GothicBBB for ghostscript
LICENSE=	2-clause-bsd

# in PLIST, just use PKGVERSION for the same value
GS_RESOURCEDIR=		share/ghostscript/${GS_VERSION}/Resource
WRKSRC=			${WRKDIR}/gcr
INSTALLATION_DIRS+=	${GS_RESOURCEDIR}/Font
INSTALLATION_DIRS+=	${GS_RESOURCEDIR}/Init

DEPENDS+=	ghostscript>=9.05:../../print/ghostscript
DEPENDS+=	ghostscript-cidfonts>=20000901nb3:../../fonts/ghostscript-cidfonts
BUILD_DEFS+=	GS_CIDFMAP
# used in options.mk to switch adobe or ttf
SUBST_VARS=	GCR_INSTALL_TYPE
PLIST_SUBST=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

.include "options.mk"

.if !empty(GS_CIDFMAP)
SUBST_CLASSES+=		ttf_path
SUBST_STAGE.ttf_path=	post-build
SUBST_MESSAGE.ttf_path=Fixing ttf install directory in cidfmap
SUBST_FILES.ttf_path=	${GS_CIDFMAP}
SUBST_SED.ttf_path=	-e 's|%%PREFIX%%|${PREFIX}|'
.endif

# To edit %%PREFIX%% in cidfmap before installation by SUBST,
do-build:
.if !empty(GS_CIDFMAP)
	${MKDIR}		  ${WRKSRC}
	${CP} files/${GS_CIDFMAP} ${WRKSRC}
.endif

do-install:
.if !empty(GS_CIDFMAP)
	${INSTALL_DATA} ${WRKSRC}/${GS_CIDFMAP} ${DESTDIR}${PREFIX}/${GS_RESOURCEDIR}/Init/cidfmap
.endif
	# mainly Ryumin and GothicBBB
	${INSTALL_DATA} files/${GCR_INSTALL_TYPE}/[GR]*   ${DESTDIR}${PREFIX}/${GS_RESOURCEDIR}/Font

# no need to edit cidfmap
.if empty(GS_CIDFMAP)
NO_BUILD=	yes
.endif

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

PKG_OPTIONS.ghostscript-agpl+=	disable-compile-inits
PKG_OPTIONS.ghostscript-gpl+=	disable-compile-inits
.include "../../print/ghostscript/buildlink3.mk"

# Following logic is flakey, for looking at PKG_OPTIONS.gs_type now NOT at build time
.if   !empty(PKG_OPTIONS.gs_type:Mghostscript-gpl)
. include	"../../print/ghostscript-gpl/Makefile.common"
. if empty(PKG_BUILD_OPTIONS.ghostscript-gpl:Mdisable-compile-inits)
PKG_FAIL_REASON+=	'(gpl) You need to set PKG_OPTIONS.ghostscript+= disable-compile-inits, at its compile time.'
. endif
.else
. include	"../../print/ghostscript-agpl/Makefile.common"
. if empty(PKG_BUILD_OPTIONS.ghostscript-agpl:Mdisable-compile-inits)
PKG_FAIL_REASON+=	'(agpl) You need to set PKG_OPTIONS.ghostscript+= disable-compile-inits, at its compile time.'
. endif
.endif

.include "../../mk/bsd.pkg.mk"
