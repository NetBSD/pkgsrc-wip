# $NetBSD: Makefile,v 1.1 2007/01/06 11:22:48 cheusov Exp $

DISTNAME=		GTop-0.16
PKGNAME=		p5-GTop-0.16
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=GTop/}

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://search.cpan.org/dist/GTop/
COMMENT=		Perl interface to libgtop

#DEPENDS+=		libgtop2-[0-9]*:../../sysutils/libgtop2
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/GTop/.packlist

.include "../../sysutils/libgtop2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
