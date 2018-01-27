# $NetBSD: Makefile,v 1.6 2012/09/24 16:56:38 asau Exp $

DISTNAME=	ar7-0.1
CATEGORIES=	net
MASTER_SITES=	http://home.arcor.de/volpol/ar7/ \
		ftp://ftp.backschues.net/pub/driver/sphairon_ar860/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Diagnosis tool for certain ADSL modems
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	bin

USE_FEATURES+=	getopt_long
LIBS.SunOS+=	-lnsl -lsocket

.include "../../mk/bsd.pkg.mk"
