# $NetBSD: Makefile,v 1.3 2007/09/21 13:06:54 thomasklausner Exp $
#

PKGNAME=		multisync-0.82
PKGREVISION=		1
COMMENT=		Modular program to synchronize PIM data

WRKSRC=			${WRKDIR}/multisync-0.82

pre-configure:
	cd ${WRKSRC} && \
		aclocal && \
		autoheader && \
		autoconf && \
		automake -acf

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../wip/multisync/Makefile.common"
