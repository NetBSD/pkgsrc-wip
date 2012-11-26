# $NetBSD: Makefile,v 1.1 2012/11/26 14:47:51 othyro Exp $
#

DISTNAME=	CrabEmu-0.1.9
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crabemu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://crabemu.sourceforge.net/
COMMENT=	Primarily a Sega Master System emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
QMAKE=			${QTDIR}/bin/qmake
INSTALLATION_DIRS+=	bin
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s|/usr/bin/|${PREFIX}/bin/|g"

pre-configure:
		cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE}

.include "../../audio/openal/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
