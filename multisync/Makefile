# $NetBSD: Makefile,v 1.1 2005/01/05 10:23:23 mreriksson Exp $
#

PKGNAME=		multisync-0.82
COMMENT=		Modular program to synchronize PIM data

WRKSRC=			${WRKDIR}/multisync-0.82

pre-configure:
	cd ${WRKSRC} && \
		${ACLOCAL} && \
		${AUTOHEADER} && \
		${AUTOCONF} && \
		${AUTOMAKE} -acf

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../wip/multisync/Makefile.common"
