# $NetBSD: Makefile,v 1.4 2012/10/04 10:45:28 asau Exp $
#

DISTNAME=		HTML-CalendarMonthSimple-1.25
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		ysbeer@af.org.za
HOMEPAGE=		http://search.cpan.org/dist/HTML-CalendarMonthSimple/
COMMENT=		Perl Module for Generating HTML Calendars

#DEPENDS+=

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES= overwrite pkgviews

PERL5_PACKLIST=		auto/HTML/CalendarMonthSimple/.packlist


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
