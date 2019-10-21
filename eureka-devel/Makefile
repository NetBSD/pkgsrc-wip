# $NetBSD$

GIT_REVISION=	5c0cd33bce0793dc4174cc8246210afdd5c78b00
PKGNAME=	eureka-devel-0
GIT_REPO=	https://git.code.sf.net/p/eureka-editor/git
#GIT_EXTRACTDIR=	eureka-124-source

#DISTNAME=	eureka-124-source
#PKGNAME=	${DISTNAME:S/eureka/eureka-devel/:S/-source//:S/-1/-1./}
CATEGORIES=	games
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eureka-editor/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/eureka-editor/
COMMENT=	Doom/Heretic/Hexen map editor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

#WRKSRC=		${WRKDIR}/eureka-1.24-source
WRKSRC=		${WRKDIR}/git

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=	share/doom

# Modify internal search path to check ${PREFIX}/share hierarchy first
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_MESSAGE.prefix=	Preparing main.cc file ...
SUBST_FILES.prefix=	src/main.cc
SUBST_SED.prefix=	-e 's,PKGSRC_PREFIX,${PREFIX},'

# Modify internal search path for DOOMWADDIR (if environment variable not set)
SUBST_CLASSES+=		dwd
SUBST_STAGE.dwd=	do-configure
SUBST_MESSAGE.dwd=	Preparing m_files.cc file ...
SUBST_FILES.dwd=	src/m_files.cc
SUBST_SED.dwd=		-e 's,PKGSRC_DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

.include "options.mk"

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
# FLTK must be compiled with OpenGL support
# FLTK version 1.4 is supported too
#.include "../../wip/fltk13/buildlink3.mk"
.include "../../wip/fltk14-devel/buildlink3.mk"
.if empty(PKG_OPTIONS.fltk14:Mopengl)
PKG_FAIL_REASON+=	"FLTK must be compiled with \"opengl\" option."
.endif
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
