# $NetBSD: Makefile,v 1.1.1.1 2010/11/06 17:08:02 rhaamo Exp $
#

DISTNAME=	gmrun-0.9.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gmrun/}

MAINTAINER=	rhaamo@gruik.at
HOMEPAGE=	http://dynarch.com/mishoo/gmrun.epl
COMMENT=	Customizable program to run programs, with tab-completion
LICENSE=	gnu-gpl-v2

DOCDIR=		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${PKGMANDIR}/man1/
INSTALLATION_DIRS+=	share/doc/gmrun/
INSTALLATION_DIRS+=	share/examples/gmrun/

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib"
CONFIGURE_ARGS=	--disable-stlport

DOCS=		README

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	config/Makefile.in config/Makefile.am
SUBST_SED.path=		-e "s|@PACKAGE_DATA_DIR@|${PREFIX}/share/examples/${PKGBASE}|"

post-install:
	${INSTALL_MAN} files/gmrun.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${MKDIR} ${DOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}/
.endfor

.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
