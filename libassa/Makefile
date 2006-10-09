# $NetBSD: Makefile,v 1.5 2006/10/09 17:56:00 bartoszkuzma Exp $
#

DISTNAME=		libassa-3.4.2
CATEGORIES=		devel net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libassa/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://libassa.sourceforge.net/
COMMENT=		Networking library based on ACP

USE_LANGUAGES+=		c
USE_LANGUAGES+=		c++
USE_LANGUAGES+=		fortran
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	${WRKSRC}/assa-3.4.pc.in

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-doxygen=no
CONFIGURE_ARGS+=	--enable-dot=no
CONFIGURE_ARGS+=	--enable-html-docs=no
CONFIGURE_ARGS+=	--enable-latex-docs=no

.include "../../mk/bsd.pkg.mk"
