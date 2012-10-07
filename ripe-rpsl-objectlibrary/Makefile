# $NetBSD: Makefile,v 1.5 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	RPSL-OL-3.1.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/ripe/dbase/software/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.ripe.net/
COMMENT=	RPSL Object Library

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_CONFIGURE_DIRS=	${WRKSRC}/perl
BUILD_DIRS=		${WRKSRC} ${WRKSRC}/perl

USE_LIBTOOL=		YES

BUILD_DEPENDS+=       p5-Net-Whois-RIPE-[0-9]*:../../wip/p5-Net-Whois-RIPE

post-configure: perl5-configure

.include "../../lang/perl5/module.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
