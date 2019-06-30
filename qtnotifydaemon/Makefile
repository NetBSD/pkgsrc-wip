# $NetBSD: Makefile,v 1.4 2013/02/17 21:07:51 othyro Exp $
#

DISTNAME=	qtnotifydaemon_1.0.14.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qtnotifydaemon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drull.org.ru/qtnotifydaemon/
COMMENT=	Configurable and flexible Qt notification daemon
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		c++
MAKE_ENV+=		SUBLIBS="-Wl,-rpath,${LIBDIR} -L${QTDIR}/lib"
INSTALLATION_DIRS+=	bin share/dbus-1/services

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_FILES.prefix=	org.freedesktop.Notifications.service
SUBST_SED.prefix=	-e 's|/usr|${PREFIX}|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtnotifydaemon ${DESTDIR}${PREFIX}/bin/qtnotifydaemon
	${INSTALL_DATA} ${WRKSRC}/org.freedesktop.Notifications.service ${DESTDIR}${PREFIX}/share/dbus-1/services/org.freedesktop.Notifications.service

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
