# $NetBSD: Makefile,v 1.1 2015/06/07 14:49:04 ishit Exp $

DISTNAME=	libcue-1.4.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcue/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcue.sourceforge.net/
COMMENT=	Library to access a cue sheet data
LICENSE=	modified-bsd OR gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libcue.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
