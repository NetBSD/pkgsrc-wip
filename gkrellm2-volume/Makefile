# $NetBSD: Makefile,v 1.8 2004/02/18 08:52:07 cubidou Exp $

DISTNAME=	gkrellm-volume-2.1.9
WRKSRC=		${WRKDIR}/gkrellm-volume
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	Gkrellm2 volume mixer plugin

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES

MAKE_ENV+=	LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale \
		enable_nls=1

.include "../../wip/gkrellm2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
