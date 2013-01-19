# $NetBSD: Makefile,v 1.4 2013/01/19 12:32:04 othyro Exp $
#

DISTNAME=	unagi-0.3.3
PKGREVISION=	3
CATEGORIES=	wm
MASTER_SITES=	https://projects.mini-dweeb.org/attachments/download/111/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projects.mini-dweeb.org/projects/unagi
COMMENT=	Modular compositing manager
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl pkg-config

PKGCONFIG_OVERRIDE+=	unagi.pc.in
EGDIR=			share/examples/xdg
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/xdg ${EGDIR}
CONF_FILES+=		${EGDIR}/unagi.conf ${PKG_SYSCONFDIR}/xdg/unagi.conf

.include "options.mk"

.if $(OPSYS) != "Linux"
BUILDLINK_TRANSFORM=	rm:-ldl
.endif

post-install:
		cd ${WRKSRC} && \
			${INSTALL_DATA} unagi.conf \
				${DESTDIR}${PREFIX}/${EGDIR}/unagi.conf
		${RM} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/unagi.conf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xcb-util036/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.8
.include "../../x11/libxcb/buildlink3.mk"
BUILDLINK_DEPMETHOD.xcb-proto=	build
.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
