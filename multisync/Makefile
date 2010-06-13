# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:11 thomasklausner Exp $
#

PKGNAME=		multisync-0.82
PKGREVISION=		3
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
