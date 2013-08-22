# $NetBSD: Makefile,v 1.27 2013/08/22 08:50:06 obache Exp $
#

DISTNAME=	Panel-0.2.17
PKGNAME=	deforaos-panel-0.2.17
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4009/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop panel

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panel-embed.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panel-embed.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panel-message.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panel-message.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panel-notify.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panel-notify.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panel.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panelctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panelctl.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../wip/deforaos-browser/buildlink3.mk"
.include "../../wip/deforaos-keyboard/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
