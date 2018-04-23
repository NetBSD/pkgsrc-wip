# $NetBSD: Makefile,v 1.7 2012/11/13 22:50:39 othyro Exp $
#

PKGNAME=		multisync-0.82
PKGREVISION=		4
COMMENT=		Modular program to synchronize PIM data
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/multisync-0.82
USE_TOOLS+=		aclocal autoconf autoheader automake

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
