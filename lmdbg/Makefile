# $NetBSD: Makefile,v 1.5 2009/03/08 11:32:19 cheusov Exp $
#

DISTNAME=	lmdbg-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/lmdbg/
COMMENT=	Lightweight Malloc Debugger

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

TEST_TARGET=		test

DOCDIR=			share/doc/lmdbg
INSTALLATION_DIRS+=	${DOCDIR}

DOCFILES=		README NEWS ChangeLog

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
