# $NetBSD$

DISTNAME=	xpopple-3.04.0
CATEGORIES=	print
GIT_REPO=	http://offog.org/git/xpopple.git
GIT_BRANCH=	master
GIT_REVISION=	0aa7a917fd5999521f8117fe3384dbcb3c8828ad

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://offog.org/code/xpopple/
COMMENT=	Display tool for PDF files (based on Motif and Poppler)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

CONFLICTS=	xpdf-[0-9]*
CONFLICTS+=	xpdf4-[0-9]*

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++20
FORCE_CXX_STD=		c++20

USE_TOOLS=		autoconf automake autoreconf pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		CXXFLAGS=${CXXFLAGS:M*:Q}
MAKE_ENV+=		SED=${SED:Q} ECHO=${ECHO:Q}

DEPENDS+=	urw-fonts-[0-9]*:../../fonts/urw-fonts

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	xpdf
EGDIR=			${PREFIX}/share/examples/xpdf
CONF_FILES=		${EGDIR}/xpdfrc ${PKG_SYSCONFDIR}/xpdfrc
INSTALLATION_DIRS=	${EGDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	doc/sample-xpdfrc doc/xpdf.1 doc/xpdfrc.5
SUBST_SED.paths=	-e "s,/usr/local,${PREFIX},g"
SUBST_SED.paths+=	-e "s,/usr/local/etc/xpdf,${PKG_SYSCONFDIR},g"
SUBST_SED.paths+=	-e "s, /etc/xpdf, ${PKG_SYSCONFDIR},g"

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/sample-xpdfrc \
		${DESTDIR}${EGDIR}/xpdfrc

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=24.03.0
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
