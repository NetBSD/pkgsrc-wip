# $NetBSD: Makefile,v 1.5 2012/10/21 15:19:44 noud4 Exp $
#

DISTNAME=		HTML-CalendarMonthSimple-1.25
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		ysbeer@af.org.za
HOMEPAGE=		http://search.cpan.org/dist/HTML-CalendarMonthSimple/
COMMENT=		Perl Module for Generating HTML Calendars

#DEPENDS+=

PLIST_SUBST+=		PERL5_SUB_INSTALLSITEARCHLIB=${PERL5_SUB_INSTALLARCHLIB:S|perl5/|perl5/vendor_perl/|}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
