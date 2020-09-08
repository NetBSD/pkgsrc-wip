# $NetBSD: Makefile,v 1.3 2012/10/21 15:19:44 noud4 Exp $

DISTNAME=	Spread-3.17.3-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JE/JESUS/}

MAINTAINER=	gizm0@inbox.lv
COMMENT=	Perl5 module interface to Spread network utilities


PERL5_PACKLIST=		auto/Spread/.packlist

PLIST_SUBST+=		PERL5_SUB_INSTALLSITEARCHLIB=${PERL5_SUB_INSTALLARCHLIB:S|perl5/|perl5/vendor_perl/|}

.include "../../net/spread/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
