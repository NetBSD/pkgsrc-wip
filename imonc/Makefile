# $NetBSD: Makefile,v 1.6 2009/11/22 15:00:17 gschwarz Exp $

DISTNAME=	imonc-20010125
CATEGORIES=	net
MASTER_SITES=	http://www.fli4l.de/fileadmin/downloadzaehler.php?file=3.4.0/
DISTFILES=	fli4l-3.4.0.tar.gz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.fli4l.de/
COMMENT=	Command-line version of the fli4l monitoring tool

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/fli4l-3.4.0/unix
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
