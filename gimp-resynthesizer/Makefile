# $NetBSD: Makefile,v 1.1.1.1 2010/04/20 04:28:20 othyro Exp $
#

DISTNAME=	resynthesizer-0.16
PKGNAME=	gimp-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://www.logarithmic.net/pfh-files/resynthesizer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logarithmic.net/pfh-files/resynthesizer
COMMENT=	Resynthesizer is a Gimp plug-in for texture synthesis
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++

INSTALLATION_DIRS+=	lib/gimp/2.0/plug-ins share/gimp/2.0/scripts

SUBST_CLASSES+=		gimptool
SUBST_STAGE.gimptool=	pre-install
SUBST_FILES.gimptool=	Makefile
SUBST_SED.gimptool=	-e "s,install-,install-admin-,g"
SUBST_MESSAGE.gimptool=	Fixing harcoded gimptool arguments

do-install:
	# This is stage is manual in this Makefile,
	# because gimptool is installing the scripts in the wrong place
	gimptool-2.0 --install-admin-bin ${WRKSRC}/resynth
	${INSTALL_SCRIPT} ${WRKSRC}/smart-enlarge.scm ${DESTDIR}${PREFIX}/share/gimp/2.0/scripts/
	${INSTALL_SCRIPT} ${WRKSRC}/smart-remove.scm ${DESTDIR}${PREFIX}/share/gimp/2.0/scripts/

.include "../../graphics/gimp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
