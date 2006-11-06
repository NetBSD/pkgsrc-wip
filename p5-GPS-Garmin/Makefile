# $NetBSD: Makefile,v 1.1.1.1 2006/11/06 20:32:19 uhabel Exp $

DISTNAME=	perl-GPS-0.15
PKGNAME=	p5-GPS-Garmin-0.15
CATEGORIES=	perl5 geography
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SREZIC/}
MAINTAINER=	uli@habel.name
HOMEPAGE=	http://search.cpan.org/dist/perl-GPS/
COMMENT=	GPS::Garmin access module for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/GPS/Garmin/.packlist

DEPENDS+= p5-Device-SerialPort>=0.12:../../comms/p5-Device-SerialPort

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
