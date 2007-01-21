# $NetBSD: Makefile,v 1.2 2007/01/21 09:36:40 gschwarz Exp $

DISTNAME=	imonc-20010125
CATEGORIES=	net
MASTER_SITES=	http://www.fli4l.de/fileadmin/downloadzaehler.php?file=3.0.2/
DISTFILES=	fli4l-3.0.2.tar.gz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.fli4l.de/
COMMENT=	Command-line version of the fli4l monitoring tool

WRKSRC=		${WRKDIR}/fli4l-3.0.2/unix
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
