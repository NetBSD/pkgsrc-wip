# $NetBSD: Makefile,v 1.3 2011/04/04 15:19:10 makoto Exp $

DISTNAME=	ghostscript-cidfonts-ryumin-${GS_VERSION}
# Please note  following is a must when building ghostscript
# for this package to work
#    PKGOPTION.ghostscipt+= disable-compile-inits
LICENSE=	# empty

CATEGORIES=	print
DISTFILES=	# empty

CONFLICTS+=	ghostscript-[0-7]*
CONFLICTS+=	ghostscript-8.[0-6]*
CONFLICTS+=	ghostscript-8.71
CONFLICTS+=	ghostscript-8.71nb[1-7]

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Enable Ryumin-Light and GothicBBB for ghostscript

.include	"../../wip/ghostscript/Makefile.common"
PKG_DESTDIR_SUPPORT=	user-destdir
GS_RESOURCEDIR=		share/ghostscript/${PKGVERSION}/Resource
WRKSRC=			${WRKDIR}/gcr
INSTALLATION_DIRS+=	${GS_RESOURCEDIR}/Font
INSTALLATION_DIRS+=	${GS_RESOURCEDIR}/Init

DEPENDS+=	ghostscript>=8.71.nb8:../../wip/ghostscript
BUILD_DEFS=	GS_CIDFMAP
# used in options.mk to switch adobe or ttf
SUBST_VARS=	GCR_INSTALL_TYPE

.include "options.mk"

.if !empty(GS_CIDFMAP)
SUBST_CLASSES+=		ttf_path
SUBST_STAGE.ttf_path=	post-build
SUBST_MESSAGES.ttf_path=Fixing ttf install directory in cidfmap
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

.include "../../wip/ghostscript/buildlink3.mk"
#.include "../../fonts/adobe-cidfonts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
