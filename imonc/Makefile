# $NetBSD: Makefile,v 1.10 2013/12/13 19:06:05 gschwarz Exp $

DISTNAME=	imonc-20010125
CATEGORIES=	net
MASTER_SITES=	http://download.fli4l.de/3.10.19/x86/
DISTFILES=	src.tar.gz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://www.fli4l.de/
COMMENT=	Command-line version of the fli4l monitoring tool
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/src/fli4l/base/imonc/
NO_CONFIGURE=	YES

LIBS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} imonc.c -o imonc \
		${LDFLAGS} ${BUILDLINK_LDADD.ncurses} ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imonc ${DESTDIR}${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
