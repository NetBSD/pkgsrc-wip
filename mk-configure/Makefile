# $NetBSD: Makefile,v 1.1.1.1 2009/03/08 17:33:35 cheusov Exp $
#

DISTNAME=	mk-configure-0.6.0
CATEGORIES=	devel
MASTER_SITES=	http://mova.org/~cheusov/pub/mk-configure/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://mova.org/~cheusov/pub/mk-configure/
COMMENT=	Lightweight replacement for GNU autoconf written in and for bmake

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# no languages
USE_BSD_MAKEFILE=	yes

DOC_FILES=		README NEWS ChangeLog TODO

MAKE_ENV+=		PREFIX=${PREFIX}
MAKE_ENV+=		MKCATPAGES=no
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

INSTALL_TARGET=		install-dirs install

PKGDOCDIR=		share/doc/mk-configure
INSTALLATION_DIRS+=	${PKGDOCDIR}

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PREFIX}/${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
