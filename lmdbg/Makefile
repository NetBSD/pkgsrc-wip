# $NetBSD: Makefile,v 1.6 2009/03/29 16:20:04 cheusov Exp $
#

DISTNAME=	lmdbg-0.10alpha1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/lmdbg/
COMMENT=	Lightweight Malloc Debugger

BUILD_DEPENDS+=	mk-configure-[0-9]*:../../wip/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes
INSTALL_DIRS=		scripts liblmdbg

TEST_TARGET=		test

DOCDIR=			share/doc/lmdbg

AUTO_MKDIRS=		yes

DOCFILES=		README NEWS ChangeLog

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
