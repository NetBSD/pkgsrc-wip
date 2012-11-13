# $NetBSD: Makefile,v 1.6 2012/11/13 20:09:35 othyro Exp $
#

PKGNAME=		multisync-0.82
PKGREVISION=		4
COMMENT=		Modular program to synchronize PIM data

WRKSRC=			${WRKDIR}/multisync-0.82

pre-configure:
	cd ${WRKSRC} && \
		aclocal && \
		autoheader && \
		autoconf && \
		automake -acf


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../wip/multisync/Makefile.common"
