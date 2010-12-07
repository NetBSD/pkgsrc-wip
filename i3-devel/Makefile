# $NetBSD: Makefile,v 1.1.1.1 2010/12/07 21:21:16 pallegra Exp $
#

DISTNAME=	i3-tree-pr1
PKGNAME=	${DISTNAME:C/tree-pr/4devel/}
CATEGORIES=	wm
MASTER_SITES=	http://i3.zekjur.net/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://i3.zekjur.net/tree/
COMMENT=	Improved dynamic tiling window manager
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake bison lex yacc
USE_LANGUAGES=	c99
MAKE_JOBS_SAFE=	no

DEPENDS+=		dmenu-[0-9]*:../../x11/dmenu

PKG_SYSCONFSUBDIR=	i3
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/i3 share/xsessions include/i3
CONF_FILES=	${PREFIX}/share/doc/i3/config ${PKG_SYSCONFDIR}/config

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:C/\/i3//}
MAKE_ENV+=	DEBUG=0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/i3 ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/i3.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.for i in i3-input i3-msg
	${INSTALL_PROGRAM} ${WRKSRC}/${i}/${i} ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/${i}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
	${INSTALL_DATA} ${WRKSRC}/i3.config ${DESTDIR}${PREFIX}/share/doc/i3/config
	${INSTALL_DATA} ${WRKSRC}/i3.desktop ${DESTDIR}${PREFIX}/share/xsessions/
	${INSTALL_DATA} ${WRKSRC}/include/i3/ipc.h ${DESTDIR}${PREFIX}/include/i3/

.include "../../devel/libev/buildlink3.mk"
.include "../../wip/yajl/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
