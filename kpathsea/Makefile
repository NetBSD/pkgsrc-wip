# $NetBSD: Makefile,v 1.12 2009/07/21 18:53:13 minskim Exp $

DISTNAME=	kpathsea-5.0.0
CATEGORIES=	print

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/kpathsea/
COMMENT=	Path searching library for TeX-related files
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	teTeX-bin<=3.0nb21
CONFLICTS+=	teTeX-texmf<=3.0nb5

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/texlive/texk/kpathsea

MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q}

SUBST_CLASSES+=		texmfdir
SUBST_MESSAGE.texmfdir=	Setting texmf directories.
SUBST_STAGE.texmfdir=	pre-configure
SUBST_FILES.texmfdir=	texmf.cnf
SUBST_SED.texmfdir=	-e 's,@PREFIX@,${PREFIX},'
SUBST_SED.texmfdir+=	-e 's,@TEXMFLOCAL@,${TEXMFLOCAL},'
SUBST_SED.texmfdir+=	-e 's,@VARBASE@,${VARBASE},'
SUBST_SED.texmfdir+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'

PKG_SYSCONFSUBDIR=	texmf

BUILD_DEFS+=		VARBASE
TEXMFLOCAL=		${PREFIX}/share/texmf-local
FILES_SUBST+=		TEXMFLOCAL=${TEXMFLOCAL}

CONF_FILES=	${PREFIX}/share/texmf/web2c/texmf.cnf \
		${PKG_SYSCONFDIR}/texmf.cnf

OWN_DIRS+=		${TEXMFLOCAL} ${VARBASE}/lib/texmf
INSTALLATION_DIRS+=	share/texmf-dist

SVN_REPOSITORIES=	texlive
SVN_ROOT.texlive=	svn://tug.org/texlive/trunk/Build/source
SVN_DISTBASE.texlive=	texlive

.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
