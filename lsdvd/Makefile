# $NetBSD: Makefile,v 1.2 2004/02/06 23:00:12 thomasklausner Exp $
#

DISTNAME=	lsdvd-0.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acidrip/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://acidrip.thirtythreeandathird.net/lsdvd.html
COMMENT=	C application for reading the contents of a DVD

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

.include "../../multimedia/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
