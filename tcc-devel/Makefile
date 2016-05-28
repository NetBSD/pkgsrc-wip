# $NetBSD: Makefile,v 1.2 2012/10/07 17:17:25 asau Exp $
#

DISTNAME=	tcc-devel-${TCC_VER}
CATEGORIES=	lang

MAINTAINER=	rumcic@gmail.com
HOMEPAGE=	http://www.tinycc.org/
COMMENT=	The Smallest ANSI C compiler


USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes
NO_CHECKSUM=	yes
REPLACE_PERL+=	texi2pod.pl

.include "../../mk/bsd.prefs.mk"

TCC_VER!=	${DATE} +%Y%m%d

.if ${OPSYS} != "Linux"
SUBST_CLASSES+=		ldl
SUBST_FILES.ldl=	Makefile
SUBST_STAGE.ldl=	post-patch
SUBST_SED.ldl=		-e 's,LIBS=,\#LIBS,'
.endif

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

HG_REPOSITORIES=	tcc
HG_REPO.tcc=		http://landley.net/hg/tinycc

WRKSRC=		${WRKDIR}/tinycc

.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
