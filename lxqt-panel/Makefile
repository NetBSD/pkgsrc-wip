# $NetBSD: Makefile,v 1.6 2015/05/23 19:03:23 krytarowski Exp $

DISTNAME=	lxqt-panel-0.9.0
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Desktop panel
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

EGDIR=		${PREFIX}/share/examples/lxqt-panel

OWN_DIRS=	${PKG_SYSCONFDIR}/xdg/lxqt

CONF_FILES+=	${EGDIR}/xdg/lxqt/panel.conf ${PKG_SYSCONFDIR}/xdg/lxqt/panel.conf

# XXX: how to fix it properly?
post-install:
	${RUN} mkdir -p ${DESTDIR}${EGDIR}/xdg
	${RUN} mv ${DESTDIR}${PKG_SYSCONFDIR}/xdg/lxqt ${DESTDIR}${EGDIR}/xdg
	${RUN} rm -rf mv ${DESTDIR}${PKG_SYSCONFDIR}

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../wip/liblxqt-mount/buildlink3.mk"
.include "../../wip/lxqt-globalkeys/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/libsysstat/buildlink3.mk"
.include "../../wip/kguiaddons/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
