# $NetBSD: Makefile,v 1.4 2015/03/24 09:51:49 thomasklausner Exp $

DISTNAME=	npth-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/npth/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	ftp://ftp.gnupg.org/gcrypt/npth/
COMMENT=	New Portable Threads Library (nPth)
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

post-build:
	cd ${WRKSRC} && ${RM} npth-config && ${MAKE} npth-config

.include "../../mk/bsd.pkg.mk"
