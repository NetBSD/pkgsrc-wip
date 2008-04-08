# $NetBSD: Makefile,v 1.3 2008/04/08 20:19:55 gschwarz Exp $

DISTNAME=	imonc-20010125
CATEGORIES=	net
MASTER_SITES=	http://www.fli4l.de/fileadmin/downloadzaehler.php?file=3.2.0/
DISTFILES=	fli4l-3.2.0.tar.gz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.fli4l.de/
COMMENT=	Command-line version of the fli4l monitoring tool

WRKSRC=		${WRKDIR}/fli4l-3.2.0/unix
NO_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
LIBS+=		-lsocket -lnsl
.endif

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} imonc.c -o imonc \
		${LDFLAGS} ${BUILDLINK_LDADD.ncurses} ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imonc ${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
