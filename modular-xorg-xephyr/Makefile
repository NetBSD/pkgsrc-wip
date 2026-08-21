# $NetBSD: Makefile,v 1.32 2026/06/03 13:13:05 wiz Exp $

DISTNAME=	xorg-server-${XORG_VERSION}
PKGNAME=	modular-xorg-xephyr-${XORG_VERSION}

DISTINFO_FILE=		${.CURDIR}/../../wip/modular-xorg-server/distinfo
PATCHDIR=		${.CURDIR}/../../wip/modular-xorg-server/patches

MAINTAINER=	khorben@defora.org
COMMENT=	Xephyr server based on kdrive from modular X.org

BROKEN_ON_PLATFORM+=	Darwin-*-*

.include "../../wip/modular-xorg-server/Makefile.common"

MESON_ARGS+=		-Dxorg=false
MESON_ARGS+=		-Dxephyr=true
MESON_ARGS+=		-Dxnest=false
MESON_ARGS+=		-Dxvfb=false

post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/xorg/protocol.txt
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/Xserver.1
	if [ -f ${DESTDIR}${PREFIX}/share/doc/xorg-server/Xserver-DTrace.xml ]; then \
		${RM} ${DESTDIR}${PREFIX}/share/doc/xorg-server/Xserver-DTrace.xml; \
	fi

.include "../../wip/modular-xorg-server/options.mk"

.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
