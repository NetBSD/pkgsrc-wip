# $NetBSD: Makefile,v 1.3 2004/03/29 02:57:01 blef Exp $

DISTNAME=	lsdvd-0.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acidrip/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://acidrip.thirtythreeandathird.net/lsdvd.html
COMMENT=	C application for reading the contents of a DVD

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
