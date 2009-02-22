# $NetBSD: Makefile,v 1.2 2009/02/22 21:45:22 cheusov Exp $
#

DISTNAME=	lmdbg-0.8.0
CATEGORIES=	devel
MASTER_SITES=	http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/lmdbg/
COMMENT=	Lightweight Malloc Debugger

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

DOCDIR=			share/doc/lmdbg
INSTALLATION_DIRS+=	${DOCDIR}

DOCFILES=		README NEWS ChangeLog

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
