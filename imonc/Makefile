# $NetBSD: Makefile,v 1.5 2009/04/19 21:30:27 gschwarz Exp $

DISTNAME=	imonc-20010125
CATEGORIES=	net
MASTER_SITES=	http://www.fli4l.de/fileadmin/downloadzaehler.php?file=3.2.3/
DISTFILES=	fli4l-3.2.3_a.tar.gz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.fli4l.de/
COMMENT=	Command-line version of the fli4l monitoring tool

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/fli4l-3.2.3/unix
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
	${INSTALL_PROGRAM} ${WRKSRC}/imonc ${DESTDIR}${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
