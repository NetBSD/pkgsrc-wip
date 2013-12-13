# $NetBSD: Makefile,v 1.10 2013/12/13 19:06:05 gschwarz Exp $

DISTNAME=	imonc-20010125
CATEGORIES=	net
MASTER_SITES=	http://www.fli4l.de/fileadmin/downloadzaehler.php?file=3.6.2/
DISTFILES=	fli4l-3.6.2.tar.gz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.fli4l.de/
COMMENT=	Command-line version of the fli4l monitoring tool
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/fli4l-3.6.2/unix
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
