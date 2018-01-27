# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:52 othyro Exp $
#

DISTNAME=	unpaper-6.1
CATEGORIES=	textproc
MASTER_SITES=	https://www.flameeyes.eu/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.flameeyes.eu/projects/unpaper
COMMENT=	Post-processing scanned and photocopied book pages
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
