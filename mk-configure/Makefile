# $NetBSD: Makefile,v 1.5 2009/03/29 16:08:00 cheusov Exp $
#

DISTNAME=	mk-configure-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mk-configure/} \
		http://mova.org/~cheusov/pub/mk-configure/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://sourceforge.net/projects/mk-configure
COMMENT=	Lightweight and powerful replacement for GNU autotools

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# no languages
USE_BSD_MAKEFILE=	yes

DOC_FILES=		README NEWS ChangeLog TODO

MAKE_ENV+=		MKCATPAGES=no

INSTALL_TARGET=		install-dirs install

PKGDOCDIR=		share/doc/mk-configure
INSTALLATION_DIRS+=	${PKGDOCDIR}

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PREFIX}/${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
