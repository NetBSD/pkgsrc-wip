# $NetBSD: Makefile,v 1.1.1.1 2004/02/22 14:12:35 cubidou Exp $

DISTNAME=		gkrellmwireless-2.0.3
PKGNAME=		${DISTNAME:S/gkrellm/gkrellm-/}
CATEGORIES=		net sysutils
MASTER_SITES=		http://gkrellm.luon.net/files/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://gkrellm.luon.net/gkrellmwireless.phtml
COMMENT=		Wavelan signal strength monitor for gkrellm

ONLY_FOR_PLATFORM=	*BSD-*-* Linux-*-*

WRKSRC=			${WRKDIR}/gkrellmwireless
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make

.include "../../wip/gkrellm2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
