# $NetBSD: Makefile,v 1.8 2009/05/31 12:54:30 cheusov Exp $
#

DISTNAME=	mk-configure-0.10.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mk-configure/} \
		http://mova.org/~cheusov/pub/mk-configure/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://sourceforge.net/projects/mk-configure
COMMENT=	Lightweight but powerful replacement for GNU autotools

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# no languages
USE_BSD_MAKEFILE=	yes

DOC_FILES=		README NEWS ChangeLog TODO

MAKE_ENV+=		MKCATPAGES=no

AUTO_MKDIRS=		yes

PKGDOCDIR=		share/doc/mk-configure
EGDIR=			share/examples/mk-configure

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PREFIX}/${PKGDOCDIR}
.endfor
	cp -Rp ${WRKSRC}/examples ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
