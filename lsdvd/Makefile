# $NetBSD: Makefile,v 1.1.1.1 2003/10/07 18:09:05 xtraeme Exp $
#

DISTNAME=	lsdvd-0.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acidrip/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://acidrip.thirtythreeandathird.net/lsdvd.html
COMMENT=	C application for reading the contents of a DVD

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

.include "../../misc/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
