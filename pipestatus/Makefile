# $NetBSD: Makefile,v 1.1 2008/01/24 22:15:11 cheusov Exp $
#

DISTNAME=	pipestatus-0.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pipestatus/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/pipestatus/
COMMENT=	UNIX/POSIX shell helper for running pipes safely

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	bin share/doc/pipestatus
DOCS=			README NEWS

do-install:
	${INSTALL_DATA} ${WRKSRC}/pipestatus ${DESTDIR}${PREFIX}/bin/
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/pipestatus/
.endfor

.include "../../mk/bsd.pkg.mk"
