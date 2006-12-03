# $NetBSD: Makefile,v 1.1.1.1 2006/12/03 15:27:25 gschwarz Exp $

DISTNAME=	imonc-20010125
CATEGORIES=	net
MASTER_SITES=	http://www.fli4l.de/fileadmin/downloadzaehler.php?file=3.0.1/
DISTFILES=	fli4l-3.0.1.tar.gz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.fli4l.de/
COMMENT=	Command-line version of the fli4l monitoring tool

WRKSRC=		${WRKDIR}/fli4l-3.0.1/unix
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} imonc.c -o imonc \
		-lncurses ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imonc ${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
