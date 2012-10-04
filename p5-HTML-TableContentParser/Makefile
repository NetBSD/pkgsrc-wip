# $NetBSD: Makefile,v 1.3 2012/10/04 10:45:28 asau Exp $
#

DISTNAME=		HTML-TableContentParser-0.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SD/SDRABBLE/}

MAINTAINER=		bartosz.kuzma@gmail.com
COMMENT=		Do interesting things with the contents of tables

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=		auto/HTML/TableContentParser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
